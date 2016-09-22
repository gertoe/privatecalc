#ifndef PHI_H
#define PHI_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern unsigned long gcd_count;

unsigned long gcd(unsigned long a, unsigned long b);
unsigned long count_gcd(unsigned long a, unsigned long b);
void down(unsigned long e0, unsigned long phi0, unsigned long e[], unsigned long phi[], unsigned long x[] ,unsigned long R[]);
void up(unsigned long x[], long a[], long b[]);

unsigned long long phi(unsigned long long n);

#endif
