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
            trace("We get here - " + e);
        }
    }

    public function readAllExample(){
        var input = new haxe.io.StringInput("testString"); 
        var read = input.readAll();
        trace(read);
        trace(Type.getClassName(Type.getClass(read)));
    }

    public function readLineExample(){
        var input = new haxe.io.StringInput("first line \n second line"); 
        var read = input.readLine();
        trace(read);
        trace(Type.getClassName(Type.getClass(read)));
    }

    public function readByteExample(){
        var input = new haxe.io.StringInput("some text"); 
        var read = input.readByte();
        trace(read);
        trace(Type.typeof(read));
        trace(String.fromCharCode(read));
    }

    public function readBytesExample(){
        var input = new haxe.io.StringInput("some text"); 
        // Allocate 4 bytes 
        var read = haxe.io.Bytes.alloc(4);
        // Read 1 byte and put it in read starting from index 0
        input.readBytes(read,0,1);
        trace(read);

        // Read 2 bytes and put it in read starting from index 2
        input.readBytes(read,2,2);
        trace(read);

        // Try putting data that will not fit
        try{
            input.readBytes(read,2,3);
        }
        catch (e:haxe.io.Error){
            trace (e);
        }

        // Trying to read more bytes than are availible in Input
        var input = new haxe.io.StringInput("some");
        var read = haxe.io.Bytes.alloc(6);
        trace (input.readBytes(read,0,6));
    }

    public function readDoubleExample() {
        //TODO 
    }

    public function readFloatExample() {
        //TODO 
    }

    public function readFullBytesExample() {
        //TODO
    }

    public function readInt16Example() {
        //TODO 
    }

    public function readInt24Example() {
        //TODO 
    }

    public function readInt31Example() {
        //TODO 
    }

    // TODO: there's more 
}
