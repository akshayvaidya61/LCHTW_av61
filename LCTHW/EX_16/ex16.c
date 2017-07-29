#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) {
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	return who;
}

void Person_destroy(struct Person *who) {
	assert(who != NULL);
	free(who->name);
	free(who);
}

void Person_print(struct Person *who) {
	printf("Name   : %s\n", who->name);
	printf("Age    : %d\n", who->age);
	printf("Height : %d\n", who->height);
	printf("Weight : %d\n", who->weight);
}

void print_Person(struct Person who) {
	printf("Name   : %s\n", who.name);
	printf("Age    : %d\n", who.age);
	printf("Height : %d\n", who.height);
	printf("Weight : %d\n", who.weight);
}

int main(int argc, char *argv[]) {
	// Make two people structures
//	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
//	struct Person *frank = Person_create("Frank Blank", 20, 72, 80);
	struct Person joe;
	joe.name = "Joe";
	joe.age = 20;
	joe.height = 64;
	joe.weight = 140;
	// Print them out and where they are in memory
	printf("Joe is at memory location: 0x%u\n", joe);
	printf("Name:%s\nAge:%d\nHeight:%d\nWeight:%d\n",joe.name,joe.age,joe.height,joe.weight);
	struct Person frank;
	frank.name = "Frank";
	frank.age = 20;
	frank.height = 64;
	frank.weight = 140;
	print_Person(frank);
	//Person_print(joe);
	//printf("Frank is at memory location: 0x%u\n", frank);
	//Person_print(frank);
	
	// Make everyone age 20 years and print
	//joe->age += 20;
	//joe->height -= 2;
	//joe->weight+= 40;

	//frank->age += 20;
	//frank->weight += 20;

	//Person_print(joe);
	//Person_print(frank);

	//Person_destroy(joe);
	//Person_destroy(frank);
	return 0;
}
