package docprinter;

import neko.io.File;
import neko.FileSystem;
import doc.Comment;

class DocServer {
    
    public function new(){
    }
    
    static var sourceDirectory:String = '/home/robert/Projects/haxe/haXe_examples/src';
    static var outputDirectory:String = '/home/robert/Projects/haxe/haXe_examples/output';
     
    function foo(x,y) { return x + y; }
    
	public  function createDirectory(dirPath:String){
        var pathParts = dirPath.split("/");
        // win drive name fix
        //pathParts[0]=pathParts[0]+"/";
        pathParts.shift();
        pathParts.pop();
        pathParts[0]="/"+pathParts[0];
        var path = '';
        for (part in pathParts){
            path += part;
			if (!FileSystem.exists(path)){
                FileSystem.createDirectory(path);        
            }
            else{
            }


            path+="/";
        }
        
    }

    public function testSerialization(comments:Array<Comment>){
        // sort by className and line
        var sort_function = function (a:Comment, b:Comment){
            if (a.className > b.className)return 1;
            
            if (a.className < b.className) return -1;            
            if (a.className == b.className){
                if (a.line_no>b.line_no) return 1;
                if (a.line_no<b.line_no) return -1;
            };
            return 0;
        };
      comments.sort(sort_function);
      var fileName = StringTools.replace(comments[0].className,'.','/');
      var inputFile = File.read(sourceDirectory+'/'+fileName+'.hx', false);
      createDirectory(outputDirectory+'/'+fileName.substr(0, fileName.lastIndexOf('/', 0)));
      var outputFile = File.write(outputDirectory+'/'+fileName+'.hx', false);
  
      // let's try to get to the file
        try
        {
            
            var lineNum = 0;
            
            while( true )
            {
                var str = inputFile.readLine();
                lineNum++;
                outputFile.writeString(str+"\n");
                
                while (comments.length > 0 && comments[0].line_no <= lineNum){
                   var comment = comments.shift();
                   var padding = str.length-StringTools.ltrim(str).length;
                   var whiteSpace = str.substr(0, padding);
                   var commentText =  comment.text;
                   
                   var commentLines = commentText.split("\n");
                   for (line in commentLines){
                       outputFile.writeString(whiteSpace+"// " + line+"\n");
                   }
                
                    
                }
            }  
            }       
            catch( ex:haxe.io.Eof )             
            {}
            inputFile.close();
            outputFile.close();
      
      
    
        return ;
    }
    
    function testConfig(){
        return "dudu";
        if (!FileSystem.exists(DocServer.sourceDirectory)){
            return ("Error: Source directory does not exist ("+DocServer.sourceDirectory+")");    
        }
        if (!FileSystem.exists(DocServer.outputDirectory)){
            FileSystem.createDirectory(DocServer.outputDirectory);
            if (!FileSystem.exists(DocServer.outputDirectory)){
                return ("Error: Can't create the output directory ("+DocServer.outputDirectory+")" );
            }    
        }
       return "ok";
    }
    
    public static function main() {
        var ctx = new haxe.remoting.Context();
        ctx.addObject("DocServer",new DocServer());
        if( haxe.remoting.HttpConnection.handleRequest(ctx) )
          return;
        // handle normal request
        neko.Lib.print("This is a remoting server !");
  } 
}
