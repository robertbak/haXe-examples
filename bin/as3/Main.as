package  {
	import examples.templates.Templates;
	import haxe.Log;
	public class Main {
		public function Main() : void {
		}
		
		static public function show_templates() : void {
			var templates : examples.templates.Templates = new examples.templates.Templates();
			templates.example_variables();
			templates.example_fields();
			templates.example_if();
			templates.example_for();
		}
		
		static public function main() : void {
			haxe.Log.trace("Heldsssa  Frodsae 2!",{ fileName : "Main.hx", lineNumber : 19, className : "Main", methodName : "main"});
			Main.show_templates();
		}
		
	}
}
