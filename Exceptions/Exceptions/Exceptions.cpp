#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
using std::exception;

class Exceptions {
private:
	std::string firstname;
public:
	Exceptions(string first) : firstname(first) 
	{
		if (first.length() == 0) {
			throw std::invalid_argument("No first name!");
		}
	}

	~Exceptions() 
	{
		//NEVER throw an exception from a destructor
		//They are implicity qualified "noexcept"
	}
};