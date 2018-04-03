#include "Exceptions.cpp"
#include "AssertEx.cpp"

//This Project plays around with exceptions in C++ as well
//as providing some basic notes and guidelines

/* C++ lets us throw anything as exceptions:
	strings, numbers, user types, exceptions from standard library
	best to define exception types or use std
*/

/*	Two approaches to error handling in C++:
		1) Assertions
		2) Exceptions
*/

/*	Assertions: 
		#include <cassert>
		#define NDEBUG // to turn off. otherwise, program will TERMINATE if false

		see assertex.cpp
*/

/*	Guidelines:
		Throw exception types (like a struct) or standard library exceptions
		Use a try catch block in your main
			//catch(...) to catch ANYTHING
		Catch by reference - catch (exception_type& ex) {...}
		When an exception is thrown, caught by the first matching catch block
			So use the catch (...) LAST
		Consider catching the exception, providing an error message, terminating
*/

/*	noexcept:
		qualifies will specify that no exceptions can be thrown out of a function
		Benefits:
			main() or calling code don't need to check for /catch exceptions
			if an exception gets thrown somehow, program will just end
*/

/*	Standard Exceptions
		#include <exception>
		
		std::exception is a base class intended to be derived:
			Includes a virtual member function called "what" that returns 
			a null terminades char sequence (*char)
			
			Override this to deliver a meaningful exception message

		struct myexception:pubic exception{
			virtual const char* what() const noexcept {
				return "My exception happened";
			}
		}
*/

/*
	Derived from std::Exception
		bad_alloc				thrown by new on allocation failure
		bad_cast				thrown by dynamic_cast on failure
		bad_exception			thrown by certain dynamic exception specifiers
		bad_typeid				thrown by typeid
		bad_function_call		thrown by empty function objects
		bad_weak_ptr			thrown by share_ptr when passed a bad weak_ptr
*/

/*	USEFUL exceptions
		Two types, can be inherited by your custom exceptions to report errors
		1) logic_error
				invalid_argument
				length_error
				out_of_range
		2) runtime_error
				range_error
				overflow_error
*/

/*
	
*/


int main() {

	try {
		Exceptions invalidexample("");
	} 
	/*catch (invalid_argument& e) 
	{
		cout << "Please specify a valid first name" << endl;
	}*/
	catch (logic_error& e) {
		cout << "General logic_error found" << endl;
	}
	catch(runtime_error& e){
		cout << "General runtime error found" << endl;
	}
	catch (...) 
	{
		cout << "General exception caught" << endl;
	}


	AssertEx ax;
	ax.sum(0, 1);

	system("pause");
}