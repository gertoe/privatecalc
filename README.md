# privatecalc
- Implementation of the Extended Eucledian algorithm to calculate the RSA private-key component $d$ from a public key $\langle e, n\rangle$.
- Unconventional but easy to understand table notation.

##### Iterative calculation of basic Euclidean Algorithm (top-down):
- $e_0 := e$,
- $\varphi_0 := \varphi(n)$,

- $e_i = \varphi_{i-1}$,
- $\varphi_i = R_{i-1}$,
- $x_i = e~\text{div} \varphi$,
- $R_i = e~\mod \varphi$

##### Iterative calculation of extended Euclidean Algorithm (bottom-up):
- $R_i = 0 \Leftrightarrow \varphi_i = 1 \Leftrightarrow a_i = 0 \Leftrightarrow b_i = 1$
- $a_i = b_{i+1}$
- $b_i = a_{i+1} - (b_{i+1} \cdot x_i)$

##### Private key component:
- $d := a_0\mod \varphi(n)$ with
- $d \cdot e = 1~\mod \varphi(n)$


Usage:
---
```
privatecalc - a small program for calculating values related to RSA
              This program is designed for educational purposes.

WARNING: This C implementation suffers from buffer overflows.

Usage:
  privatecalc gcd <a> <b>
  privatecalc phi [-v|--verbose] <x>
  privatecalc prime <p>
  privatecalc [-v|--verbose] <e> <n>
  privatecalc [-h|--help]
  privatecalc --version

Options:
  -h --help     Show this screen.
  --version     Show version.
  -v --verbose  Be verbose

```

## Requirements
#### privatecalc:
- Clang / GCC

---

#### argparser
- flex
- bison

Installation
---
Just `make` and run.


License
---
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
All third party code is excepted from the licensing of this project.

Acknowledgements
---
- This Project uses [rouming/docopt.c] by Roman Pen



[rouming/docopt.c]:https://github.com/rouming/docopt.c
