#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_Template
#include <haxe/Template.h>
#endif
#ifndef INCLUDED_haxe__Template_TemplateExpr
#include <haxe/_Template/TemplateExpr.h>
#endif
namespace haxe{

Void Template_obj::__construct(::String str)
{
{
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",65)
	::List tokens = this->parseTokens(str);
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",66)
	this->expr = this->parseBlock(tokens);
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",67)
	if ((!(tokens->isEmpty()))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",68)
		hx::Throw (((HX_CSTRING("Unexpected '") + tokens->first()->__Field(HX_CSTRING("s"))) + HX_CSTRING("'")));
	}
}
;
	return null();
}

Template_obj::~Template_obj() { }

Dynamic Template_obj::__CreateEmpty() { return  new Template_obj; }
hx::ObjectPtr< Template_obj > Template_obj::__new(::String str)
{  hx::ObjectPtr< Template_obj > result = new Template_obj();
	result->__construct(str);
	return result;}

Dynamic Template_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Template_obj > result = new Template_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Template_obj::execute( Dynamic context,Dynamic macros){
	HX_SOURCE_PUSH("Template_obj::execute")
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			return __result;
		}
	};
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",72)
	this->macros = (  (((macros == null()))) ? Dynamic(_Function_1_1::Block()) : Dynamic(macros) );
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",73)
	this->context = context;
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",74)
	this->stack = ::List_obj::__new();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",75)
	this->buf = ::StringBuf_obj::__new();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",76)
	this->run(this->expr);
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",77)
	return this->buf->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC2(Template_obj,execute,return )

