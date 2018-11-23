#include <stdio.h>
#include "santa.h"

int main()
{
	unsigned int tour[ncities+1];
	tour[0] = tour[ncities] = 0;

	for(int i=1; i<=ncities-1; i++)
		tour[i] = i;

    printf("Total distance = %lf\n", totaldistance(tour, ncities+1));
}
