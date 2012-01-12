#ifndef INCLUDED_examples_api_ArrayExamples
#define INCLUDED_examples_api_ArrayExamples

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(examples,api,ArrayExamples)
namespace examples{
namespace api{


class ArrayExamples_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ArrayExamples_obj OBJ_;
		ArrayExamples_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ArrayExamples_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ArrayExamples_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ArrayExamples"); }

		static Void example_new( );
		static Dynamic example_new_dyn();

		static Void example_length( );
		static Dynamic example_length_dyn();

		static Void example_concat( );
		static Dynamic example_concat_dyn();

		static Void example_copy( );
		static Dynamic example_copy_dyn();

		static Void example_insert( );
		static Dynamic example_insert_dyn();

		static Void example_iterator( );
		static Dynamic example_iterator_dyn();

		static Void example_join( );
		static Dynamic example_join_dyn();

		static Void example_pop( );
		static Dynamic example_pop_dyn();

		static Void example_push( );
		static Dynamic example_push_dyn();

		static Void example_remove( );
		static Dynamic example_remove_dyn();

		static Void example_reverse( );
		static Dynamic example_reverse_dyn();

		static Void example_shift( );
		static Dynamic example_shift_dyn();

		static Void example_slice( );
		static Dynamic example_slice_dyn();

		static Void example_sort( );
		static Dynamic example_sort_dyn();

		static Void example_splice( );
		static Dynamic example_splice_dyn();

		static Void example_unshift( );
		static Dynamic example_unshift_dyn();

		static Void show_usage_example( );
		static Dynamic show_usage_example_dyn();

};

} // end namespace examples
} // end namespace api

#endif /* INCLUDED_examples_api_ArrayExamples */ 
