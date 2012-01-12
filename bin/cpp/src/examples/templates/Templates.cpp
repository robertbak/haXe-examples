#include <hxcpp.h>

#ifndef INCLUDED_examples_templates_Templates
#include <examples/templates/Templates.h>
#endif
#ifndef INCLUDED_examples_templates_User
#include <examples/templates/User.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Template
#include <haxe/Template.h>
#endif
namespace examples{
namespace templates{

Void Templates_obj::__construct()
{
{
}
;
	return null();
}

Templates_obj::~Templates_obj() { }

Dynamic Templates_obj::__CreateEmpty() { return  new Templates_obj; }
hx::ObjectPtr< Templates_obj > Templates_obj::__new()
{  hx::ObjectPtr< Templates_obj > result = new Templates_obj();
	result->__construct();
	return result;}

Dynamic Templates_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Templates_obj > result = new Templates_obj();
	result->__construct();
	return result;}

::String Templates_obj::example_variables( ){
	HX_SOURCE_PUSH("Templates_obj::example_variables")
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",19)
	::String templateDefinition = HX_CSTRING("This is a simple template called ::name::");
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",21)
	::haxe::Template _template = ::haxe::Template_obj::__new(templateDefinition);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("name") , HX_CSTRING("simple name"),false);
			return __result;
		}
	};
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",22)
	::String result = _template->execute(_Function_1_1::Block(),null());
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",23)
	::haxe::Log_obj::trace(result,hx::SourceInfo(HX_CSTRING("Templates.hx"),23,HX_CSTRING("examples.templates.Templates"),HX_CSTRING("example_variables")));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",24)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Templates_obj,example_variables,return )

::String Templates_obj::example_fields( ){
	HX_SOURCE_PUSH("Templates_obj::example_fields")
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",29)
	::String templateDefinition = HX_CSTRING("This shows the use of subfields ::user.firstName:: ::user.lastName::");
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",31)
	::examples::templates::User user = ::examples::templates::User_obj::__new(HX_CSTRING("Bob"),HX_CSTRING("Hope"),(int)43);
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",32)
	::haxe::Template _template = ::haxe::Template_obj::__new(templateDefinition);
	struct _Function_1_1{
		inline static Dynamic Block( ::examples::templates::User &user){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("user") , user,false);
			return __result;
		}
	};
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",33)
	::String result = _template->execute(_Function_1_1::Block(user),null());
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",34)
	::haxe::Log_obj::trace(result,hx::SourceInfo(HX_CSTRING("Templates.hx"),34,HX_CSTRING("examples.templates.Templates"),HX_CSTRING("example_fields")));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",35)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Templates_obj,example_fields,return )

::String Templates_obj::example_if( ){
	HX_SOURCE_PUSH("Templates_obj::example_if")
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",40)
	::String templateDefinition = HX_CSTRING("This shows the use of if -::if (user.age > 18):: Legal ::else:: Illegal ::end::");
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",42)
	::examples::templates::User user = ::examples::templates::User_obj::__new(HX_CSTRING("Bob"),HX_CSTRING("Hope"),(int)42);
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",43)
	::haxe::Template _template = ::haxe::Template_obj::__new(templateDefinition);
	struct _Function_1_1{
		inline static Dynamic Block( ::examples::templates::User &user){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("user") , user,false);
			return __result;
		}
	};
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",44)
	::String result = _template->execute(_Function_1_1::Block(user),null());
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",45)
	::haxe::Log_obj::trace(result,hx::SourceInfo(HX_CSTRING("Templates.hx"),45,HX_CSTRING("examples.templates.Templates"),HX_CSTRING("example_if")));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",46)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Templates_obj,example_if,return )

