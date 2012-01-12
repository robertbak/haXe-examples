#include <hxcpp.h>

#ifndef INCLUDED_examples_templates_User
#include <examples/templates/User.h>
#endif
namespace examples{
namespace templates{

Void User_obj::__construct(::String firstName,::String lastName,int age)
{
{
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",102)
	this->firstName = firstName;
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",103)
	this->lastName = lastName;
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",104)
	this->age = age;
}
;
	return null();
}

User_obj::~User_obj() { }

Dynamic User_obj::__CreateEmpty() { return  new User_obj; }
hx::ObjectPtr< User_obj > User_obj::__new(::String firstName,::String lastName,int age)
{  hx::ObjectPtr< User_obj > result = new User_obj();
	result->__construct(firstName,lastName,age);
	return result;}

Dynamic User_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< User_obj > result = new User_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}


User_obj::User_obj()
{
}

void User_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(User);
	HX_MARK_MEMBER_NAME(firstName,"firstName");
	HX_MARK_MEMBER_NAME(lastName,"lastName");
	HX_MARK_MEMBER_NAME(age,"age");
	HX_MARK_END_CLASS();
}

Dynamic User_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"age") ) { return age; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"lastName") ) { return lastName; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"firstName") ) { return firstName; }
	}
	return super::__Field(inName);
}

Dynamic User_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"age") ) { age=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"lastName") ) { lastName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"firstName") ) { firstName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void User_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("firstName"));
	outFields->push(HX_CSTRING("lastName"));
	outFields->push(HX_CSTRING("age"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("firstName"),
	HX_CSTRING("lastName"),
	HX_CSTRING("age"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class User_obj::__mClass;

void User_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("examples.templates.User"), hx::TCanCast< User_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void User_obj::__boot()
{
}

} // end namespace examples
} // end namespace templates
