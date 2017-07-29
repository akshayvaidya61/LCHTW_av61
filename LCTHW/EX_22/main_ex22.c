#include <stdio.h>
#include <stdlib.h>
#include "ex22.h"
#include "dbg.h"
#include <time.h>

int main(int argc, char *argv[]) {
	time_t t;
	srand((unsigned) time(&t));
	printf("%d\n",rand()%10000);
	return 0;
	
}