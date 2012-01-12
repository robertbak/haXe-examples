#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_examples_api_ArrayExamples
#include <examples/api/ArrayExamples.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace examples{
namespace api{

Void ArrayExamples_obj::__construct()
{
	return null();
}

ArrayExamples_obj::~ArrayExamples_obj() { }

Dynamic ArrayExamples_obj::__CreateEmpty() { return  new ArrayExamples_obj; }
hx::ObjectPtr< ArrayExamples_obj > ArrayExamples_obj::__new()
{  hx::ObjectPtr< ArrayExamples_obj > result = new ArrayExamples_obj();
	result->__construct();
	return result;}

Dynamic ArrayExamples_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArrayExamples_obj > result = new ArrayExamples_obj();
	result->__construct();
	return result;}

Void ArrayExamples_obj::example_new( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_new")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",6)
		Array< int > a1 = Array_obj< int >::__new();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",7)
		Array< ::String > a2 = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",9)
		Array< ::String > a3 = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_new,(void))

Void ArrayExamples_obj::example_length( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_length")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",13)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",14)
		::haxe::Log_obj::trace(a->length,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),14,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_length")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_length,(void))

Void ArrayExamples_obj::example_concat( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_concat")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",19)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",20)
		Array< ::String > b = Array_obj< ::String >::__new().Add(HX_CSTRING("apple")).Add(HX_CSTRING("pear"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",21)
		Array< ::String > c = a->concat(b);
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",22)
		::haxe::Log_obj::trace(c,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),22,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_concat")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",24)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),24,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_concat")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_concat,(void))

Void ArrayExamples_obj::example_copy( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_copy")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",29)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",30)
		Array< ::String > c = a->copy();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",31)
		::haxe::Log_obj::trace(c,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),31,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_copy")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",35)
		Array< ::StringBuf > a1 = Array_obj< ::StringBuf >::__new();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",36)
		::StringBuf sb = ::StringBuf_obj::__new();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",37)
		hx::IndexRef((sb->b).mPtr,sb->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("firstpart");
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",38)
		a1->push(sb);
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",39)
		Array< ::StringBuf > c1 = a1->copy();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",40)
		::haxe::Log_obj::trace(c1,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),40,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_copy")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",42)
		{
			HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",42)
			::StringBuf _this = a1->__get((int)0);
			HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",42)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("secondpart");
		}
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",43)
		::haxe::Log_obj::trace(c1,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),43,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_copy")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_copy,(void))

Void ArrayExamples_obj::example_insert( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_insert")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",48)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",49)
		a->insert((int)0,HX_CSTRING("NEW"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",50)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),50,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_insert")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",52)
		a->insert((int)50,HX_CSTRING("too far"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",53)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),53,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_insert")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_insert,(void))

Void ArrayExamples_obj::example_iterator( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_iterator")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_iterator,(void))

Void ArrayExamples_obj::example_join( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_join")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",62)
		Array< int > a = Array_obj< int >::__new().Add((int)1).Add((int)2).Add((int)3);
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",63)
		::String result = a->join(HX_CSTRING("-"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",64)
		::haxe::Log_obj::trace(result,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),64,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_join")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_join,(void))

Void ArrayExamples_obj::example_pop( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_pop")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",69)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",70)
		::haxe::Log_obj::trace(a->pop(),hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),70,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_pop")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",72)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),72,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_pop")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_pop,(void))

Void ArrayExamples_obj::example_push( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_push")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",77)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",78)
		::haxe::Log_obj::trace(a->push(HX_CSTRING("four")),hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),78,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_push")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",80)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),80,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_push")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_push,(void))

Void ArrayExamples_obj::example_remove( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_remove")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",85)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("one"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",86)
		::haxe::Log_obj::trace(a->remove(HX_CSTRING("one")),hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),86,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_remove")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",88)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),88,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_remove")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",90)
		::haxe::Log_obj::trace(a->remove(HX_CSTRING("zebra")),hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),90,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_remove")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_remove,(void))

Void ArrayExamples_obj::example_reverse( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_reverse")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",95)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",96)
		a->reverse();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",97)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),97,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_reverse")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_reverse,(void))

Void ArrayExamples_obj::example_shift( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_shift")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",102)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",103)
		::haxe::Log_obj::trace(a->shift(),hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),103,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_shift")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",105)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),105,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_shift")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_shift,(void))

Void ArrayExamples_obj::example_slice( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_slice")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",110)
		Array< int > a = Array_obj< int >::__new().Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)5).Add((int)6).Add((int)7).Add((int)8).Add((int)9);
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",111)
		::haxe::Log_obj::trace(a->slice((int)3,(int)5),hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),111,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_slice")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",114)
		a = Array_obj< int >::__new().Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)5).Add((int)6).Add((int)7).Add((int)8).Add((int)9);
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",115)
		::haxe::Log_obj::trace(a->slice((int)3,(int)-1),hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),115,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_slice")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_slice,(void))

Void ArrayExamples_obj::example_sort( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_sort")

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		int run(int x,int y){
{
				HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",124)
				if (((x > y))){
					HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",124)
					return (int)-1;
				}
				else{
					HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",127)
					if (((x < y))){
						HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",127)
						return (int)1;
					}
				}
				HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",130)
				return (int)0;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",121)
		Dynamic sort_function =  Dynamic(new _Function_1_1());
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",133)
		Array< int > a = Array_obj< int >::__new().Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)5).Add((int)6).Add((int)7).Add((int)8).Add((int)9);
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",134)
		a->sort(sort_function);
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",135)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),135,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_sort")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_sort,(void))

