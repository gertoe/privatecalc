#include "phi.h"

unsigned long gcd_count = 0;

// calculates Euler's phi-function phi(n)
unsigned long long phi(unsigned long long n)
{
  if (n <= 3)
    return (unsigned long long)0;
  else
  {
    unsigned char count = 0;
    unsigned long p = 0, q = 0;

    // only search up to upper bound (ceil(sqrt(n)) ~> assume "%" in O(1): phi(n) \in O(sqrt(n) + 1))
    // in fact "%" \in O(n) due to prime factorization \in NPC ~> O(exp(sqrt(n) + 1)
    unsigned long limit = (unsigned long)ceil(sqrtl(n));

    for (unsigned long i = 2; i < limit; ++i)
    {
      // get prime factors p and q. if p or q no prime (n is no dual-prime-product), then count > 1.
      if ((n % (unsigned long long)i) == 0)
      {
        p = i;
        q = (unsigned long)((unsigned long long)n/(unsigned long long)i);
        count += 1;
      }
      // optional (pseudo-code like)
      else
      {
        continue;
      }
    }

    // return value of Euler's phi-function: n = p*q => phi(n) = (p-1)*(q-1)
    return (count > 1) ? 0 : (unsigned long long)(((unsigned long long)(p-1))*(unsigned long long)(q-1));
  }
}

// C program to demonstrate Basic Euclidean Algorithm
// Function to return gcd of a and b
unsigned long gcd(unsigned long a, unsigned long b)
{
  return (a == 0) ? b : gcd((b % a), a);
}

// calculates gcd of a and b and increments global gcd count
unsigned long count_gcd(unsigned long a, unsigned long b)
{
  ++gcd_count;
  if (!a) // (a == 0)
  {
    return (unsigned long)b;
  }
  else
  {
    return (unsigned long)count_gcd(b % a, a);
  }
}

// calculate and store basic-Euclidean-algorithm-values
void down(unsigned long e0, unsigned long phi0, unsigned long e[], unsigned long phi[], unsigned long x[] ,unsigned long R[])
{
  e[0]   = e0;
  phi[0] = phi0;
  x[0]   = e[0] / phi[0];
  R[0]   = e[0] % phi[0];

  for (unsigned long i = 1; i < gcd_count; ++i)
  {
    e[i]   = phi[i-1];
    phi[i] = R[i-1];
    x[i]   = e[i]/phi[i];
    R[i]   = e[i]%phi[i];
  }
}

// calculate and store extended-Euclidean-algorithm-values
void up(unsigned long x[], long a[], long b[])
{
  a[gcd_count - 1] = 0;
  b[gcd_count - 1] = 1;

  for (unsigned long i = gcd_count - 2; i > 0; --i)
  {
    a[i] = b[i + 1];
    b[i] = a[i + 1] - (b[i + 1] * x[i]);
  }

  a[0] = b[1];
  b[0] = a[1] - (b[1] * x[0]);
}

