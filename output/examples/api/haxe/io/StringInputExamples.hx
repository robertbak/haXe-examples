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
        
        // To make the initialization easier StringInput extends BytesInput 
        var stringInput = new StringInput("testString"); 
        trace(stringInput.readString(4));
        // test


    }
}
