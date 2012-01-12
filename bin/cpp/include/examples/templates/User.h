#ifndef INCLUDED_examples_templates_User
#define INCLUDED_examples_templates_User

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(examples,templates,User)
namespace examples{
namespace templates{


class User_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef User_obj OBJ_;
		User_obj();
		Void __construct(::String firstName,::String lastName,int age);

	public:
		static hx::ObjectPtr< User_obj > __new(::String firstName,::String lastName,int age);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~User_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("User"); }

		::String firstName; /* REM */ 
		::String lastName; /* REM */ 
		int age; /* REM */ 
};

} // end namespace examples
} // end namespace templates

#endif /* INCLUDED_examples_templates_User */ 
