#include <stdio.h>
#include <time.h>

int main()
	{
	int i=0;
	int array[100000];
	clock_t startTime, duration;

	startTime = clock();

	for(i=0; i<100000; i++)
		array[i] = i;

	duration = clock() - startTime;
	printf("Time: %f\n", ((float) duration) / CLOCKS_PER_SEC);

	}
