#ifndef MAIN_H
#define MAIN_H

/**
 *Desc: Contains all the main prototype functions used in the 0x14  Bit Manipulation Task
 */

unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int _putchar(char c);
#endif /*MAIN_H*/
