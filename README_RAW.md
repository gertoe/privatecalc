# privatecalc
## unconventional table-notation but easy to understand
Naive implementation of Euclid's extended algorithm to calculate an RSA private-key a from a public-key $\langle e, n\rangle$

Iterative calculation of basic Euclidean Algorithm (top-down):
- $e_0 := e$,
- $\varphi_0 := \varphi(n)$,

- $e_i = \varphi_{i-1}$,
- $\varphi_i = R_{i-1}$,
- $x_i = e~\text{div} \varphi$,
- $R_i = e~\text{mod} \varphi$

Iterative calculation of extended Euclidean Algorithm (bottom-up):
- $R_i = 0 \Leftrightarrow \varphi_i = 1 \Leftrightarrow a_i = 0 \Leftrightarrow b_i = 1$
- $a_i = b_{i+1}$
- $b_i = a_{i+1} - (b_{i+1} \cdot x_i)$

Private key: $d := a_0$

$d \cdot e = 1~\text{mod} \varphi(n)$

```

Usage:
  privatecalc gcd <a> <b>
  privatecalc phi [-v|--verbose] <x>
  privatecalc [-v|--verbose] <e> <n>
  privatecalc [-h|--help]
  privatecalc --version

Options:
  -h --help     Show this screen.
  --version     Show version.
  -v --verbose  Be verbose

```
