package examples.api.haxe.io;

import haxe.io.StringInput;
import haxe.io.BytesInput;

class StringInputExamples {
    public function new(){
    }

    public function sample_use(){
        // You can't initalize a BytesInput with a string
        // eg. var bytesInput = new BytesInput("testString");
        // will throw a compile time error

        // To make the initialization easier StringInput extends BytesInput (which extends Input)
        var stringInput = new StringInput("testString");
        // There are no additional functions, so let's use 
        // something from the Input class
        trace(stringInput.readString(4));


    }
}
