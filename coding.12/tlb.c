#define _GNU_SOURCE 
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sched.h>

int main(int numpages, int numtrials) {
	int pagesize = getpagesize(); //this function gets us the page size in bytes
	int jump = pagesize / sizeof(int);
	
	struct timespec start;
	struct timespec end;

	int *arrayy = (int*)calloc(numpages*pagesize, sizeof(int));
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i=0;i<numpages*jump;i+=jump) {
		arrayy[i] += 1;
		int temp = a[i];
	}
	clock_gettime(CLOCK_MONOTONIC, &end);

	long time_taken = (end.tv_sec - start.tv_sec);
	time_taken = (time_taken + (end.tv_nsec - start.tv_nsec));

	long loops = numtrials * numpages;
	
	return (long) time_taken / (long) loops;
}

