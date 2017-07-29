#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// forward declaration
int can_print_it(char);
void print_letters(char[]);

void print_arguments(int argc, char *argv[]) {
	int i = 0;
	for(i = 1; i <= argc-1; i++) {
		print_letters(argv[i]);
	}
}

void print_letters(char arg[]) {
	int i = 0;
	for(i = 0 ; arg[i] != '\0'; i++) {
		char ch = arg[i];
		if(can_print_it(ch)) {
			printf("'%c' == %d ",ch, ch);
		}
	}
	printf("\n");
}

int can_print_it(char ch) {
	return(isalpha(ch) || isblank(ch));
}

int main(int argc, char *argv[]) {
	print_arguments(argc, argv);
	printf("end\n");
	return 0;
}