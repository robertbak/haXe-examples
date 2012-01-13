package examples.api;

class ArrayExamples {


    public function newExample(){
        var a1:Array<Int> = new Array<Int>();
        var a2:Array<String> = ['one','two','three'];
        /** Type inference works - http://en.wikipedia.org/wiki/Type_inference **/
        var a3 = ['one','two','three']; 
    }
    
    public function lengthExample(){
        var a = ['one','two','three'];
        trace (a.length);
    }
    
    public function concatExample(){
        var a = ['one','two','three'];
        var b = ['apple','pear'];
        var c = a.concat(b);
        trace (c);
        trace (a);
    }

    public function copyExample(){
        var a = ['one','two','three'];
        var c = a.copy();
        trace (c);
        
        // References to the original objects are copied 
        var a:Array<StringBuf> = new Array<StringBuf>();
        var sb:StringBuf = new StringBuf();
        sb.add("firstpart");
        a.push(sb);
        var c = a.copy();
        trace (c);
        a[0].add("secondpart");
        trace (c);
    }
    
    public function insertExample(){
         var a = ['one','two','three'];
         a.insert(0,'NEW');
         trace(a);
         a.insert(50,'too far');
         trace(a);
    }
    
    public function iterator(){
        // TODO
    }

    public function joinExample(){
         var a = [1,2,3];
         var result = a.join('-');
         trace (result);
    }
    
    public function popExample(){
        var a = ['one','two','three'];
        trace (a.pop());
        trace (a);
    }
    
    public function pushExample(){
         var a = ['one','two','three'];
         trace (a.push('four'));
         trace (a);     
    }    
    
    public function removeExample(){
         var a = ['one','two','one'];
         trace (a.remove('one'));
         trace (a);     
         trace (a.remove('zebra'));
    }
    
    public function reverseExample(){
         var a = ['one','two','three'];
         a.reverse();
         trace (a);     
    }
    
    public function shiftExample(){
         var a = ['one','two','three'];
         trace (a.shift());
         trace (a);
    }

    public function sliceExample(){
         var a = [1,2,3,4,5,6,7,8,9];
         trace (a.slice(3,5));
         
         a = [1,2,3,4,5,6,7,8,9];
         trace (a.slice(3,-1));
    }
    
    public function sortExample(){
        /** Reverse order **/
        var sort_function = 
            function(x:Int,y:Int){
                
                if (x > y){
                    return -1;
                }
                else if (x < y){
                    return 1;
                }
                return 0;                
            };
        
        var a = [1,2,3,4,5,6,7,8,9];
        a.sort(sort_function);
        trace(a);
    }   
    
    public function spliceExample(){
         var a = [1,2,3,4,5,6,7,8,9];
         trace (a.splice(3,5));
         trace (a);
    }
    
    public function unshiftExample(){
         var a = ['one','two','three'];
         a.unshift('zero');
         trace (a);
    }
    
    public function new(){
    
    }
        
}