::String Templates_obj::example_for( ){
	HX_SOURCE_PUSH("Templates_obj::example_for")
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",51)
	::String templateDefinition = HX_CSTRING("This shows the use of for - ::foreach users:: ::firstName:: ::lastName:: age: (::age::)::end::");
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",52)
	Array< ::examples::templates::User > array = Array_obj< ::examples::templates::User >::__new();
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",53)
	array->push(::examples::templates::User_obj::__new(HX_CSTRING("Bob"),HX_CSTRING("Hope"),(int)43));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",54)
	array->push(::examples::templates::User_obj::__new(HX_CSTRING("Tom"),HX_CSTRING("Tam"),(int)18));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",55)
	array->push(::examples::templates::User_obj::__new(HX_CSTRING("Blip"),HX_CSTRING("Blop"),(int)12));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",56)
	::haxe::Template _template = ::haxe::Template_obj::__new(templateDefinition);
	struct _Function_1_1{
		inline static Dynamic Block( Array< ::examples::templates::User > &array){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("users") , array,false);
			return __result;
		}
	};
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",57)
	::String result = _template->execute(_Function_1_1::Block(array),null());
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",58)
	::haxe::Log_obj::trace(result,hx::SourceInfo(HX_CSTRING("Templates.hx"),58,HX_CSTRING("examples.templates.Templates"),HX_CSTRING("example_for")));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",59)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Templates_obj,example_for,return )

::String Templates_obj::example_makro( ){
	HX_SOURCE_PUSH("Templates_obj::example_makro")
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",64)
	::String templateDefinition = HX_CSTRING("This shows the use of makros - $$makro(::user.age::)");
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",66)
	::examples::templates::User user = ::examples::templates::User_obj::__new(HX_CSTRING("Bob"),HX_CSTRING("Hope"),(int)43);
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",67)
	::haxe::Template _template = ::haxe::Template_obj::__new(templateDefinition);
	struct _Function_1_1{
		inline static Dynamic Block( ::examples::templates::User &user){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("user") , user,false);
			return __result;
		}
	};
	struct _Function_1_2{
		inline static Dynamic Block( ::examples::templates::Templates_obj *__this){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("makro") , __this->makroFunction_dyn(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",68)
	::String result = _template->execute(_Function_1_1::Block(user),_Function_1_2::Block(this));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",69)
	::haxe::Log_obj::trace(result,hx::SourceInfo(HX_CSTRING("Templates.hx"),69,HX_CSTRING("examples.templates.Templates"),HX_CSTRING("example_makro")));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",70)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Templates_obj,example_makro,return )

::String Templates_obj::makroFunction( Dynamic resolve,int age){
	HX_SOURCE_PUSH("Templates_obj::makroFunction")
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",77)
	resolve(HX_CSTRING("user"));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",78)
	return HX_CSTRING("Test");
}


HX_DEFINE_DYNAMIC_FUNC2(Templates_obj,makroFunction,return )

::String Templates_obj::example_globals( ){
	HX_SOURCE_PUSH("Templates_obj::example_globals")
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",83)
	::haxe::Template_obj::globals->__FieldRef(HX_CSTRING("copyright")) = HX_CSTRING("Copyrighted by XX");
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",84)
	::String templateDefinition = HX_CSTRING("This shows the use of globals - ::copyright::");
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",87)
	::haxe::Template _template = ::haxe::Template_obj::__new(templateDefinition);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			return __result;
		}
	};
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",88)
	::String result = _template->execute(_Function_1_1::Block(),null());
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",89)
	::haxe::Log_obj::trace(result,hx::SourceInfo(HX_CSTRING("Templates.hx"),89,HX_CSTRING("examples.templates.Templates"),HX_CSTRING("example_globals")));
	HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/templates/Templates.hx",90)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Templates_obj,example_globals,return )


Templates_obj::Templates_obj()
{
}

void Templates_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Templates);
	HX_MARK_END_CLASS();
}

Dynamic Templates_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"example_if") ) { return example_if_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"example_for") ) { return example_for_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"example_makro") ) { return example_makro_dyn(); }
		if (HX_FIELD_EQ(inName,"makroFunction") ) { return makroFunction_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"example_fields") ) { return example_fields_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"example_globals") ) { return example_globals_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"example_variables") ) { return example_variables_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Templates_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Templates_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("example_variables"),
	HX_CSTRING("example_fields"),
	HX_CSTRING("example_if"),
	HX_CSTRING("example_for"),
	HX_CSTRING("example_makro"),
	HX_CSTRING("makroFunction"),
	HX_CSTRING("example_globals"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Templates_obj::__mClass;

void Templates_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("examples.templates.Templates"), hx::TCanCast< Templates_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Templates_obj::__boot()
{
}

} // end namespace examples
} // end namespace templates
