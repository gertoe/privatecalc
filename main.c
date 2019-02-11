#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "cmd.h"
#include "phi.h"

int main(int argc, char *argv[])
{
  // cli-args structure
  struct cli cli;
  int rc;

  rc = cli_parse(argc, argv, &cli);
  if (rc)
  {
    fprintf(stderr, "%s\n", cli_usage);
    return -1;
  }
  else if (cli.h || cli.help)
  {
    fprintf(stderr, "%s\n", cli_usage);
    return EXIT_SUCCESS;
  }
  else
  {
    if (cli.version)
    {
      printf("privatecalc %s\n", BUILD);
      return EXIT_SUCCESS;
    }

    else if (cli.gcd)
    {
      unsigned long a, b;
      sscanf(cli.a, "%lu", &a);
      sscanf(cli.b, "%lu", &b);

      if(cli.v || cli.verbose)
      {
        printf("gcd(%lu,%lu) = ", a, b);
      }
      printf("%lu\n", gcd(a,b));
      return EXIT_SUCCESS;
    }

    else if (cli.phi)
    {
      unsigned long long x;
      sscanf(cli.x, "%llu", &x);

      unsigned long long phi_x = phi(x);

      if(cli.v || cli.verbose)
      {
        printf("p = %lu, q = %lu\n", p, q);
        printf("phi(%llu) = ", x);
      }

      printf("%llu\n", phi_x);

      return EXIT_SUCCESS;
    }

    else if (cli.prime)
    {
      unsigned long long p;
      sscanf(cli.p, "%llu", &p);
      return !isPrime(p);
    }

    else
    {
      // reset count, initialize table
      gcd_count = 0;

      unsigned long e0, n;
      if (!cli.e || !cli.n)
      {
        printf("Printing example: e = 35, n = 85\n");
        e0 = 35;
        n = 85;
      }
      // parse command line arguments
      else
      {
        sscanf(cli.e, "%lu", &e0);
        sscanf(cli.n, "%lu", &n);
      }

      unsigned long phi0 = phi(n);
      count_gcd(e0, phi0);

      unsigned long e[gcd_count];
      unsigned long phi[gcd_count];
      unsigned long x[gcd_count];
      unsigned long R[gcd_count];
      long a[gcd_count];
      long b[gcd_count];

      // calculate basic Euclidean algorithm
      down(e0, phi0, e, phi, x, R);
      // calculate extended Euclidean algorithm
      up(x, a, b);


      if (cli.verbose || cli.v)
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

      // fix result if a_0 is negative:
      // d = a_0 mod phi(n)
      unsigned long d = (a[0] < 0) ? (a[0] + phi0) : a[0];

      // print result
      if (cli.verbose || cli.v)
      {
        printf("=> (%ld) * %lu + (%ld) * %lu = 1 mod %lu\n", a[0], e0, b[0], phi0, phi0);
        printf("=> d mod phi(n) = ");
      }

      printf("%lu\n", d);
    }
  }

  cli_free(&cli);
  return EXIT_SUCCESS;
}

