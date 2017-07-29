#ifndef __ex22_h__
#define __ex22_h__

// Make THE_SIZE in ex22.c available to everyone
extern int THE_SIZE;

// Gets and sets internal static variables in ex22.c
int get_age();
void set_age(int age);

// Updates the static variable thats inside update_ratio
double update_ratio(double ratio);	

void print_size();

#endif