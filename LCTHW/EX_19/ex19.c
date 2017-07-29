#include "dbg.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void test_debug() {
	debug("Dhungan don in action");
	debug("Dhungan no. %d", 9211);
}

void test_log_err() {
	log_err("Everything is going wrong here");
	log_err("Mistake no %d made",3);
}

void test_log_warn() {
	log_warn("Ignore this one");
}

void test_log_info() {
	log_info("Did some mundane stuff");
}

int test_check(char *filename) {
	FILE *input = NULL;

	char *block = NULL;
	block = malloc(100);
	check_mem(block);

	input  = fopen(filename, "r");
	check(input, "Failed to open %s", filename);
	
	free(block);
	fclose(input);
	return 0;
	
	error:
		if(block) free(block);
		if(input) fclose(input);
		return -1;
}

int test_sentinel(int code) {
	char *temp = malloc(100);
	check_mem(temp);
	
	switch(code) {
	
	case 1:
		log_info("This worked");	
		break;
	
	default:
		sentinel("I should not run");
	}
	free(temp);
	return 0;
	
	error:
		if(temp) {
			free(temp);
		}
		return -1;
}

int test_check_mem() {
	char *test = NULL;
	check_mem(test);
	
	free(test);
	return 1;
	error:
		return -1;
}

int test_check_debug() {
	int i = 0;
	check_debug(i != 0, "Oops i was 0");
	
	return 1;
	
	error:
		return -1;
}

int main(int argc, char *argv[]) {
	check(argc == 2, "Needs an argument");
	
	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();
	
	check(test_check("ex19") == 0,"failed with file ex19.c");
	check(test_check(argv[1]) == 0, "failed with argv");
	check(test_sentinel(1), "test sentinel failed");
	check(test_check_mem() == 0,"test_check_mem failed");
	check(test_check_debug() == 0, "test_check_debug failed");
	
	
	return 0;
	
	error:
		return 1;
}