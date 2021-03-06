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
        // 3
    }
    
    public function concatExample(){
        var a = ['one','two','three'];
        var b = ['apple','pear'];
        var c = a.concat(b);
        trace (c);
        // [one, two, three, apple, pear]
        trace (a);
        // [one, two, three]
    }

    public function copyExample(){
        var a = ['one','two','three'];
        var c = a.copy();
        trace (c);
        // [one, two, three]
        
        // References to the original objects are copied 
        var a:Array<StringBuf> = new Array<StringBuf>();
        var sb:StringBuf = new StringBuf();
        sb.add("firstpart");
        a.push(sb);
        var c = a.copy();
        trace (c);
        // [firstpart]
        a[0].add("secondpart");
        trace (c);
        // [firstpartsecondpart]
    }
    
    public function insertExample(){
         var a = ['one','two','three'];
         a.insert(0,'NEW');
         trace(a);
         // [NEW, one, two, three]
         a.insert(50,'too far');
         trace(a);
         // [NEW, one, two, three, too far]
    }
    
    public function iterator(){
        // TODO
    }

    public function joinExample(){
         var a = [1,2,3];
         var result = a.join('-');
         trace (result);
         // 1-2-3
    }
    
    public function popExample(){
        var a = ['one','two','three'];
        trace (a.pop());
        // three
        trace (a);
        // [one, two]
    }
    
    public function pushExample(){
         var a = ['one','two','three'];
         trace (a.push('four'));
         // 4
         trace (a);     
         // [one, two, three, four]
    }    
    
    public function removeExample(){
         var a = ['one','two','one'];
         trace (a.remove('one'));
         // true
         trace (a);     
         // [two, one]
         trace (a.remove('zebra'));
         // false
    }
    
    public function reverseExample(){
         var a = ['one','two','three'];
         a.reverse();
         trace (a);     
         // [three, two, one]
    }
    
    public function shiftExample(){
         var a = ['one','two','three'];
         trace (a.shift());
         // one
         trace (a);
         // [two, three]
    }

    public function sliceExample(){
         var a = [1,2,3,4,5,6,7,8,9];
         trace (a.slice(3,5));
         // [4, 5]
         
         a = [1,2,3,4,5,6,7,8,9];
         trace (a.slice(3,-1));
         // [4, 5, 6, 7, 8]
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
        // [9, 8, 7, 6, 5, 4, 3, 2, 1]
    }   
    
    public function spliceExample(){
         var a = [1,2,3,4,5,6,7,8,9];
         trace (a.splice(3,5));
         // [4, 5, 6, 7, 8]
         trace (a);
         // [1, 2, 3, 9]
    }
    
    public function unshiftExample(){
         var a = ['one','two','three'];
         a.unshift('zero');
         trace (a);
         // [zero, one, two, three]
    }
    
    public function new(){
    
    }
        
}
