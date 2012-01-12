package haxe._Template {
	public class TemplateExpr extends enum {
		public static const __isenum : Boolean = true;
		public function TemplateExpr( t : String, index : int, p : Array = null ) : void { this.tag = t; this.index = index; this.params = p; }
		public static function OpBlock(l : List) : TemplateExpr { return new TemplateExpr("OpBlock",4,[l]); }
		public static function OpExpr(expr : Function) : TemplateExpr { return new TemplateExpr("OpExpr",1,[expr]); }
		public static function OpForeach(expr : Function, loop : haxe._Template.TemplateExpr) : TemplateExpr { return new TemplateExpr("OpForeach",5,[expr,loop]); }
		public static function OpIf(expr : Function, eif : haxe._Template.TemplateExpr, eelse : haxe._Template.TemplateExpr) : TemplateExpr { return new TemplateExpr("OpIf",2,[expr,eif,eelse]); }
		public static function OpMacro(name : String, params : List) : TemplateExpr { return new TemplateExpr("OpMacro",6,[name,params]); }
		public static function OpStr(str : String) : TemplateExpr { return new TemplateExpr("OpStr",3,[str]); }
		public static function OpVar(v : String) : TemplateExpr { return new TemplateExpr("OpVar",0,[v]); }
		public static var __constructs__ : Array = ["OpVar","OpExpr","OpIf","OpStr","OpBlock","OpForeach","OpMacro"];;
	}
}
