package examples.xml;

class XMLExamples {

    public function new() {

    }

    static public var testXMLString1 = "<test><item label='something' param='value'><subitem label='subitemlabel' /></item></test>";

    static public var testXMLString2 = 
    "<test label='mainNode' >
        <item label='item1' ></item>
        <item label='item2' />
        <notanitem label='not an item' />
     </test>";

    /**
     * Shows how to parse a string to XML
     */
    public function example_parse():Xml{
        var xml = Xml.parse(XMLExamples.testXMLString1);
        return(xml);
    }
 
    /**
     *  How to find stuff around XML 
     */
    public function example_browsing() {
        var xml = Xml.parse(XMLExamples.testXMLString2);
        trace ("firstChild() points to : " + xml.firstChild().nodeName);
        // All the nodes being children of the head node in XML
        for (i in xml.firstChild().elements()){
           trace (i.nodeName);
        }       

        // Just the nodes called 'item'
        for (i in xml.firstChild().elementsNamed("item")){
           trace (i.nodeName);
        }

        // Attributes of the main node
        for (attribute in xml.firstChild().attributes()){
            trace ("Attribute: " + attribute);
            trace ("Value:     " + xml.firstChild().get(attribute));
        }
    }

    public function example_modification() {
        var xml = Xml.parse(XMLExamples.testXMLString2);
        // StringTools.htmlEscape used to display it nicely in the browser
        // Let's take a look at what everything produces 
        trace (StringTools.htmlEscape(Xml.createElement("test").toString()));
        trace (StringTools.htmlEscape(Xml.createCData("test").toString()));
        trace (StringTools.htmlEscape(Xml.createComment("test").toString()));
        trace (StringTools.htmlEscape(Xml.createDocType("test").toString()));
        trace (StringTools.htmlEscape(Xml.createPCData("test").toString()));
        trace (StringTools.htmlEscape(Xml.createProlog("test").toString()));
        xml.firstChild().addChild(Xml.createElement("testElement"));
        trace (StringTools.htmlEscape(xml.toString()));
        xml.firstChild().insertChild(Xml.createElement("testElementForIndex0"),0);
        trace (StringTools.htmlEscape(xml.toString()));
    }

    /**
     * FastXML helps to work with XML while dealing with much less code
     */
    public function example_fastXML() {
        // let's parse some XML from a String
        var xml = Xml.parse(XMLExamples.testXMLString2);

        // This wraps a "regular" Xml node
        var fastXml = new haxe.xml.Fast(xml.firstChild());
        // get the name of the current node
        trace (fastXml.name);
        /* Output: test */

        // check if an attribute "label" exist 
        trace (fastXml.has.label);
        /* Output: true */

        // access an attribute called "label"
        trace (fastXml.att.label);
        /* Output: mainNode */

        // accessing attibutes which do not exists 
        try{
            //this will throw an exception
            trace (fastXml.att.notanattribute);
        }
        catch (msg:String){
            trace ("Exception: " + msg);
        }
        /** Output: Exception: test is missing attribute notanattribute **/

        // So a smart thing to do is:
        if (fastXml.has.notanattribute) trace(fastXml.has.notanattribute);
        /** Output: -- no exception thrown -- */

        if (fastXml.hasNode.item){
            for (fastNode in fastXml.nodes.item)
                trace("Type: " + fastNode.name + " - " + fastNode.att.label);
        }
    }

    static function main() {
        trace("hello world");
    }    

}
