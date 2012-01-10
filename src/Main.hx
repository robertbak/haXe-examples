package;
import examples.templates.Templates;
import examples.api.ArrayExamples;
import examples.api.haxe.TemplateExamples;
import doc.Comment;
import haxe.Serializer;
import neko.FileSystem;
import neko.Lib;

class Main {    
    
    public static var running_on:String;
    public static var file_comments:Array<Dynamic>;
    static var count:Int = 0;    
    public static function custom_trace( v : Dynamic, ?inf : haxe.PosInfos){     
    
    // neko.Lib.println("count = "+count+" "+running_on+":"+inf.lineNumber+":> "+v);
    
      var s = Std.string(v);
      var comment:Comment = new Comment(inf.lineNumber,running_on,s);
      count++;
    
      file_comments.push(comment);
    }
    
    public function new(){
    }
    
    public static function show_templates(){        
        var templates:Templates = new Templates();
        templates.example_variables();
        templates.example_fields();
        templates.example_if(); 
        templates.example_for(); 
        templates.example_makro();
        templates.example_globals();                   
    }
    
    
    public static function runOnClass(className:String){
       if (className!=""){
        file_comments = new Array<Comment>();
        
        running_on = className;
        var obj = Type.createInstance(Type.resolveClass(className),[]);
        var allFields = (Type.getInstanceFields(Type.resolveClass(className)));
        var isFunction = function(name)
            { return Reflect.isFunction(Reflect.field(obj,name)); }
        
        var functions = Lambda.filter(allFields, isFunction);
        for( ff in functions )
            Reflect.callMethod(obj, Reflect.field(obj,ff),[]);
        if (file_comments.length == 0)
            file_comments.push(new doc.Comment(0,running_on,'No traces'));
       }
    }
    static function createDirectory(dirPath:String){
        
        var pathParts = dirPath.split("/");
        // win drive name fix
        pathParts[0]=pathParts[0]+"/";
        var path = '';
        for (part in pathParts){
            path += part;
            trace(path);
            if (!FileSystem.exists(path)){
                FileSystem.createDirectory(path);        
            }
            path+="/";
        }
        
    }
    
    public static var classList:Array<String> = 
        ['examples.api.ArrayExamples', 'examples.api.haxe.TemplateExamples'
        ]; 
                            
    public static var URL = "http://127.0.0.1.:2000/Main.n";
    public static function main() {        
    
        haxe.Log.trace = custom_trace;
              
           runOnClass(classList.pop());    
            var cnx = haxe.remoting.HttpAsyncConnection.urlConnect(URL);
            cnx.setErrorHandler( function(err) trace("Error : "+Std.string(err)) );
       cnx.DocServer.testSerialization.call([file_comments],display);            
        
    }
    static function display(v) {
        
            Lib.println("1");
            Lib.println(classList);
            
        if (classList.length>0){
            
             runOnClass(classList.pop());    
            var cnx = haxe.remoting.HttpAsyncConnection.urlConnect(URL);
            cnx.setErrorHandler( function(err) trace("Error : "+Std.string(err)) );
            cnx.DocServer.testSerialization.call([file_comments],display);            
        }
  }
}
