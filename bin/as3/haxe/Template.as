package haxe {
	import haxe._Template.TemplateExpr;
	import flash.Boot;
	public class Template {
		public function Template(str : String = null) : void { if( !flash.Boot.skip_constructor ) {
			var tokens : List = this.parseTokens(str);
			this.expr = this.parseBlock(tokens);
			if(!tokens.isEmpty()) throw "Unexpected '" + tokens.first().s + "'";
		}}
		
		protected var expr : haxe._Template.TemplateExpr;
		protected var context : *;
		protected var macros : *;
		protected var stack : List;
		protected var buf : StringBuf;
		public function execute(context : *,macros : * = null) : String {
			this.macros = ((macros == null)?{ }:macros);
			this.context = context;
			this.stack = new List();
			this.buf = new StringBuf();
			this.run(this.expr);
			return this.buf.toString();
		}
		
		public function resolve(v : String) : * {
			if(Reflect.hasField(this.context,v)) return Reflect.field(this.context,v);
			{ var $it : * = this.stack.iterator();
			while( $it.hasNext() ) { var ctx : * = $it.next();
			if(Reflect.hasField(ctx,v)) return Reflect.field(ctx,v);
			}}
			if(v == "__current__") return this.context;
			return Reflect.field(haxe.Template.globals,v);
		}
		
		protected function parseTokens(data : String) : List {
			var tokens : List = new List();
			while(haxe.Template.splitter.match(data)) {
				var p : * = haxe.Template.splitter.matchedPos();
				if(p.pos > 0) tokens.add({ p : data.substr(0,p.pos), s : true, l : null});
				if(data["charCodeAt"](p.pos) == 58) {
					tokens.add({ p : data.substr(p.pos + 2,p.len - 4), s : false, l : null});
					data = haxe.Template.splitter.matchedRight();
					continue;
				}
				var parp : int = p.pos + p.len;
				var npar : int = 1;
				while(npar > 0) {
					var c : * = data["charCodeAt"](parp);
					if(c == 40) npar++;
					else if(c == 41) npar--;
					else if(c == null) throw "Unclosed macro parenthesis";
					parp++;
				}
				var params : Array = data.substr(p.pos + p.len,parp - (p.pos + p.len) - 1).split(",");
				tokens.add({ p : haxe.Template.splitter.matched(2), s : false, l : params});
				data = data.substr(parp,data.length - parp);
			}
			if(data.length > 0) tokens.add({ p : data, s : true, l : null});
			return tokens;
		}
		
		protected function parseBlock(tokens : List) : haxe._Template.TemplateExpr {
			var l : List = new List();
			while(true) {
				var t : * = tokens.first();
				if(t == null) break;
				if(!t.s && (t.p == "end" || t.p == "else" || t.p.substr(0,7) == "elseif ")) break;
				l.add(this.parse(tokens));
			}
			if(l.length == 1) return l.first();
			return haxe._Template.TemplateExpr.OpBlock(l);
		}
		
		protected function parse(tokens : List) : haxe._Template.TemplateExpr {
			var t : * = tokens.pop();
			var p : String = t.p;
			if(t.s) return haxe._Template.TemplateExpr.OpStr(p);
			if(t.l != null) {
				var pe : List = new List();
				{
					var _g : int = 0, _g1 : Array = t.l;
					while(_g < _g1.length) {
						var p1 : String = _g1[_g];
						++_g;
						pe.add(this.parseBlock(this.parseTokens(p1)));
					}
				}
				return haxe._Template.TemplateExpr.OpMacro(p,pe);
			}
			if(p.substr(0,3) == "if ") {
				p = p.substr(3,p.length - 3);
				var e : Function = this.parseExpr(p);
				var eif : haxe._Template.TemplateExpr = this.parseBlock(tokens);
				var t1 : * = tokens.first();
				var eelse : haxe._Template.TemplateExpr;
				if(t1 == null) throw "Unclosed 'if'";
				if(t1.p == "end") {
					tokens.pop();
					eelse = null;
				}
				else if(t1.p == "else") {
					tokens.pop();
					eelse = this.parseBlock(tokens);
					t1 = tokens.pop();
					if(t1 == null || t1.p != "end") throw "Unclosed 'else'";
				}
				else {
					t1.p = t1.p.substr(4,t1.p.length - 4);
					eelse = this.parse(tokens);
				}
				return haxe._Template.TemplateExpr.OpIf(e,eif,eelse);
			}
			if(p.substr(0,8) == "foreach ") {
				p = p.substr(8,p.length - 8);
				var e1 : Function = this.parseExpr(p);
				var efor : haxe._Template.TemplateExpr = this.parseBlock(tokens);
				var t2 : * = tokens.pop();
				if(t2 == null || t2.p != "end") throw "Unclosed 'foreach'";
				return haxe._Template.TemplateExpr.OpForeach(e1,efor);
			}
			if(haxe.Template.expr_splitter.match(p)) return haxe._Template.TemplateExpr.OpExpr(this.parseExpr(p));
			return haxe._Template.TemplateExpr.OpVar(p);
		}
		
		protected function parseExpr(data : String) : Function {
			var l : List = new List();
			var expr : String = data;
			while(haxe.Template.expr_splitter.match(data)) {
				var p : * = haxe.Template.expr_splitter.matchedPos();
				var k : int = p.pos + p.len;
				if(p.pos != 0) l.add({ p : data.substr(0,p.pos), s : true});
				var p1 : String = haxe.Template.expr_splitter.matched(0);
				l.add({ p : p1, s : p1.indexOf("\"") >= 0});
				data = haxe.Template.expr_splitter.matchedRight();
			}
			if(data.length != 0) l.add({ p : data, s : true});
			var e : Function;
			try {
				e = this.makeExpr(l);
				if(!l.isEmpty()) throw l.first().p;
			}
			catch( s : String ){
				throw "Unexpected '" + s + "' in " + expr;
			}
			return function() : * {
				try {
					return e();
				}
				catch( exc : * ){
					throw "Error : " + Std.string(exc) + " in " + expr;
				}
			}
		}
		
		protected function makeConst(v : String) : Function {
			haxe.Template.expr_trim.match(v);
			v = haxe.Template.expr_trim.matched(1);
			if(v["charCodeAt"](0) == 34) {
				var str : String = v.substr(1,v.length - 2);
				return function() : String {
					return str;
				}
			}
			if(haxe.Template.expr_int.match(v)) {
				var i : * = Std._parseInt(v);
				return function() : * {
					return i;
				}
			}
			if(haxe.Template.expr_float.match(v)) {
				var f : Number = Std._parseFloat(v);
				return function() : Number {
					return f;
				}
			}
			var me : haxe.Template = this;
			return function() : * {
				return me.resolve(v);
			}
		}
		
		protected function makePath(e : Function,l : List) : Function {
			var p : * = l.first();
			if(p == null || p.p != ".") return e;
			l.pop();
			var field : * = l.pop();
			if(field == null || !field.s) throw field.p;
			var f : String = field.p;
			haxe.Template.expr_trim.match(f);
			f = haxe.Template.expr_trim.matched(1);
			return this.makePath(function() : * {
				return Reflect.field(e(),f);
			},l);
		}
		
		protected function makeExpr(l : List) : Function {
			return this.makePath(this.makeExpr2(l),l);
		}
		
		protected function makeExpr2(l : List) : Function {
			var p : * = l.pop();
			if(p == null) throw "<eof>";
			if(p.s) return this.makeConst(p.p);
			switch(p.p) {
			case "(":
			{
				var e1 : Function = this.makeExpr(l);
				var p1 : * = l.pop();
				if(p1 == null || p1.s) throw p1.p;
				if(p1.p == ")") return e1;
				var e2 : Function = this.makeExpr(l);
				var p2 : * = l.pop();
				if(p2 == null || p2.p != ")") throw p2.p;
				return (function($this:Template) : Function {
					var $r : Function;
					switch(p1.p) {
					case "+":
					$r = function() : * {
						return e1() + e2();
					}
					break;
					case "-":
					$r = function() : * {
						return e1() - e2();
					}
					break;
					case "*":
					$r = function() : * {
						return e1() * e2();
					}
					break;
					case "/":
					$r = function() : * {
						return e1() / e2();
					}
					break;
					case ">":
					$r = function() : * {
						return e1() > e2();
					}
					break;
					case "<":
					$r = function() : * {
						return e1() < e2();
					}
					break;
					case ">=":
					$r = function() : * {
						return e1() >= e2();
					}
					break;
					case "<=":
					$r = function() : * {
						return e1() <= e2();
					}
					break;
					case "==":
					$r = function() : * {
						return e1() == e2();
					}
					break;
					case "!=":
					$r = function() : * {
						return e1() != e2();
					}
					break;
					case "&&":
					$r = function() : * {
						return e1() && e2();
					}
					break;
					case "||":
					$r = function() : * {
						return e1() || e2();
					}
					break;
					default:
					$r = (function($this:Template) : Function {
						var $r2 : Function;
						throw "Unknown operation " + p1.p;
						return $r2;
					}($this));
					break;
					}
					return $r;
				}(this));
			}
			break;
			case "!":
			{
				var e : Function = this.makeExpr(l);
				return function() : Boolean {
					var v : * = e();
					return v == null || v == false;
				}
			}
			break;
			case "-":
			{
				var e3 : Function = this.makeExpr(l);
				return function() : Number {
					return -e3();
				}
			}
			break;
			}
			throw p.p;
		}
		
		protected function run(e : haxe._Template.TemplateExpr) : void {
			{
				var $e : enum = (e);
				switch( $e.index ) {
				case 0:
				var v : String = $e.params[0];
				this.buf.add(Std.string(this.resolve(v)));
				break;
				case 1:
				var e1 : Function = $e.params[0];
				this.buf.add(Std.string(e1()));
				break;
				case 2:
				var eelse : haxe._Template.TemplateExpr = $e.params[2], eif : haxe._Template.TemplateExpr = $e.params[1], e2 : Function = $e.params[0];
				{
					var v1 : * = e2();
					if(v1 == null || v1 == false) {
						if(eelse != null) this.run(eelse);
					}
					else this.run(eif);
				}
				break;
				case 3:
				var str : String = $e.params[0];
				this.buf.add(str);
				break;
				case 4:
				var l : List = $e.params[0];
				{
					{ var $it2 : * = l.iterator();
					while( $it2.hasNext() ) { var e3 : haxe._Template.TemplateExpr = $it2.next();
					this.run(e3);
					}}
				}
				break;
				case 5:
				var loop : haxe._Template.TemplateExpr = $e.params[1], e4 : Function = $e.params[0];
				{
					var v2 : * = e4();
					try {
						if(v2.hasNext == null) {
							var x : * = v2.iterator();
							if(x.hasNext == null) throw null;
							v2 = x;
						}
					}
					catch( e5 : * ){
						throw "Cannot iter on " + v2;
					}
					this.stack.push(this.context);
					var v3 : * = v2;
					{ var $it3 : * = v3;
					while( $it3.hasNext() ) { var ctx : * = $it3.next();
					{
						this.context = ctx;
						this.run(loop);
					}
					}}
					this.context = this.stack.pop();
				}
				break;
				case 6:
				var params : List = $e.params[1], m : String = $e.params[0];
				{
					var v4 : * = Reflect.field(this.macros,m);
					var pl : Array = new Array();
					var old : StringBuf = this.buf;
					pl.push(this.resolve);
					{ var $it4 : * = params.iterator();
					while( $it4.hasNext() ) { var p : haxe._Template.TemplateExpr = $it4.next();
					{
						{
							var $e5 : enum = (p);
							switch( $e5.index ) {
							case 0:
							var v5 : String = $e5.params[0];
							pl.push(this.resolve(v5));
							break;
							default:
							{
								this.buf = new StringBuf();
								this.run(p);
								pl.push(this.buf.toString());
							}
							break;
							}
						}
					}
					}}
					this.buf = old;
					try {
						this.buf.add(Std.string(Reflect.callMethod(this.macros,v4,pl)));
					}
					catch( e6 : * ){
						var plstr : String = (function($this:Template) : String {
							var $r6 : String;
							try {
								$r6 = pl.join(",");
							}
							catch( e7 : * ){
								$r6 = "???";
							}
							return $r6;
						}(this));
						var msg : String = "Macro call " + m + "(" + plstr + ") failed (" + Std.string(e6) + ")";
						throw msg;
					}
				}
				break;
				}
			}
		}
		
		static protected var splitter : EReg = new EReg("(::[A-Za-z0-9_ ()&|!+=/><*.\"-]+::|\\$\\$([A-Za-z0-9_-]+)\\()","");
		static protected var expr_splitter : EReg = new EReg("(\\(|\\)|[ \r\n\t]*\"[^\"]*\"[ \r\n\t]*|[!+=/><*.&|-]+)","");
		static protected var expr_trim : EReg = new EReg("^[ ]*([^ ]+)[ ]*$","");
		static protected var expr_int : EReg = new EReg("^[0-9]+$","");
		static protected var expr_float : EReg = new EReg("^([+-]?)(?=\\d|,\\d)\\d*(,\\d*)?([Ee]([+-]?\\d+))?$","");
		static public var globals : * = { }
	}
}
