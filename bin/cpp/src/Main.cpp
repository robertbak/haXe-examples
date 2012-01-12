#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_examples_api_ArrayExamples
#include <examples/api/ArrayExamples.h>
#endif
#ifndef INCLUDED_examples_templates_Templates
#include <examples/templates/Templates.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void Main_obj::__construct()
{
{
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::custom_trace( Dynamic v,Dynamic inf){
{
		HX_SOURCE_PUSH("Main_obj::custom_trace")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,custom_trace,(void))

Void Main_obj::show_templates( ){
{
		HX_SOURCE_PUSH("Main_obj::show_templates")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",15)
		::examples::templates::Templates templates = ::examples::templates::Templates_obj::__new();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",16)
		templates->example_variables();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",17)
		templates->example_fields();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",18)
		templates->example_if();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",19)
		templates->example_for();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",20)
		templates->example_makro();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",21)
		templates->example_globals();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,show_templates,(void))

Void Main_obj::main( ){
{
		HX_SOURCE_PUSH("Main_obj::main")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",25)
		::haxe::Log_obj::trace(HX_CSTRING("Heldsssa  Frodsae 2!"),hx::SourceInfo(HX_CSTRING("Main.hx"),25,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",27)
		::haxe::Log_obj::trace = ::Main_obj::custom_trace_dyn();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/Main.hx",28)
		::examples::api::ArrayExamples_obj::show_usage_example();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_END_CLASS();
}

Dynamic Main_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"custom_trace") ) { return custom_trace_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"show_templates") ) { return show_templates_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("custom_trace"),
	HX_CSTRING("show_templates"),
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Main_obj::__boot()
{
}

