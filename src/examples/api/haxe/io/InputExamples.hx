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
        trace(Type.getClassName(Type.getClass(read)));

        read = input.read(4);
        trace(read);

        /* Try reading more bytes than are left */
        try{
            read = input.read(1000);
            trace(read);
        }
        catch (e:haxe.io.Eof){
            trace("We get here " + e);
        }
    }

    public function readAllExample(){
        var input = new haxe.io.StringInput("testString"); 
        var read = input.readAll(14);
        trace(read);
        trace(Type.getClassName(Type.getClass(read)));

    }
}
