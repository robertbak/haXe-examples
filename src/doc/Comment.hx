package doc;

class Comment {
    public var text:String;
    public var line_no:Int;
    public var className:String;
    
    public function new(line_no,className,text){
        this.line_no = line_no;
        this.className = className;
        this.text = text;
    }
}
