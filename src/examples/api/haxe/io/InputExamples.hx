package examples.api.haxe.io;


// Input is an abstract class so we need to 
// use and implementation in the examples
class InputExamples {
	public function new(){
	}

    public function readExample(){
       var input = new haxe.io.StringInput("testString"); 
       var read = input.read(2);
       trace(read);
       trace(Type.getClassName(Type.getClass(read)));
       
    }
}
