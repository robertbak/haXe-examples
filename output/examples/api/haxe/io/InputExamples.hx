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

        read = input.read(4);
        trace(read);
        // Stri

        /* Try reading more bytes than are left */
        try{
            read = input.read(1000);
            trace(read);
        }
        catch (e:haxe.io.Eof){
            trace("We get here " + e);
            // We get here Eof
        }
    }

    public function readAllExample(){
        var input = new haxe.io.StringInput("testString"); 
        var read = input.readAll(14);
        trace(read);
        // testString
        trace(Type.getClassName(Type.getClass(read)));
        // haxe.io.Bytes

    }
}
