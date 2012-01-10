package examples.api;

class ArrayExamples {


    public function new_example(){
        var a1:Array<Int> = new Array<Int>();
        var a2:Array<String> = ['one','two','three'];
        /** Type inference works - http://en.wikipedia.org/wiki/Type_inference **/
        var a3 = ['one','two','three']; 
    }
    
    public function length_example(){
        var a = ['one','two','three'];
        trace (a.length);
    }
    
    public function concat_example(){
        var a = ['one','two','three'];
        var b = ['apple','pear'];
        var c = a.concat(b);
        trace (c);
        trace (a);
    }

    public function copy_example(){
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
    
    public function insert_example(){
         var a = ['one','two','three'];
         a.insert(0,'NEW');
         trace(a);
         a.insert(50,'too far');
         trace(a);
    }
    
    public function iterator(){
        // TODO
    }

    public function join_example(){
         var a = [1,2,3];
         var result = a.join('-');
         trace (result);
    }
    
    public function pop_example(){
        var a = ['one','two','three'];
        trace (a.pop());
        trace (a);
    }
    
    public function push_example(){
         var a = ['one','two','three'];
         trace (a.push('four'));
         trace (a);     
    }    
    
    public function remove_example(){
         var a = ['one','two','one'];
         trace (a.remove('one'));
         trace (a);     
         trace (a.remove('zebra'));
    }
    
    public function reverse_example(){
         var a = ['one','two','three'];
         a.reverse();
         trace (a);     
    }
    
    public function shift_example(){
         var a = ['one','two','three'];
         trace (a.shift());
         trace (a);
    }

    public function slice_example(){
         var a = [1,2,3,4,5,6,7,8,9];
         trace (a.slice(3,5));
         
         a = [1,2,3,4,5,6,7,8,9];
         trace (a.slice(3,-1));
    }
    
    public function sort_example(){
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
    
    public function splice_example(){
         var a = [1,2,3,4,5,6,7,8,9];
         trace (a.splice(3,5));
         trace (a);
    }
    
    public function unshift_example(){
         var a = ['one','two','three'];
         a.unshift('zero');
         trace (a);
    }
    
    public function new(){
    
    }
        
}
