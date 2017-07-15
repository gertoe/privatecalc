#include "phi.h"

unsigned long gcd_count = 0;
unsigned long p;
unsigned long q;


int isPrime(unsigned long long n)
{
  // Corner cases
  if (n <= 1)
  {
    return 0;
  }
  else if (n <= 3)
  {
    return 1;
  }
  else
  {
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (!(n%2) || !(n%3))
    {
      return 0;
    }
    else
    {
      for (unsigned long i = 5; i*i <= n; i += 6)
      {
        if (n % (unsigned long long)i == 0 || n % (i+2) == 0)
        {
          return 0;
        }
        else
        {
          continue;
        }
      }
    }
  }

  return 1;
}


// calculates Euler's phi-function phi(n)
// WARNING: still bugs in here
//
// exits with error code 1 if p or q are no primes
unsigned long long phi(unsigned long long n)
{
  // 1 is no prime, therefore (1 * 2) and (1 * 3) are no prime products
  if (n <= 3)
    exit(1);
  else
  {
    unsigned char count = 0;
    p = 1;
    q = n;

    // naive optimisation: seach up to sqrt(n)
    unsigned long limit = (unsigned long)ceil(sqrtl(n));

    for (unsigned long i = 2; i <= limit; ++i)
    {

      // determine prime factors p and q. if p or q are no primes (n is no prime-product), then count > 1.
      if ((n % (unsigned long long)i) == 0)
      {
        p = (unsigned long long)i;
        q = (unsigned long) (((unsigned long long)n) / ((unsigned long long)i));

        if (isPrime(p) && isPrime(q))
        {
          count += 1;
          break;
        }
      }
      else
      {
        continue;
      }
    }

    if (!isPrime(p) || !isPrime(q))
    {
      exit(1);
    }
    else
    {

    // return value of Euler's phi-function: n = p*q => phi(n) = (p-1)*(q-1)
    return ((count > 1) || (!p && !q)) ? 0 : (unsigned long long)(((unsigned long long)(p-1))*(unsigned long long)(q-1));
    }
  }
}

// C program to demonstrate Basic Euclidean Algorithm
// Function to return gcd of a and b
unsigned long gcd(unsigned long a, unsigned long b)
{
  if (!a && !b)
  {
    // gcd(0,0) = 1
    return 1;
  }
  return (a == 0) ? b : gcd((b % a), a);
}

// calculates gcd of a and b and increments global gcd count
unsigned long count_gcd(unsigned long a, unsigned long b)
{
  if (!a && !b)
  {
    // gcd(0,0) = 1
    return 1;
  }
  else
  {
    ++gcd_count;
    if (a == 0)
    {
      return (unsigned long)b;
    }
    else
    {
      return (unsigned long)count_gcd(b % a, a);
    }
  }
}

// calculates basic Euclidean algorithm
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

// calculates extended Euclidean algorithm
// WARNING: a, b mod phi(n); this function calculates a and b without modulus!
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

