#ifndef INCLUDED_examples_templates_Templates
#define INCLUDED_examples_templates_Templates

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(examples,templates,Templates)
namespace examples{
namespace templates{


class Templates_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Templates_obj OBJ_;
		Templates_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Templates_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Templates_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Templates"); }

		virtual ::String example_variables( );
		Dynamic example_variables_dyn();

		virtual ::String example_fields( );
		Dynamic example_fields_dyn();

		virtual ::String example_if( );
		Dynamic example_if_dyn();

		virtual ::String example_for( );
		Dynamic example_for_dyn();

		virtual ::String example_makro( );
		Dynamic example_makro_dyn();

		virtual ::String makroFunction( Dynamic resolve,int age);
		Dynamic makroFunction_dyn();

		virtual ::String example_globals( );
		Dynamic example_globals_dyn();

};

} // end namespace examples
} // end namespace templates

#endif /* INCLUDED_examples_templates_Templates */ 
