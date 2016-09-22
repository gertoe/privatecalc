#include "phi.h"
#include "docopt.c"

int main(int argc, char *argv[])
{
  DocoptArgs args = docopt(argc, argv, /* help */ 1, /* version */ "0.1 ALPHA");

  if (args.gcd && args.phi)
  {
    printf("invalid subcommand combination\n");
    return EXIT_FAILURE;
  }

  else if (args.gcd)
  {
    unsigned long a, b;
    sscanf(args.a, "%lu", &a);
    sscanf(args.b, "%lu", &b);

    printf("gcd(%lu,%lu) = %lu\n", a, b, gcd(a,b));
    return EXIT_SUCCESS;
  }

  else if (args.phi)
  {
    unsigned long long x;
    sscanf(args.x, "%llu", &x);

    printf("phi(%llu) = %llu", x, phi(x));
    return EXIT_SUCCESS;
  }

  else
  {
    // reset count, initialize table
    gcd_count = 0;

    unsigned long e0, n;
    if (!args.e || !args.n)
    {
      printf("Printing example: e = 35, n = 85\n");
      e0 = 35;
      n = 85;
    }
    // parse command line arguments
    else
    {
      sscanf(args.e, "%lu", &e0);
      sscanf(args.n, "%lu", &n);
    }

    unsigned long phi0 = phi(n);
    count_gcd(e0, phi0);

    unsigned long e[gcd_count];
    unsigned long phi[gcd_count];
    unsigned long x[gcd_count];
    unsigned long R[gcd_count];
    long a[gcd_count];
    long b[gcd_count];

    // calculate Euclidean algorithm (basic and extended)
    down(e0, phi0, e, phi, x, R);
    up(x, a, b);

    if (args.verbose)
    {
      // verbose output
      printf("i\te\t\tphi\t\tx\t\tR\t\ta\t\tb\n");
      printf("\n");
      for (unsigned long i = 0; i < gcd_count; ++i)
      {
        printf("%lu\t%lu\t\t%lu\t\t%lu\t\t%lu\t\t%ld\t\t%ld\n", i, e[i], phi[i], x[i], R[i], a[i], b[i]);
      }
      printf("\n");
    }

    // print result
    printf("=> d = %lu\n", a[0]);
  }
  return EXIT_SUCCESS;
}
