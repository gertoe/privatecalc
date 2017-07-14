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
  if (rc || cli.h || cli.help) {
    fprintf(stderr, "%s\n", cli_usage);
    return -1;
  }

  if (cli.gcd && cli.phi)
  {
    printf("invalid subcommand combination\n");
    return EXIT_FAILURE;
  }

  else if (cli.gcd)
  {
    unsigned long a, b;
    sscanf(cli.a, "%lu", &a);
    sscanf(cli.b, "%lu", &b);

    printf("gcd(%lu,%lu) = %lu\n", a, b, gcd(a,b));
    return EXIT_SUCCESS;
  }

  else if (cli.phi)
  {
    unsigned long long x;
    sscanf(cli.x, "%llu", &x);

    printf("phi(%llu) = %llu\n", x, phi(x));

    if(cli.v || cli.verbose)
    {
      printf("p = %lu, q = %lu\n", p, q);
    }

    return EXIT_SUCCESS;
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

    // print result
    if (cli.verbose || cli.v)
    {
      printf("=> ");
    }
    printf("d = %lu\n", a[0]);
  }

  cli_free(&cli);
  return EXIT_SUCCESS;
}
