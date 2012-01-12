#ifndef INCLUDED_haxe__Template_TemplateExpr
#define INCLUDED_haxe__Template_TemplateExpr

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS2(haxe,_Template,TemplateExpr)
namespace haxe{
namespace _Template{


class TemplateExpr_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TemplateExpr_obj OBJ_;

	public:
		TemplateExpr_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxe._Template.TemplateExpr"); }
		::String __ToString() const { return HX_CSTRING("TemplateExpr.") + tag; }

		static ::haxe::_Template::TemplateExpr OpBlock(::List l);
		static Dynamic OpBlock_dyn();
		static ::haxe::_Template::TemplateExpr OpExpr(Dynamic expr);
		static Dynamic OpExpr_dyn();
		static ::haxe::_Template::TemplateExpr OpForeach(Dynamic expr,::haxe::_Template::TemplateExpr loop);
		static Dynamic OpForeach_dyn();
		static ::haxe::_Template::TemplateExpr OpIf(Dynamic expr,::haxe::_Template::TemplateExpr eif,::haxe::_Template::TemplateExpr eelse);
		static Dynamic OpIf_dyn();
		static ::haxe::_Template::TemplateExpr OpMacro(::String name,::List params);
		static Dynamic OpMacro_dyn();
		static ::haxe::_Template::TemplateExpr OpStr(::String str);
		static Dynamic OpStr_dyn();
		static ::haxe::_Template::TemplateExpr OpVar(::String v);
		static Dynamic OpVar_dyn();
};

} // end namespace haxe
} // end namespace _Template

#endif /* INCLUDED_haxe__Template_TemplateExpr */ 
