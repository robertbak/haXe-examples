package examples.api;

// Most of this examples were created by http://haxe.org/wiki/user?name=ianxm
class LambdaExamples {

    function new() {
    }

    public function arrayExample() {
        var list = new List<Int>();
        list.add(1);
        list.add(2);
        var array = Lambda.array(list);
        trace (array);
    }

    public function concatExample() {
        var list = new List();
        list.add(1);
        list.add(2);
        var array = [3,4];
        var result = Lambda.concat(list,array);
        trace (result);
    }

    public function countExample() {
        var array = [1,2];
        var result = Lambda.count(array);
        trace (result);
    }

    public function emptyExample(){
        var array = [1];
        trace (Lambda.empty(array));

        var array = [];
        trace (Lambda.empty(array));
    }

    public function existsExample() {
        var fun = function (element)
        { return if (element > 5) {true;} else {false;}};
        var array = [0,1];
        trace (Lambda.exists(array,fun));
        var array = [0,1,6];
        trace (Lambda.exists(array,fun));
    }

    public function filterExample() {
        var fun = function (element)
        { return if (element > 5) {true;} else {false;}};
        var array = [0,1,6];
        trace (Lambda.filter(array,fun));
    }

    public function foldExample() {
        var fun = function (newThing,oldThing){ return newThing+oldThing;};
        var array = [1,2,3,4,5];

        trace (Lambda.fold(array,fun,0));
        trace (Lambda.fold(array,fun,10));
    }


    public function foreachExample() {
        var fun = function (element)
        { return if (element > 5) {true;} else {false;}};
        var array = [0,1];
        trace (Lambda.foreach(array,fun));
        var array = [0,1,6];
        trace (Lambda.foreach(array,fun));
    }

    public function hasExample() {
        // compare using the == operator
        var array = [0,1];
        trace (Lambda.has(array,1));
        trace (Lambda.has(array,2));


        var stringArray = ["underdog","overcat"];
        //  does a string end with element 
        var fun = function (x, element) 
        { return StringTools.endsWith(x,element);};
        trace (Lambda.has(stringArray,"dog",fun));
        trace (Lambda.has(stringArray,"over",fun));
    }

    public function indexOf() {
        var array = ["one","two","three"];
        trace (Lambda.indexOf(array,"two"));
    }

    public function iterExample() {
        var result = 0;
        var fun = function (x) { result = result + x;};  

        var array = [1,2,3,4,5];
        Lambda.iter(array,fun);
        trace (result);
    }

    public function listExample() {
        var array = [1,2];
        trace (array);
        trace (Lambda.list(array));
    }

    public function mapExample() {
        var array = [1,2,5];
        var fun = function (x) {return Std.string(x);};
        trace (Lambda.map(array,fun));
    }

    public function mapiExample(){
        var array = [1,4,5];
        var fun = function (index,x) 
        {return Std.string(index)+"->"+Std.string(x);};
        trace (Lambda.mapi(array,fun));
    }

}
