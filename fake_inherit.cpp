#include <type_traits>

#define __STATIC_INTERFACE /* This is compile-time interface */

#ifdef INSPECT_STATIC_INTERFACE
#define __FAKE_INHERIT(static_interface) \
	: public static_interface
#else
#define __FAKE_INHERIT(static_interface)
#endif

#define __INSPECT_STATIC_INTERFACE(class_name) \
	static_assert(std::is_abstract<class_name>::value == false, \
		#class_name" doesn't meet static interface.");

__STATIC_INTERFACE class Bird
{
	virtual void fly() = 0;
};

class SuccessClass __FAKE_INHERIT(Bird)
{
	void fly() {};
};
__INSPECT_STATIC_INTERFACE(SuccessClass)

class FailClass __FAKE_INHERIT(Bird)
{
//	void fly() {};
};
__INSPECT_STATIC_INTERFACE(FailClass)

int main()
{
}
