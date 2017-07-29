/* Pointers to function
*  The program demonstrates use of pointers to a function
*  Author: Akshay Vaidya
*
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Exit function for catching faults
void die(const char *message) {
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n",message);
	}
	exit(1);
}

// typedef creates a fake type, in this case for a function pointer
typedef int (*compare_cb) (int a, int b);


// A classic bubble sort function using compare_cb to do sorting
int *bubble_sort(int *numbers, int count, compare_cb cmp) {
	int temp = 0;
	
	int *target = malloc(count * sizeof(int));
	if(!target) die("Memory Error");
	
	memcpy(target,numbers,count*sizeof(int));
	
	for(int i = 0; i < count; i++) {
		for(int j = 0; j < count - 1; j++) {
			if(cmp(target[j],target[j+1]) > 0) {
				temp = target[j];
				target[j] = target[j+1];
				target[j+1] = temp;	
			}
		}
	}
	return target;
}

int sorted_order(int a, int b) {
	return a - b;
}

int reverse_order(int a, int b) {
	return b - a;
}

// Function to test that we are sorting correctly
void testSorting(int *numbers, int count, compare_cb cmp) {
	int *sorted = bubble_sort(numbers, count, cmp);
	
	if(!sorted) die("Failed to sort as requested");
	unsigned char *data = (unsigned char *) cmp;
	for(int i = 0; i < 25; i++) {
		printf("%02x:", data[i]);
		data[i] = i;
	}
	printf("\n");
	free(sorted);
}


int main(int argc, char *argv[]) {
	if(argc < 2) die("USAGE: ex18 28 1 29 12 43");
	int count = argc - 1;
	
	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory Error!");
	
	char **inputs = argv + 1;
	for(int i = 0; i < count;  i++) {
		numbers[i] = atoi(inputs[i]);
		printf("%d ",numbers[i]);
	}
	printf("\n");
	
	testSorting(numbers, count, sorted_order);
	testSorting(numbers, count, reverse_order);
	free(numbers);
   return 0; 
}