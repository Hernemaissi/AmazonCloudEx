/*
 ============================================================================
 Name        : time_loop.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int main(void) {
	int i = 0;
	int results[1000000];
	int micros[1000000];
	struct timeval tim;
	for (; i<1000000; i++) {
		gettimeofday(&tim, NULL);
		results[i] = tim.tv_sec;
		micros[i] = tim.tv_usec;
	}

	FILE *file;
	file = fopen("time_results.txt","a+");
	for (i = 0; i < 1000000; i++) {
		fprintf(file, "%i,%i\n", results[i], micros[i]);
	}
	fclose(file);
	exit(0);
}
