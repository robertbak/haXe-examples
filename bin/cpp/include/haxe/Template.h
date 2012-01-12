#ifndef INCLUDED_haxe_Template
#define INCLUDED_haxe_Template

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EReg)
HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS0(StringBuf)
HX_DECLARE_CLASS1(haxe,Template)
HX_DECLARE_CLASS2(haxe,_Template,TemplateExpr)
namespace haxe{


class Template_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Template_obj OBJ_;
		Template_obj();
		Void __construct(::String str);

	public:
		static hx::ObjectPtr< Template_obj > __new(::String str);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Template_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Template"); }

		::haxe::_Template::TemplateExpr expr; /* REM */ 
		Dynamic context; /* REM */ 
		Dynamic macros; /* REM */ 
		::List stack; /* REM */ 
		::StringBuf buf; /* REM */ 
		virtual ::String execute( Dynamic context,Dynamic macros);
		Dynamic execute_dyn();

		virtual Dynamic resolve( ::String v);
		Dynamic resolve_dyn();

		virtual ::List parseTokens( ::String data);
		Dynamic parseTokens_dyn();

		virtual ::haxe::_Template::TemplateExpr parseBlock( ::List tokens);
		Dynamic parseBlock_dyn();

		virtual ::haxe::_Template::TemplateExpr parse( ::List tokens);
		Dynamic parse_dyn();

		virtual Dynamic parseExpr( ::String data);
		Dynamic parseExpr_dyn();

		virtual Dynamic makeConst( ::String v);
		Dynamic makeConst_dyn();

		virtual Dynamic makePath( Dynamic e,::List l);
		Dynamic makePath_dyn();

		virtual Dynamic makeExpr( ::List l);
		Dynamic makeExpr_dyn();

		virtual Dynamic makeExpr2( ::List l);
		Dynamic makeExpr2_dyn();

		virtual Void run( ::haxe::_Template::TemplateExpr e);
		Dynamic run_dyn();

		static ::EReg splitter; /* REM */ 
		static ::EReg expr_splitter; /* REM */ 
		static ::EReg expr_trim; /* REM */ 
		static ::EReg expr_int; /* REM */ 
		static ::EReg expr_float; /* REM */ 
		static Dynamic globals; /* REM */ 
};

} // end namespace haxe

#endif /* INCLUDED_haxe_Template */ 
