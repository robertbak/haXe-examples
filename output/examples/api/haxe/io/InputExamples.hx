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
            trace("We get here - " + e);
            // We get here - Eof
        }
    }

    public function readAllExample(){
        var input = new haxe.io.StringInput("testString"); 
        var read = input.readAll();
        trace(read);
        // testString
        trace(Type.getClassName(Type.getClass(read)));
        // haxe.io.Bytes
    }

    public function readLineExample(){
        var input = new haxe.io.StringInput("first line \n second line"); 
        var read = input.readLine();
        trace(read);
        // first line 
        trace(Type.getClassName(Type.getClass(read)));
        // String
    }

    public function readByteExample(){
        var input = new haxe.io.StringInput("some text"); 
        var read = input.readByte();
        trace(read);
        // 115
        trace(Type.typeof(read));
        // TInt
        trace(String.fromCharCode(read));
        // s
    }

    public function readBytesExample(){
        var input = new haxe.io.StringInput("some text"); 
        // Allocate 4 bytes 
        var read = haxe.io.Bytes.alloc(4);
        // Read 1 byte and put it in read starting from index 0
        input.readBytes(read,0,1);
        trace(read);
        // s   

        // Read 2 bytes and put it in read starting from index 2
        input.readBytes(read,2,2);
        trace(read);
        // s om

        // Try putting data that will not fit
        try{
            input.readBytes(read,2,3);
        }
        catch (e:haxe.io.Error){
            trace (e);
            // OutsideBounds
        }
   
        // Trying to read more bytes than are availible in Input
        var input = new haxe.io.StringInput("some");
        var read = haxe.io.Bytes.alloc(6);
        trace (input.readBytes(read,0,6));
        // 4
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
