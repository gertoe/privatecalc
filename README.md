# privatecalc
## unconventional table-notation but easy to understand
Naive implementation of Euclid's extended algorithm to calculate an RSA private-key a from a public-key <img src="svgs/f2ebdd12741c2e50f91b87f40c2b3394.svg?invert_in_darkmode" align=middle width=37.48206pt height=24.56552999999997pt/>

Iterative calculation of basic Euclidean Algorithm (top-down):
- <img src="svgs/5d0311c338d3938af9a740a8747ba360.svg?invert_in_darkmode" align=middle width=49.0446pt height=14.102549999999994pt/>,
- <img src="svgs/14d0c598b7ef8ae8591aa533d31c742e.svg?invert_in_darkmode" align=middle width=77.787765pt height=24.56552999999997pt/>,

- <img src="svgs/a81c2061ef17b983c4c7b852ed59ef3a.svg?invert_in_darkmode" align=middle width=67.07877pt height=14.102549999999994pt/>,
- <img src="svgs/2cc76e08f16fb045b82bb8f27d1ebb4d.svg?invert_in_darkmode" align=middle width=71.888025pt height=22.381919999999983pt/>,
- <img src="svgs/1d47be875254923a1f8e5414d49891a4.svg?invert_in_darkmode" align=middle width=82.89534pt height=22.745910000000016pt/>,
- <img src="svgs/1916f166162d52d55b2e32b15735b9f5.svg?invert_in_darkmode" align=middle width=95.1027pt height=22.745910000000016pt/>

Iterative calculation of extended Euclidean Algorithm (bottom-up):
- <img src="svgs/cda1164e70fe5dba84ff1dddeb45fc66.svg?invert_in_darkmode" align=middle width=257.486295pt height=22.745910000000016pt/>
- <img src="svgs/c16f0c27baa64ae504497a80c044af9f.svg?invert_in_darkmode" align=middle width=64.24308pt height=22.745910000000016pt/>
- <img src="svgs/344a4852e079b70e89dab7b502c8e279.svg?invert_in_darkmode" align=middle width=153.758385pt height=24.56552999999997pt/>

Private key: <img src="svgs/1be6a434188d73e9234e2966107094ae.svg?invert_in_darkmode" align=middle width=50.12782500000001pt height=22.745910000000016pt/>

<img src="svgs/04c1708d02e21b09cce26ec877997a4c.svg?invert_in_darkmode" align=middle width=128.33023500000002pt height=24.56552999999997pt/>

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