Dynamic Template_obj::resolve( ::String v){
	HX_SOURCE_PUSH("Template_obj::resolve")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",81)
	if ((::Reflect_obj::hasField(this->context,v))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",82)
		return ::Reflect_obj::field(this->context,v);
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",83)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(this->stack->iterator());  __it->hasNext(); ){
		Dynamic ctx = __it->next();
		if ((::Reflect_obj::hasField(ctx,v))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",85)
			return ::Reflect_obj::field(ctx,v);
		}
;
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",86)
	if (((v == HX_CSTRING("__current__")))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",87)
		return this->context;
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",88)
	return ::Reflect_obj::field(::haxe::Template_obj::globals,v);
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,resolve,return )

::List Template_obj::parseTokens( ::String data){
	HX_SOURCE_PUSH("Template_obj::parseTokens")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",92)
	::List tokens = ::List_obj::__new();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",93)
	while((::haxe::Template_obj::splitter->match(data))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",94)
		Dynamic p = ::haxe::Template_obj::splitter->matchedPos();
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",95)
		if (((p->__Field(HX_CSTRING("pos")) > (int)0))){
			struct _Function_3_1{
				inline static Dynamic Block( ::String &data,Dynamic &p){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("p") , data.substr((int)0,p->__Field(HX_CSTRING("pos"))),false);
					__result->Add(HX_CSTRING("s") , true,false);
					__result->Add(HX_CSTRING("l") , null(),false);
					return __result;
				}
			};
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",96)
			tokens->add(_Function_3_1::Block(data,p));
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",99)
		if (((data.charCodeAt(p->__Field(HX_CSTRING("pos"))) == (int)58))){
			struct _Function_3_1{
				inline static Dynamic Block( ::String &data,Dynamic &p){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("p") , data.substr((p->__Field(HX_CSTRING("pos")) + (int)2),(p->__Field(HX_CSTRING("len")) - (int)4)),false);
					__result->Add(HX_CSTRING("s") , false,false);
					__result->Add(HX_CSTRING("l") , null(),false);
					return __result;
				}
			};
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",100)
			tokens->add(_Function_3_1::Block(data,p));
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",101)
			data = ::haxe::Template_obj::splitter->matchedRight();
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",102)
			continue;
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",106)
		int parp = (p->__Field(HX_CSTRING("pos")) + p->__Field(HX_CSTRING("len")));
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",107)
		int npar = (int)1;
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",108)
		while(((npar > (int)0))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",109)
			Dynamic c = data.charCodeAt(parp);
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",110)
			if (((c == (int)40))){
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",111)
				(npar)++;
			}
			else{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",112)
				if (((c == (int)41))){
					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",113)
					(npar)--;
				}
				else{
					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",114)
					if (((c == null()))){
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",115)
						hx::Throw (HX_CSTRING("Unclosed macro parenthesis"));
					}
				}
			}
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",116)
			(parp)++;
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",118)
		Array< ::String > params = data.substr((p->__Field(HX_CSTRING("pos")) + p->__Field(HX_CSTRING("len"))),((parp - ((p->__Field(HX_CSTRING("pos")) + p->__Field(HX_CSTRING("len"))))) - (int)1)).split(HX_CSTRING(","));
		struct _Function_2_1{
			inline static Dynamic Block( Array< ::String > &params){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("p") , ::haxe::Template_obj::splitter->matched((int)2),false);
				__result->Add(HX_CSTRING("s") , false,false);
				__result->Add(HX_CSTRING("l") , params,false);
				return __result;
			}
		};
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",119)
		tokens->add(_Function_2_1::Block(params));
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",120)
		data = data.substr(parp,(data.length - parp));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",122)
	if (((data.length > (int)0))){
		struct _Function_2_1{
			inline static Dynamic Block( ::String &data){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("p") , data,false);
				__result->Add(HX_CSTRING("s") , true,false);
				__result->Add(HX_CSTRING("l") , null(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",123)
		tokens->add(_Function_2_1::Block(data));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",124)
	return tokens;
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,parseTokens,return )

::haxe::_Template::TemplateExpr Template_obj::parseBlock( ::List tokens){
	HX_SOURCE_PUSH("Template_obj::parseBlock")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",128)
	::List l = ::List_obj::__new();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",129)
	while((true)){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",130)
		Dynamic t = tokens->first();
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",131)
		if (((t == null()))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",132)
			break;
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",133)
		if (((bool(!(t->__Field(HX_CSTRING("s")))) && bool(((bool((bool((t->__Field(HX_CSTRING("p")) == HX_CSTRING("end"))) || bool((t->__Field(HX_CSTRING("p")) == HX_CSTRING("else"))))) || bool((t->__Field(HX_CSTRING("p"))->__Field(HX_CSTRING("substr"))((int)0,(int)7) == HX_CSTRING("elseif "))))))))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",134)
			break;
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",135)
		l->add(this->parse(tokens));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",137)
	if (((l->length == (int)1))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",138)
		return l->first();
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",139)
	return ::haxe::_Template::TemplateExpr_obj::OpBlock(l);
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,parseBlock,return )

::haxe::_Template::TemplateExpr Template_obj::parse( ::List tokens){
	HX_SOURCE_PUSH("Template_obj::parse")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",143)
	Dynamic t = tokens->pop();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",144)
	::String p = t->__Field(HX_CSTRING("p"));
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",145)
	if ((t->__Field(HX_CSTRING("s")))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",146)
		return ::haxe::_Template::TemplateExpr_obj::OpStr(p);
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",148)
	if (((t->__Field(HX_CSTRING("l")) != null()))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",149)
		::List pe = ::List_obj::__new();
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",150)
		{
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",150)
			int _g = (int)0;
			Array< ::String > _g1 = t->__Field(HX_CSTRING("l"));
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",150)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",150)
				::String p1 = _g1->__get(_g);
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",150)
				++(_g);
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",151)
				pe->add(this->parseBlock(this->parseTokens(p1)));
			}
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",152)
		return ::haxe::_Template::TemplateExpr_obj::OpMacro(p,pe);
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",155)
	if (((p.substr((int)0,(int)3) == HX_CSTRING("if ")))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",156)
		p = p.substr((int)3,(p.length - (int)3));
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",157)
		Dynamic e = this->parseExpr(p);
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",158)
		::haxe::_Template::TemplateExpr eif = this->parseBlock(tokens);
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",159)
		Dynamic t1 = tokens->first();
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",160)
		::haxe::_Template::TemplateExpr eelse;
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",161)
		if (((t1 == null()))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",162)
			hx::Throw (HX_CSTRING("Unclosed 'if'"));
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",163)
		if (((t1->__Field(HX_CSTRING("p")) == HX_CSTRING("end")))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",164)
			tokens->pop();
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",165)
			eelse = null();
		}
		else{
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",166)
			if (((t1->__Field(HX_CSTRING("p")) == HX_CSTRING("else")))){
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",167)
				tokens->pop();
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",168)
				eelse = this->parseBlock(tokens);
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",169)
				t1 = tokens->pop();
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",170)
				if (((bool((t1 == null())) || bool((t1->__Field(HX_CSTRING("p")) != HX_CSTRING("end")))))){
					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",171)
					hx::Throw (HX_CSTRING("Unclosed 'else'"));
				}
			}
			else{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",173)
				t1->__FieldRef(HX_CSTRING("p")) = t1->__Field(HX_CSTRING("p"))->__Field(HX_CSTRING("substr"))((int)4,(t1->__Field(HX_CSTRING("p"))->__Field(HX_CSTRING("length")) - (int)4));
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",174)
				eelse = this->parse(tokens);
			}
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",176)
		return ::haxe::_Template::TemplateExpr_obj::OpIf(e,eif,eelse);
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",178)
	if (((p.substr((int)0,(int)8) == HX_CSTRING("foreach ")))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",179)
		p = p.substr((int)8,(p.length - (int)8));
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",180)
		Dynamic e = this->parseExpr(p);
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",181)
		::haxe::_Template::TemplateExpr efor = this->parseBlock(tokens);
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",182)
		Dynamic t1 = tokens->pop();
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",183)
		if (((bool((t1 == null())) || bool((t1->__Field(HX_CSTRING("p")) != HX_CSTRING("end")))))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",184)
			hx::Throw (HX_CSTRING("Unclosed 'foreach'"));
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",185)
		return ::haxe::_Template::TemplateExpr_obj::OpForeach(e,efor);
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",187)
	if ((::haxe::Template_obj::expr_splitter->match(p))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",188)
		return ::haxe::_Template::TemplateExpr_obj::OpExpr(this->parseExpr(p));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",189)
	return ::haxe::_Template::TemplateExpr_obj::OpVar(p);
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,parse,return )

Dynamic Template_obj::parseExpr( ::String data){
	HX_SOURCE_PUSH("Template_obj::parseExpr")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",193)
	::List l = ::List_obj::__new();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",194)
	Array< ::String > expr = Array_obj< ::String >::__new().Add(data);
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",195)
	while((::haxe::Template_obj::expr_splitter->match(data))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",196)
		Dynamic p = ::haxe::Template_obj::expr_splitter->matchedPos();
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",197)
		int k = (p->__Field(HX_CSTRING("pos")) + p->__Field(HX_CSTRING("len")));
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",198)
		if (((p->__Field(HX_CSTRING("pos")) != (int)0))){
			struct _Function_3_1{
				inline static Dynamic Block( ::String &data,Dynamic &p){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("p") , data.substr((int)0,p->__Field(HX_CSTRING("pos"))),false);
					__result->Add(HX_CSTRING("s") , true,false);
					return __result;
				}
			};
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",199)
			l->add(_Function_3_1::Block(data,p));
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",200)
		::String p1 = ::haxe::Template_obj::expr_splitter->matched((int)0);
		struct _Function_2_1{
			inline static Dynamic Block( ::String &p1){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("p") , p1,false);
				__result->Add(HX_CSTRING("s") , (p1.indexOf(HX_CSTRING("\""),null()) >= (int)0),false);
				return __result;
			}
		};
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",201)
		l->add(_Function_2_1::Block(p1));
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",202)
		data = ::haxe::Template_obj::expr_splitter->matchedRight();
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",204)
	if (((data.length != (int)0))){
		struct _Function_2_1{
			inline static Dynamic Block( ::String &data){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("p") , data,false);
				__result->Add(HX_CSTRING("s") , true,false);
				return __result;
			}
		};
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",205)
		l->add(_Function_2_1::Block(data));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",206)
	Dynamic e = Dynamic( Array_obj<Dynamic>::__new());
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",207)
	try{
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",208)
		hx::IndexRef((e).mPtr,(int)0) = this->makeExpr(l);
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",209)
		if ((!(l->isEmpty()))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",210)
			hx::Throw (l->first()->__Field(HX_CSTRING("p")));
		}
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::String >() ){
			::String s = __e;{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",211)
				hx::Throw ((((HX_CSTRING("Unexpected '") + s) + HX_CSTRING("' in ")) + expr->__get((int)0)));
			}
		}
		else throw(__e);
	}

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Dynamic,e,Array< ::String >,expr)
	Dynamic run(){
{
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",214)
			try{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",215)
				return e->__GetItem((int)0)();
			}
			catch(Dynamic __e){
				{
					Dynamic exc = __e;{
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",217)
						hx::Throw ((((HX_CSTRING("Error : ") + ::Std_obj::string(exc)) + HX_CSTRING(" in ")) + expr->__get((int)0)));
					}
				}
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC0(return)

	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",214)
	return  Dynamic(new _Function_1_1(e,expr));
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,parseExpr,return )

Dynamic Template_obj::makeConst( ::String v){
	HX_SOURCE_PUSH("Template_obj::makeConst")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",223)
	Array< ::String > v1 = Array_obj< ::String >::__new().Add(v);
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",224)
	::haxe::Template_obj::expr_trim->match(v1->__get((int)0));
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",225)
	v1[(int)0] = ::haxe::Template_obj::expr_trim->matched((int)1);
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",226)
	if (((v1->__get((int)0).charCodeAt((int)0) == (int)34))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",227)
		Array< ::String > str = Array_obj< ::String >::__new().Add(v1->__get((int)0).substr((int)1,(v1->__get((int)0).length - (int)2)));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::String >,str)
		::String run(){
{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",228)
				return str->__get((int)0);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0(return)

		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",228)
		return  Dynamic(new _Function_2_1(str));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",230)
	if ((::haxe::Template_obj::expr_int->match(v1->__get((int)0)))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",231)
		Array< Dynamic > i = Array_obj< Dynamic >::__new().Add(::Std_obj::parseInt(v1->__get((int)0)));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< Dynamic >,i)
		Dynamic run(){
{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",232)
				return i->__get((int)0);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0(return)

		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",232)
		return  Dynamic(new _Function_2_1(i));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",234)
	if ((::haxe::Template_obj::expr_float->match(v1->__get((int)0)))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",235)
		Array< double > f = Array_obj< double >::__new().Add(::Std_obj::parseFloat(v1->__get((int)0)));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< double >,f)
		double run(){
{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",236)
				return f->__get((int)0);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0(return)

		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",236)
		return  Dynamic(new _Function_2_1(f));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",238)
	Array< ::haxe::Template > me = Array_obj< ::haxe::Template >::__new().Add(hx::ObjectPtr<OBJ_>(this));

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::haxe::Template >,me,Array< ::String >,v1)
	Dynamic run(){
{
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",239)
			return me->__get((int)0)->resolve(v1->__get((int)0));
		}
		return null();
	}
	HX_END_LOCAL_FUNC0(return)

	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",239)
	return  Dynamic(new _Function_1_1(me,v1));
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,makeConst,return )

Dynamic Template_obj::makePath( Dynamic e,::List l){
	HX_SOURCE_PUSH("Template_obj::makePath")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",242)
	Dynamic e1 = Dynamic( Array_obj<Dynamic>::__new().Add(e));
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",243)
	Dynamic p = l->first();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",244)
	if (((bool((p == null())) || bool((p->__Field(HX_CSTRING("p")) != HX_CSTRING(".")))))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",245)
		return e1->__GetItem((int)0);
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",246)
	l->pop();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",247)
	Dynamic field = l->pop();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",248)
	if (((bool((field == null())) || bool(!(field->__Field(HX_CSTRING("s"))))))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",249)
		hx::Throw (field->__Field(HX_CSTRING("p")));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",250)
	Array< ::String > f = Array_obj< ::String >::__new().Add(field->__Field(HX_CSTRING("p")));
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",251)
	::haxe::Template_obj::expr_trim->match(f->__get((int)0));
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",252)
	f[(int)0] = ::haxe::Template_obj::expr_trim->matched((int)1);

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Dynamic,e1,Array< ::String >,f)
	Dynamic run(){
{
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",253)
			return ::Reflect_obj::field(e1->__GetItem((int)0)(),f->__get((int)0));
		}
		return null();
	}
	HX_END_LOCAL_FUNC0(return)

	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",253)
	return this->makePath( Dynamic(new _Function_1_1(e1,f)),l);
}


HX_DEFINE_DYNAMIC_FUNC2(Template_obj,makePath,return )

Dynamic Template_obj::makeExpr( ::List l){
	HX_SOURCE_PUSH("Template_obj::makeExpr")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",256)
	return this->makePath(this->makeExpr2(l),l);
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,makeExpr,return )

Dynamic Template_obj::makeExpr2( ::List l){
	HX_SOURCE_PUSH("Template_obj::makeExpr2")
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",261)
	Dynamic p = l->pop();
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",262)
	if (((p == null()))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",263)
		hx::Throw (HX_CSTRING("<eof>"));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",264)
	if ((p->__Field(HX_CSTRING("s")))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",265)
		return this->makeConst(p->__Field(HX_CSTRING("p")));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",266)
	::String _switch_1 = (p->__Field(HX_CSTRING("p")));
	if (  ( _switch_1==HX_CSTRING("("))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",268)
		Dynamic e1 = Dynamic( Array_obj<Dynamic>::__new().Add(this->makeExpr(l)));
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",269)
		Dynamic p1 = l->pop();
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",270)
		if (((bool((p1 == null())) || bool(p1->__Field(HX_CSTRING("s")))))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",271)
			hx::Throw (p1->__Field(HX_CSTRING("p")));
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",272)
		if (((p1->__Field(HX_CSTRING("p")) == HX_CSTRING(")")))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",273)
			return e1->__GetItem((int)0);
		}
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",274)
		Dynamic e2 = Dynamic( Array_obj<Dynamic>::__new().Add(this->makeExpr(l)));
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",275)
		Dynamic p2 = l->pop();
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",276)
		if (((bool((p2 == null())) || bool((p2->__Field(HX_CSTRING("p")) != HX_CSTRING(")")))))){
			HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",277)
			hx::Throw (p2->__Field(HX_CSTRING("p")));
		}
		struct _Function_2_1{
			inline static Dynamic Block( Dynamic &p1,Dynamic &e2,Dynamic &e1){
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",278)
				::String _switch_2 = (p1->__Field(HX_CSTRING("p")));
				if (  ( _switch_2==HX_CSTRING("+"))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",279)
							return (e1->__GetItem((int)0)() + e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",279)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("-"))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",280)
							return (e1->__GetItem((int)0)() - e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",280)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("*"))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",281)
							return (e1->__GetItem((int)0)() * e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",281)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("/"))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",282)
							return (double(e1->__GetItem((int)0)()) / double(e2->__GetItem((int)0)()));
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",282)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING(">"))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",283)
							return (e1->__GetItem((int)0)() > e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",283)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("<"))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",284)
							return (e1->__GetItem((int)0)() < e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",284)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING(">="))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",285)
							return (e1->__GetItem((int)0)() >= e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",285)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("<="))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",286)
							return (e1->__GetItem((int)0)() <= e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",286)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("=="))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",287)
							return (e1->__GetItem((int)0)() == e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",287)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("!="))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",288)
							return (e1->__GetItem((int)0)() != e2->__GetItem((int)0)());
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",288)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("&&"))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",289)
							return (bool(e1->__GetItem((int)0)()) && bool(e2->__GetItem((int)0)()));
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",289)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else if (  ( _switch_2==HX_CSTRING("||"))){

					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Dynamic,e1,Dynamic,e2)
					Dynamic run(){
{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",290)
							return (bool(e1->__GetItem((int)0)()) || bool(e2->__GetItem((int)0)()));
						}
						return null();
					}
					HX_END_LOCAL_FUNC0(return)

					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",290)
					return  Dynamic(new _Function_4_1(e1,e2));
				}
				else  {
					HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",291)
					return hx::Throw ((HX_CSTRING("Unknown operation ") + p1->__Field(HX_CSTRING("p"))));
				}
;
;
			}
		};
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",278)
		return _Function_2_1::Block(p1,e2,e1);
	}
	else if (  ( _switch_1==HX_CSTRING("!"))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",294)
		Dynamic e = Dynamic( Array_obj<Dynamic>::__new().Add(this->makeExpr(l)));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,e)
		bool run(){
{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",296)
				Dynamic v = e->__GetItem((int)0)();
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",297)
				return (bool((v == null())) || bool((v == false)));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0(return)

		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",295)
		return  Dynamic(new _Function_2_1(e));
	}
	else if (  ( _switch_1==HX_CSTRING("-"))){
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",300)
		Dynamic e = Dynamic( Array_obj<Dynamic>::__new().Add(this->makeExpr(l)));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,e)
		double run(){
{
				HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",301)
				return -(e->__GetItem((int)0)());
			}
			return null();
		}
		HX_END_LOCAL_FUNC0(return)

		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",301)
		return  Dynamic(new _Function_2_1(e));
	}
	HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",303)
	hx::Throw (p->__Field(HX_CSTRING("p")));
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,makeExpr2,return )

Void Template_obj::run( ::haxe::_Template::TemplateExpr e){
{
		HX_SOURCE_PUSH("Template_obj::run")
		HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",306)
		{
::haxe::_Template::TemplateExpr _switch_3 = (e);
			switch((_switch_3)->GetIndex()){
				case 0: {
					::String v = _switch_3->__Param(0);
{
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",309)
						::StringBuf _this = this->buf;
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",309)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = ::Std_obj::string(this->resolve(v));
					}
				}
				;break;
				case 1: {
					Dynamic e1 = _switch_3->__Param(0);
{
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",311)
						::StringBuf _this = this->buf;
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",311)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = ::Std_obj::string(e1());
					}
				}
				;break;
				case 2: {
					::haxe::_Template::TemplateExpr eelse = _switch_3->__Param(2);
					::haxe::_Template::TemplateExpr eif = _switch_3->__Param(1);
					Dynamic e1 = _switch_3->__Param(0);
{
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",313)
						Dynamic v = e1();
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",314)
						if (((bool((v == null())) || bool((v == false))))){
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",314)
							if (((eelse != null()))){
								HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",315)
								this->run(eelse);
							}
						}
						else{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",317)
							this->run(eif);
						}
					}
				}
				;break;
				case 3: {
					::String str = _switch_3->__Param(0);
{
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",319)
						::StringBuf _this = this->buf;
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",319)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = str;
					}
				}
				;break;
				case 4: {
					::List l = _switch_3->__Param(0);
{
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",320)
						for(::cpp::FastIterator_obj< ::haxe::_Template::TemplateExpr > *__it = ::cpp::CreateFastIterator< ::haxe::_Template::TemplateExpr >(l->iterator());  __it->hasNext(); ){
							::haxe::_Template::TemplateExpr e1 = __it->next();
							this->run(e1);
						}
					}
				}
				;break;
				case 5: {
					::haxe::_Template::TemplateExpr loop = _switch_3->__Param(1);
					Dynamic e1 = _switch_3->__Param(0);
{
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",324)
						Dynamic v = e1();
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",325)
						try{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",325)
							if (((v->__Field(HX_CSTRING("hasNext")) == null()))){
								HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",327)
								Dynamic x = v->__Field(HX_CSTRING("iterator"))();
								HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",328)
								if (((x->__Field(HX_CSTRING("hasNext")) == null()))){
									HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",328)
									hx::Throw (null());
								}
								HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",329)
								v = x;
							}
						}
						catch(Dynamic __e){
							{
								Dynamic e2 = __e;{
									HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",331)
									hx::Throw ((HX_CSTRING("Cannot iter on ") + v));
								}
							}
						}
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",334)
						this->stack->push(this->context);
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",335)
						Dynamic v1 = v;
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",336)
						for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(v1);  __it->hasNext(); ){
							Dynamic ctx = __it->next();
							{
								HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",337)
								this->context = ctx;
								HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",338)
								this->run(loop);
							}
;
						}
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",340)
						this->context = this->stack->pop();
					}
				}
				;break;
				case 6: {
					::List params = _switch_3->__Param(1);
					::String m = _switch_3->__Param(0);
{
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",342)
						Dynamic v = ::Reflect_obj::field(this->macros,m);
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",343)
						Dynamic pl = Dynamic( Array_obj<Dynamic>::__new() );
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",344)
						::StringBuf old = this->buf;
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",345)
						pl->__Field(HX_CSTRING("push"))(this->resolve_dyn());
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",346)
						for(::cpp::FastIterator_obj< ::haxe::_Template::TemplateExpr > *__it = ::cpp::CreateFastIterator< ::haxe::_Template::TemplateExpr >(params->iterator());  __it->hasNext(); ){
							::haxe::_Template::TemplateExpr p = __it->next();
							{
								HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",346)
								{
::haxe::_Template::TemplateExpr _switch_4 = (p);
									switch((_switch_4)->GetIndex()){
										case 0: {
											::String v1 = _switch_4->__Param(0);
{
												HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",348)
												pl->__Field(HX_CSTRING("push"))(this->resolve(v1));
											}
										}
										;break;
										default: {
											HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",350)
											this->buf = ::StringBuf_obj::__new();
											HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",351)
											this->run(p);
											HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",352)
											pl->__Field(HX_CSTRING("push"))(this->buf->b->__Field(HX_CSTRING("join"))(HX_CSTRING("")));
										}
									}
								}
							}
;
						}
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",355)
						this->buf = old;
						HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",356)
						try{
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",357)
							::StringBuf _this = this->buf;
							HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",357)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = ::Std_obj::string(::Reflect_obj::callMethod(this->macros,v,pl));
						}
						catch(Dynamic __e){
							{
								Dynamic e1 = __e;{
									struct _Function_3_1{
										inline static ::String Block( Dynamic &pl){
											HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",359)
											try{
												HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",359)
												return pl->__Field(HX_CSTRING("join"))(HX_CSTRING(","));
											}
											catch(Dynamic __e){
												{
													Dynamic e2 = __e;{
														HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",359)
														return HX_CSTRING("???");
													}
												}
											}
										}
									};
									HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",359)
									::String plstr = _Function_3_1::Block(pl);
									HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",360)
									::String msg = ((((((HX_CSTRING("Macro call ") + m) + HX_CSTRING("(")) + plstr) + HX_CSTRING(") failed (")) + ::Std_obj::string(e1)) + HX_CSTRING(")"));
									HX_SOURCE_POS("H:\\Programy\\FDT\\haXe\\haxe-2.08-win\\std/haxe/Template.hx",364)
									hx::Throw (msg);
								}
							}
						}
					}
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Template_obj,run,(void))

::EReg Template_obj::splitter;

::EReg Template_obj::expr_splitter;

::EReg Template_obj::expr_trim;

::EReg Template_obj::expr_int;

::EReg Template_obj::expr_float;

Dynamic Template_obj::globals;


Template_obj::Template_obj()
{
}

void Template_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Template);
	HX_MARK_MEMBER_NAME(expr,"expr");
	HX_MARK_MEMBER_NAME(context,"context");
	HX_MARK_MEMBER_NAME(macros,"macros");
	HX_MARK_MEMBER_NAME(stack,"stack");
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_END_CLASS();
}

Dynamic Template_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"expr") ) { return expr; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stack") ) { return stack; }
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"macros") ) { return macros; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"globals") ) { return globals; }
		if (HX_FIELD_EQ(inName,"context") ) { return context; }
		if (HX_FIELD_EQ(inName,"execute") ) { return execute_dyn(); }
		if (HX_FIELD_EQ(inName,"resolve") ) { return resolve_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"splitter") ) { return splitter; }
		if (HX_FIELD_EQ(inName,"expr_int") ) { return expr_int; }
		if (HX_FIELD_EQ(inName,"makePath") ) { return makePath_dyn(); }
		if (HX_FIELD_EQ(inName,"makeExpr") ) { return makeExpr_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"expr_trim") ) { return expr_trim; }
		if (HX_FIELD_EQ(inName,"parseExpr") ) { return parseExpr_dyn(); }
		if (HX_FIELD_EQ(inName,"makeConst") ) { return makeConst_dyn(); }
		if (HX_FIELD_EQ(inName,"makeExpr2") ) { return makeExpr2_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"expr_float") ) { return expr_float; }
		if (HX_FIELD_EQ(inName,"parseBlock") ) { return parseBlock_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"parseTokens") ) { return parseTokens_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"expr_splitter") ) { return expr_splitter; }
	}
	return super::__Field(inName);
}

Dynamic Template_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::StringBuf >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"expr") ) { expr=inValue.Cast< ::haxe::_Template::TemplateExpr >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stack") ) { stack=inValue.Cast< ::List >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"macros") ) { macros=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"globals") ) { globals=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"context") ) { context=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"splitter") ) { splitter=inValue.Cast< ::EReg >(); return inValue; }
		if (HX_FIELD_EQ(inName,"expr_int") ) { expr_int=inValue.Cast< ::EReg >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"expr_trim") ) { expr_trim=inValue.Cast< ::EReg >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"expr_float") ) { expr_float=inValue.Cast< ::EReg >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"expr_splitter") ) { expr_splitter=inValue.Cast< ::EReg >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Template_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("expr"));
	outFields->push(HX_CSTRING("context"));
	outFields->push(HX_CSTRING("macros"));
	outFields->push(HX_CSTRING("stack"));
	outFields->push(HX_CSTRING("buf"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("splitter"),
	HX_CSTRING("expr_splitter"),
	HX_CSTRING("expr_trim"),
	HX_CSTRING("expr_int"),
	HX_CSTRING("expr_float"),
	HX_CSTRING("globals"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("expr"),
	HX_CSTRING("context"),
	HX_CSTRING("macros"),
	HX_CSTRING("stack"),
	HX_CSTRING("buf"),
	HX_CSTRING("execute"),
	HX_CSTRING("resolve"),
	HX_CSTRING("parseTokens"),
	HX_CSTRING("parseBlock"),
	HX_CSTRING("parse"),
	HX_CSTRING("parseExpr"),
	HX_CSTRING("makeConst"),
	HX_CSTRING("makePath"),
	HX_CSTRING("makeExpr"),
	HX_CSTRING("makeExpr2"),
	HX_CSTRING("run"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Template_obj::splitter,"splitter");
	HX_MARK_MEMBER_NAME(Template_obj::expr_splitter,"expr_splitter");
	HX_MARK_MEMBER_NAME(Template_obj::expr_trim,"expr_trim");
	HX_MARK_MEMBER_NAME(Template_obj::expr_int,"expr_int");
	HX_MARK_MEMBER_NAME(Template_obj::expr_float,"expr_float");
	HX_MARK_MEMBER_NAME(Template_obj::globals,"globals");
};

Class Template_obj::__mClass;

void Template_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Template"), hx::TCanCast< Template_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Template_obj::__boot()
{
	hx::Static(splitter) = ::EReg_obj::__new(HX_CSTRING("(::[A-Za-z0-9_ ()&|!+=/><*.\"-]+::|\\$\\$([A-Za-z0-9_-]+)\\()"),HX_CSTRING(""));
	hx::Static(expr_splitter) = ::EReg_obj::__new(HX_CSTRING("(\\(|\\)|[ \r\n\t]*\"[^\"]*\"[ \r\n\t]*|[!+=/><*.&|-]+)"),HX_CSTRING(""));
	hx::Static(expr_trim) = ::EReg_obj::__new(HX_CSTRING("^[ ]*([^ ]+)[ ]*$"),HX_CSTRING(""));
	hx::Static(expr_int) = ::EReg_obj::__new(HX_CSTRING("^[0-9]+$"),HX_CSTRING(""));
	hx::Static(expr_float) = ::EReg_obj::__new(HX_CSTRING("^([+-]?)(?=\\d|,\\d)\\d*(,\\d*)?([Ee]([+-]?\\d+))?$"),HX_CSTRING(""));
struct _Function_0_1{
	inline static Dynamic Block( ){
		hx::Anon __result = hx::Anon_obj::Create();
		return __result;
	}
};
	hx::Static(globals) = _Function_0_1::Block();
}

} // end namespace haxe
