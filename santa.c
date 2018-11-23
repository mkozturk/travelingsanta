#include <math.h>
#include "santa.h"
// Binary search: Used to determine if a given CityId is among the primes
int binarySearch(unsigned int arr[], int l, int r, int x) 
{ 
    while (l <= r) 
    { 
        int m = l + (r-l)/2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} 

double totaldistance(unsigned int tour[], int tourlen)
// tour[] is a permutation of CityIds; tourlen is the number of elements in tour[]
// User must ensure that tour[0] == tour[tourlen-1] == 0
// tourlen == number of cities + 1 
{
	float dx, dy;
	double total=0;
	int step=1;
	
	while (step < tourlen){
		dx = (x[tour[step]]-x[tour[step-1]]);
		dy = (y[tour[step]]-y[tour[step-1]]);
		// Every 10th step is 10% more lengthy unless coming from a prime CityId.
		if (step %10 == 0 && binarySearch(primeids,0,nprimes-1, tour[step-1]) == -1)
			total += 1.1 * sqrt(dx*dx + dy*dy);
		else
			total += sqrt(dx*dx + dy*dy);
/*		printf("step %d, %d (%.2f %.2f) --> %d (%.2f %.2f), total = %.3f\n",
				step, tour[step-1], x[tour[step-1]],y[tour[step-1]], 
				tour[step], x[tour[step]],y[tour[step]],
				total); 
				*/

		step++;
	}
	return total;
}
