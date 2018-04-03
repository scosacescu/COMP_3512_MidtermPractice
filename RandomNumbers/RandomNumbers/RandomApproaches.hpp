#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <random>

// like a util library of various random number generation approaches
namespace randomAlgos {
	using namespace std;

	//Method 1: We can generate randos using rand and srand from Cstdlib
	inline int oldeTymeCApproach() {
		int upperbound{ 100 };
		//inits the random number generator and accepts seed parameter as current time
		srand(time(NULL));
		//rand returns a pseudo-random integer between 0 and RAND_MAX
		int my_int = rand() % upperbound;
		cout << "my_int: "<< my_int << endl;
		double zero_to_one = rand() / (double)RAND_MAX;
		cout << "zero_to_one " << zero_to_one << endl;

		int my_second_int = rand() % upperbound;
		cout << my_second_int << endl;

		cout << "now print out 10 random values" << endl;
		for (int i = 0; i < 10; i++) {
			int my_second_int = rand() % upperbound;
			cout << my_second_int << endl;
		}
		return my_int;
	}

	//use uniform real distribution to create a distribution over the closed interval 
	//[a,b) (including, not including) 
	inline double uniDistDouble(double min, double max) {
		default_random_engine generator(time(0));
		uniform_real_distribution<double> distribution(min, max);
		double my_random_double{ 0.0 };

		for (int i = 0; i < 10; i++)
		{
			my_random_double = distribution(generator);
			cout << "Uniform real distribution: " << my_random_double << endl;
		}
		return my_random_double;
	}

	inline int uniDistInt(int min, int max) {
		random_device rd;
		mt19937 generator(rd());
		uniform_int_distribution<> distribution(min, max);
		int my_int{ 0 };

		for (int i = 0; i < 10; i++) {
			my_int = distribution(generator);
			cout << "Uniform int distribution using marsenne twister: " << my_int << endl;
		}

		return my_int;

	}

}