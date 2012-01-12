package examples.templates {
	import flash.Boot;
	public class User {
		public function User(firstName : String = null,lastName : String = null,age : int = 0) : void { if( !flash.Boot.skip_constructor ) {
			this.firstName = firstName;
			this.lastName = lastName;
			this.age = age;
		}}
		
		public var firstName : String;
		public var lastName : String;
		public var age : int;
	}
}
