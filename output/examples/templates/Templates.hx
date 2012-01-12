package examples.templates;
import haxe.Template;

/**
 * @see http://haxe.org/doc/cross/template.html
 */

class Templates
{

    public function new() 
    {
    }
    
    public function example_variables():String {
        
        var templateDefinition:String = "This is a simple template called ::name::";
        
        var template = new Template(templateDefinition);
        var result   = template.execute( { name:"simple name" } );
        trace(result);
        // This is a simple template called simple name
        return result;
    }
    
    public function example_fields():String {
        
        var templateDefinition:String = "This shows the use of subfields ::user.firstName:: ::user.lastName::";
        
        var user:User = new User("Bob", "Hope", 43);                
        var template = new Template(templateDefinition);
        var result   = template.execute({user:user});
        trace(result);
        // This shows the use of subfields Bob Hope
        return result;
    }
    
    public function example_if():String {
        
        var templateDefinition:String = "This shows the use of if -::if (user.age > 18):: Legal ::else:: Illegal ::end::";
        
        var user:User = new User("Bob", "Hope", 42);                
        var template = new Template(templateDefinition);
        var result   = template.execute({user:user});
        trace(result);
        // This shows the use of if - Legal 
        return result;
    }
    
    public function example_for():String {
        
        var templateDefinition:String = "This shows the use of for - ::foreach users:: ::firstName:: ::lastName:: age: (::age::)::end::";        
        var array:Array<User> = new Array<User>();  
        array.push(new User("Bob", "Hope", 43));
        array.push(new User("Tom", "Tam",  18));
        array.push(new User("Blip", "Blop",  12));
        var template = new Template(templateDefinition);
        var result   = template.execute({users:array});
        trace(result);
        // This shows the use of for -  Bob Hope age: (43) Tom Tam age: (18) Blip Blop age: (12)
        return result;
    }
    
    public function example_makro():String {
        
		var makroFunction = function ( resolve: String -> Dynamic, age:Int):String {
        
            // this gives the value of the user variable in the context
            resolve('user');
            return "Test" ;
        }
		
        var templateDefinition:String = "This shows the use of makros - $$makro(::user.age::)";
        
        var user:User = new User("Bob", "Hope", 43);                
        var template = new Template(templateDefinition);
        var result   = template.execute({user:user},{makro:makroFunction});
        trace(result);
        // This shows the use of makros - Test
        return result;
    }
    
    
    
    
    public function example_globals():String {
        // use the Template.globals
        Template.globals.copyright = "Copyrighted by XX";
        var templateDefinition:String = "This shows the use of globals - ::copyright::";
        
        
        var template = new Template(templateDefinition);
        var result   = template.execute({});
        trace(result);
        // This shows the use of globals - Copyrighted by XX
        return result;
    }
    
    
}

class User {
    public var firstName:String;
    public var lastName:String;
    public var age:Int;
    
    public function new(firstName:String, lastName:String, age:Int) {
        this.firstName = firstName;
        this.lastName  = lastName;
        this.age = age;
    }
}
