package examples.templates {
	import examples.templates.User;
	import haxe.Template;
	import haxe.Log;
	public class Templates {
		public function Templates() : void {
		}
		
		public function example_variables() : String {
			var templateDefinition : String = "This is a simple template called ::name::";
			var template : haxe.Template = new haxe.Template(templateDefinition);
			var result : String = template.execute({ name : "simple name"});
			haxe.Log.trace(result,{ fileName : "Templates.hx", lineNumber : 23, className : "examples.templates.Templates", methodName : "example_variables"});
			return result;
		}
		
		public function example_fields() : String {
			var templateDefinition : String = "This shows the use of subfields ::user.firstName:: ::user.lastName::";
			var user : examples.templates.User = new examples.templates.User("Bob","Hope",43);
			var template : haxe.Template = new haxe.Template(templateDefinition);
			var result : String = template.execute({ user : user});
			haxe.Log.trace(result,{ fileName : "Templates.hx", lineNumber : 34, className : "examples.templates.Templates", methodName : "example_fields"});
			return result;
		}
		
		public function example_if() : String {
			var templateDefinition : String = "This shows the use of if -::if (user.age > 18):: Legal ::else:: Illegal ::end::";
			var user : examples.templates.User = new examples.templates.User("Bob","Hope",42);
			var template : haxe.Template = new haxe.Template(templateDefinition);
			var result : String = template.execute({ user : user});
			haxe.Log.trace(result,{ fileName : "Templates.hx", lineNumber : 45, className : "examples.templates.Templates", methodName : "example_if"});
			return result;
		}
		
		public function example_for() : String {
			var templateDefinition : String = "This shows the use of for - ::foreach users:: ::firstName:: ::lastName:: age: (::age::)::end::";
			var list : List = new List();
			list.add(new examples.templates.User("Bob","Hope",43));
			list.add(new examples.templates.User("Tom","Tam",18));
			list.add(new examples.templates.User("Blip","Blop",12));
			var template : haxe.Template = new haxe.Template(templateDefinition);
			var result : String = template.execute({ users : list});
			haxe.Log.trace(result,{ fileName : "Templates.hx", lineNumber : 58, className : "examples.templates.Templates", methodName : "example_for"});
			return result;
		}
		
		public function example_makro() : String {
			var templateDefinition : String = "This shows the use of makros - $$makro(::user.age::)";
			var user : examples.templates.User = new examples.templates.User("Bob","Hope",43);
			var template : haxe.Template = new haxe.Template(templateDefinition);
			var result : String = template.execute({ user : user},{ makro : this.makroFunction});
			haxe.Log.trace(result,{ fileName : "Templates.hx", lineNumber : 69, className : "examples.templates.Templates", methodName : "example_makro"});
			return result;
		}
		
		public function makroFunction(resolve : Function,age : int) : String {
			resolve("user");
			return "Test";
		}
		
		public function example_globals() : String {
			haxe.Template.globals.copyright = "Copyrighted by XX";
			var templateDefinition : String = "This shows the use of globals - ::copyright::";
			var template : haxe.Template = new haxe.Template(templateDefinition);
			var result : String = template.execute({ });
			haxe.Log.trace(result,{ fileName : "Templates.hx", lineNumber : 89, className : "examples.templates.Templates", methodName : "example_globals"});
			return result;
		}
		
	}
}
