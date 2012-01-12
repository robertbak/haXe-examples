#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_haxe__Template_TemplateExpr
#include <haxe/_Template/TemplateExpr.h>
#endif
namespace haxe{
namespace _Template{

::haxe::_Template::TemplateExpr  TemplateExpr_obj::OpBlock(::List l)
	{ return hx::CreateEnum< TemplateExpr_obj >(HX_CSTRING("OpBlock"),4,hx::DynamicArray(0,1).Add(l)); }

::haxe::_Template::TemplateExpr  TemplateExpr_obj::OpExpr(Dynamic expr)
	{ return hx::CreateEnum< TemplateExpr_obj >(HX_CSTRING("OpExpr"),1,hx::DynamicArray(0,1).Add(expr)); }

::haxe::_Template::TemplateExpr  TemplateExpr_obj::OpForeach(Dynamic expr,::haxe::_Template::TemplateExpr loop)
	{ return hx::CreateEnum< TemplateExpr_obj >(HX_CSTRING("OpForeach"),5,hx::DynamicArray(0,2).Add(expr).Add(loop)); }

::haxe::_Template::TemplateExpr  TemplateExpr_obj::OpIf(Dynamic expr,::haxe::_Template::TemplateExpr eif,::haxe::_Template::TemplateExpr eelse)
	{ return hx::CreateEnum< TemplateExpr_obj >(HX_CSTRING("OpIf"),2,hx::DynamicArray(0,3).Add(expr).Add(eif).Add(eelse)); }

::haxe::_Template::TemplateExpr  TemplateExpr_obj::OpMacro(::String name,::List params)
	{ return hx::CreateEnum< TemplateExpr_obj >(HX_CSTRING("OpMacro"),6,hx::DynamicArray(0,2).Add(name).Add(params)); }

::haxe::_Template::TemplateExpr  TemplateExpr_obj::OpStr(::String str)
	{ return hx::CreateEnum< TemplateExpr_obj >(HX_CSTRING("OpStr"),3,hx::DynamicArray(0,1).Add(str)); }

::haxe::_Template::TemplateExpr  TemplateExpr_obj::OpVar(::String v)
	{ return hx::CreateEnum< TemplateExpr_obj >(HX_CSTRING("OpVar"),0,hx::DynamicArray(0,1).Add(v)); }

HX_DEFINE_CREATE_ENUM(TemplateExpr_obj)

int TemplateExpr_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("OpBlock")) return 4;
	if (inName==HX_CSTRING("OpExpr")) return 1;
	if (inName==HX_CSTRING("OpForeach")) return 5;
	if (inName==HX_CSTRING("OpIf")) return 2;
	if (inName==HX_CSTRING("OpMacro")) return 6;
	if (inName==HX_CSTRING("OpStr")) return 3;
	if (inName==HX_CSTRING("OpVar")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TemplateExpr_obj,OpBlock,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TemplateExpr_obj,OpExpr,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(TemplateExpr_obj,OpForeach,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(TemplateExpr_obj,OpIf,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(TemplateExpr_obj,OpMacro,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TemplateExpr_obj,OpStr,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TemplateExpr_obj,OpVar,return)

int TemplateExpr_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("OpBlock")) return 1;
	if (inName==HX_CSTRING("OpExpr")) return 1;
	if (inName==HX_CSTRING("OpForeach")) return 2;
	if (inName==HX_CSTRING("OpIf")) return 3;
	if (inName==HX_CSTRING("OpMacro")) return 2;
	if (inName==HX_CSTRING("OpStr")) return 1;
	if (inName==HX_CSTRING("OpVar")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic TemplateExpr_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("OpBlock")) return OpBlock_dyn();
	if (inName==HX_CSTRING("OpExpr")) return OpExpr_dyn();
	if (inName==HX_CSTRING("OpForeach")) return OpForeach_dyn();
	if (inName==HX_CSTRING("OpIf")) return OpIf_dyn();
	if (inName==HX_CSTRING("OpMacro")) return OpMacro_dyn();
	if (inName==HX_CSTRING("OpStr")) return OpStr_dyn();
	if (inName==HX_CSTRING("OpVar")) return OpVar_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("OpVar"),
	HX_CSTRING("OpExpr"),
	HX_CSTRING("OpIf"),
	HX_CSTRING("OpStr"),
	HX_CSTRING("OpBlock"),
	HX_CSTRING("OpForeach"),
	HX_CSTRING("OpMacro"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class TemplateExpr_obj::__mClass;

Dynamic __Create_TemplateExpr_obj() { return new TemplateExpr_obj; }

void TemplateExpr_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe._Template.TemplateExpr"), hx::TCanCast< TemplateExpr_obj >,sStaticFields,sMemberFields,
	&__Create_TemplateExpr_obj, &__Create,
	&super::__SGetClass(), &CreateTemplateExpr_obj, sMarkStatics);
}

void TemplateExpr_obj::__boot()
{
}


} // end namespace haxe
} // end namespace _Template
