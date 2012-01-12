package;
import examples.templates.Templates;
import examples.api.ArrayExamples;
import examples.api.haxe.io.BytesBufferExamples; 
import examples.api.haxe.io.BytesDataExamples; 
import examples.api.haxe.io.BytesExamples; 
import examples.api.haxe.io.BytesInputExamples; 
import examples.api.haxe.io.BytesOutputExamples; 
import examples.api.haxe.io.EofExamples; 
import examples.api.haxe.io.ErrorExamples; 
import examples.api.haxe.io.InputExamples; 
import examples.api.haxe.io.OutputExamples; 
import examples.api.haxe.io.StringInputExamples; 
import examples.api.haxe.TemplateExamples;
import examples.templates.Templates;
import examples.xml.XMLExamples;
import doc.Comment;
import haxe.Serializer;
import neko.FileSystem;
import neko.Lib;

class Main {    

    public static var running_on:String;
    public static var file_comments:Array<doc.Comment>;
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
        pathParts.pop();
        var path = '';
        for (part in pathParts){
            path += part;
            if (!FileSystem.exists(path)){
                trace(path+" doesnt exist");
                FileSystem.createDirectory(path);        
            }
            else{
                trace(path+" exists");
            }

            path+="/";
        }

    }
    static var traceHolder; 
    public static var classList:Array<String> = 
        ['examples.api.ArrayExamples', 'examples.api.haxe.TemplateExamples','examples.templates.Templates','examples.xml.XMLExamples',
        'examples.api.haxe.io.BytesExamples','examples.api.haxe.io.BytesBufferExamples',
'examples.api.haxe.io.BytesDataExamples', 
'examples.api.haxe.io.BytesExamples', 
'examples.api.haxe.io.BytesInputExamples', 
'examples.api.haxe.io.BytesOutputExamples', 
'examples.api.haxe.io.EofExamples', 
'examples.api.haxe.io.ErrorExamples', 
'examples.api.haxe.io.InputExamples', 
'examples.api.haxe.io.OutputExamples', 
'examples.api.haxe.io.StringInputExamples'];

    public static var URL = "http://localhost:2000/Server.n";
    public static function main() {        
        traceHolder = haxe.Log.trace;
        haxe.Log.trace = custom_trace;
        //	var docSrv = new docprinter.DocServer();
        //	docSrv.createDirectory("/home/robert/Projects/haxe/haXe_examples/output/examples");

        runOnClass(classList.pop());   
        haxe.Log.trace = traceHolder;

        var cnx = haxe.remoting.HttpAsyncConnection.urlConnect(URL);
        cnx.setErrorHandler( function(err) trace("Error : "+Std.string(err)) );
        cnx.DocServer.testSerialization.call([file_comments],display);            

    }
    static function display(v) {

        if (classList.length>0){
            haxe.Log.trace = custom_trace;
            runOnClass(classList.pop());    
            haxe.Log.trace = traceHolder;
            trace ("Running " + file_comments[0].className);
             
            var cnx = haxe.remoting.HttpAsyncConnection.urlConnect(URL);
            cnx.setErrorHandler( function(err) trace("Error : "+Std.string(err)) );
            cnx.DocServer.testSerialization.call([file_comments],display);            
        }
    }
}
