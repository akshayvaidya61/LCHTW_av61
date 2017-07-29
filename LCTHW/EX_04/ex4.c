#include <stdio.h>

void makeBadFunction() {
	char *ptr = NULL;
	int i = 0;
	for(i = 0; i < 100000; i++) {
		printf("%c",ptr[i]);
	}
}

int main() {
	makeBadFunction();
	makeBadFunction();
	makeBadFunction();
	makeBadFunction();
	makeBadFunction();
	return 0;
}
