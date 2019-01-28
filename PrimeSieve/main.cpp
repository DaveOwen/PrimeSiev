//Written by: David Owen

#include <iostream>
#include <math.h>
#include <cstring>
#include <ctime>
#include <chrono>
#include <ratio>

#define RUNS 1000				// How many times the code will run. This is used to obtain a more accurate timing.
#define RANGE 100000 		// What number of primes to search up to
#define R2 RANGE/2

using namespace std::chrono;
int main()
{
	//Set up varibles
	int count;
	char primes[RANGE];
	int searchRange = sqrt(R2) + 1;

	//############################ SIEV #################################
	high_resolution_clock::time_point startTime = high_resolution_clock::now();

	for (int k = 0; k < RUNS; ++k)
	{
		count = 0;
		memset(primes, 0, R2);
		for (int i = 0; i < searchRange; ++i)
		{
			if (primes[i] == 0)
			{
				for (int j = (i << 1)*i + (i << 2) + (i << 1) + 3; j < R2; j += i * 4 + 6)
				{
					primes[j] = 1;
					primes[j + i * 2 + 3] = 1;
				}
			}
		}
	}
	high_resolution_clock::time_point endTime = high_resolution_clock::now();
	for (int i = 0; i < R2; i++) if (primes[i] == 0) count++;

	duration<double> time_span = duration_cast<duration<double>>((endTime - startTime) / (1000 * RUNS));
	//#####################################################################



	//####################  OUTPUT TIME AND PRIMES  ######################
	std::cout << "Optimised Sieve Time:  " << time_span.count() << std::endl;
	std::cout << "\nPrimes Found:  " << count + 1 << std::endl;
	//#####################################################################
	return 0;
}