Void ArrayExamples_obj::example_splice( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_splice")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",140)
		Array< int > a = Array_obj< int >::__new().Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)5).Add((int)6).Add((int)7).Add((int)8).Add((int)9);
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",141)
		::haxe::Log_obj::trace(a->splice((int)3,(int)5),hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),141,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_splice")));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",143)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),143,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_splice")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_splice,(void))

Void ArrayExamples_obj::example_unshift( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::example_unshift")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",148)
		Array< ::String > a = Array_obj< ::String >::__new().Add(HX_CSTRING("one")).Add(HX_CSTRING("two")).Add(HX_CSTRING("three"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",149)
		a->unshift(HX_CSTRING("zero"));
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",150)
		::haxe::Log_obj::trace(a,hx::SourceInfo(HX_CSTRING("ArrayExamples.hx"),150,HX_CSTRING("examples.api.ArrayExamples"),HX_CSTRING("example_unshift")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,example_unshift,(void))

Void ArrayExamples_obj::show_usage_example( ){
{
		HX_SOURCE_PUSH("ArrayExamples_obj::show_usage_example")
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",155)
		::examples::api::ArrayExamples_obj::example_new();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",156)
		::examples::api::ArrayExamples_obj::example_length();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",157)
		::examples::api::ArrayExamples_obj::example_sort();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",158)
		::examples::api::ArrayExamples_obj::example_concat();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",159)
		::examples::api::ArrayExamples_obj::example_copy();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",160)
		::examples::api::ArrayExamples_obj::example_insert();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",161)
		::examples::api::ArrayExamples_obj::example_iterator();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",162)
		::examples::api::ArrayExamples_obj::example_join();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",163)
		::examples::api::ArrayExamples_obj::example_pop();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",164)
		::examples::api::ArrayExamples_obj::example_push();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",165)
		::examples::api::ArrayExamples_obj::example_remove();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",166)
		::examples::api::ArrayExamples_obj::example_reverse();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",167)
		::examples::api::ArrayExamples_obj::example_shift();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",168)
		::examples::api::ArrayExamples_obj::example_slice();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",169)
		::examples::api::ArrayExamples_obj::example_sort();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",170)
		::examples::api::ArrayExamples_obj::example_splice();
		HX_SOURCE_POS("H:/ImaginaryDOT/Learning/haXeFDTWorkspace/haXe_examples/src/examples/api/ArrayExamples.hx",171)
		::examples::api::ArrayExamples_obj::example_unshift();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ArrayExamples_obj,show_usage_example,(void))


ArrayExamples_obj::ArrayExamples_obj()
{
}

void ArrayExamples_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ArrayExamples);
	HX_MARK_END_CLASS();
}

Dynamic ArrayExamples_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"example_new") ) { return example_new_dyn(); }
		if (HX_FIELD_EQ(inName,"example_pop") ) { return example_pop_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"example_copy") ) { return example_copy_dyn(); }
		if (HX_FIELD_EQ(inName,"example_join") ) { return example_join_dyn(); }
		if (HX_FIELD_EQ(inName,"example_push") ) { return example_push_dyn(); }
		if (HX_FIELD_EQ(inName,"example_sort") ) { return example_sort_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"example_shift") ) { return example_shift_dyn(); }
		if (HX_FIELD_EQ(inName,"example_slice") ) { return example_slice_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"example_length") ) { return example_length_dyn(); }
		if (HX_FIELD_EQ(inName,"example_concat") ) { return example_concat_dyn(); }
		if (HX_FIELD_EQ(inName,"example_insert") ) { return example_insert_dyn(); }
		if (HX_FIELD_EQ(inName,"example_remove") ) { return example_remove_dyn(); }
		if (HX_FIELD_EQ(inName,"example_splice") ) { return example_splice_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"example_reverse") ) { return example_reverse_dyn(); }
		if (HX_FIELD_EQ(inName,"example_unshift") ) { return example_unshift_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"example_iterator") ) { return example_iterator_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"show_usage_example") ) { return show_usage_example_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ArrayExamples_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ArrayExamples_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("example_new"),
	HX_CSTRING("example_length"),
	HX_CSTRING("example_concat"),
	HX_CSTRING("example_copy"),
	HX_CSTRING("example_insert"),
	HX_CSTRING("example_iterator"),
	HX_CSTRING("example_join"),
	HX_CSTRING("example_pop"),
	HX_CSTRING("example_push"),
	HX_CSTRING("example_remove"),
	HX_CSTRING("example_reverse"),
	HX_CSTRING("example_shift"),
	HX_CSTRING("example_slice"),
	HX_CSTRING("example_sort"),
	HX_CSTRING("example_splice"),
	HX_CSTRING("example_unshift"),
	HX_CSTRING("show_usage_example"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ArrayExamples_obj::__mClass;

void ArrayExamples_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("examples.api.ArrayExamples"), hx::TCanCast< ArrayExamples_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ArrayExamples_obj::__boot()
{
}

} // end namespace examples
} // end namespace api
