#include <iostream>
using namespace std;
/*	Casting in C++
		We have new casting operators

		c = typeof_cast<TYPENAME*>(a);

		Don't use C-style casting, instead select the operator best suited too your needs
		Document the intended reason, and let the compiler help you
		
		This will provide you with safer, better documented casts
*/

/*
	1) dynamic_cast
			Pointer of one type to pointer of another type, within hierarchy
			Allowed with pointers/references to polymorphic types
			Compiler will catch errors based on runtime type
				Will throw bad_cast otherwise

			We can say that the real purpose of dynamic_cast is to allow upcasts within
			an inheritance hierarchy

			But dynamic_cast can also downcast (convert from pointer-to-base to pointer-to-derived) 
			polymorphic classes (those with virtual members) if -and only if- the pointed object is 
			a valid complete object of the target type.

	2) const_cast
			Use this to cast AWAY the const qualifier
			This is assured to be safe ONLY IF the data to which the pointer points was
			not declcared as const of volatile when first declared
			
	3) static_cast
			Pointer of one class type to a pointer of another WITHIN hierarchy
			Avoid runtime checks done in dynamic_cast
			Can use with nonpolymorphic types
			ONLY VALID id pre-cast type and post-cast type can be implicitly converted
			to one another in 1 or both directions
				ie can perform similar to C-style casts

	4) reinerpret_cast
			For inherently risky type casts - won't let us cast away const
*/

class Base { virtual void dummy() {} };
class Derived : public Base { int a; };

int main() {
	int a{ 7 };
	
	double b = static_cast<double>(a);
	cout << b << endl;

	Base * pba = new Derived;
	Base * pbb = new Base;
	Derived * pd;

	pd = dynamic_cast<Derived*>(pba);


	system("pause");
}