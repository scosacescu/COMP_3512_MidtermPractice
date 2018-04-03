#include <cassert>
//#define NDEBUG

class AssertEx {
private:
	int result;
public:
	//let's pretend our sum has to be above zero for whatever reason
	int sum(int a, int b) {
		result = a + b;
		assert(result > 0);
		return result;
	}

};