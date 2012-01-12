#include <hxcpp.h>

#include <StringBuf.h>
#include <examples/templates/User.h>
#include <examples/templates/Templates.h>
#include <Reflect.h>
#include <List.h>
#include <examples/api/ArrayExamples.h>
#include <Std.h>
#include <Main.h>
#include <haxe/Log.h>
#include <haxe/Template.h>
#include <EReg.h>
#include <cpp/Lib.h>
#include <haxe/_Template/TemplateExpr.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::StringBuf_obj::__register();
::examples::templates::User_obj::__register();
::examples::templates::Templates_obj::__register();
::Reflect_obj::__register();
::List_obj::__register();
::examples::api::ArrayExamples_obj::__register();
::Std_obj::__register();
::Main_obj::__register();
::haxe::Log_obj::__register();
::haxe::Template_obj::__register();
::EReg_obj::__register();
::cpp::Lib_obj::__register();
::haxe::_Template::TemplateExpr_obj::__register();
::cpp::Lib_obj::__boot();
::EReg_obj::__boot();
::haxe::Log_obj::__boot();
::haxe::_Template::TemplateExpr_obj::__boot();
::haxe::Template_obj::__boot();
::Main_obj::__boot();
::Std_obj::__boot();
::examples::api::ArrayExamples_obj::__boot();
::List_obj::__boot();
::Reflect_obj::__boot();
::examples::templates::Templates_obj::__boot();
::examples::templates::User_obj::__boot();
::StringBuf_obj::__boot();
}

