package examples.api.haxe.io;


// Input is an abstract class so we need to 
// use an implementation in the examples
class InputExamples {
	public function new(){
	}

    public function readExample(){
       var input = new haxe.io.StringInput("testString"); 
       var read = input.read(4);
       trace(read);
       // test
       trace(Type.getClassName(Type.getClass(read)));
       // haxe.io.Bytes
    }
}
