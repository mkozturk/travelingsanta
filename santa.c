#include <math.h>
#include "santa.h"
// Binary search: Used to determine if a given CityId is among the primes
int binarySearch(unsigned int arr[], int l, int r, unsigned int x) 
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

double totaldistance(unsigned int path[], int pathlen)
// path[] is a permutation of CityIds; pathlen is the number of elements in path[]
// User must ensure that path[0] == path[pathlen-1] == 0
// pathlen == number of cities + 1 
{
	float dx, dy;
	double total=0;
	int step=1;
	
	while (step < pathlen){
		dx = (x[path[step]]-x[path[step-1]]);
		dy = (y[path[step]]-y[path[step-1]]);
		// Every 10th step is 10% more lengthy unless coming from a prime CityId.
		if (step %10 == 0 && binarySearch(primeids,0,nprimes-1, path[step-1]) == -1)
			total += 1.1 * sqrt(dx*dx + dy*dy);
		else
			total += sqrt(dx*dx + dy*dy);

		step++;
	}
	return total;
}
