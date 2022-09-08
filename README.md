# LatticeGreensFunctions

Computes lattice Green's functions  in two dimensions for square lattices. The method is a set of recurrence relations implemented in high-precision arithmetic. The square lattice results were needed for a particular research project, which is why this was developed, but similar recursion relations are available for three-dimensional lattices and the same method should work.

<p align="center">
<a href="https://github.com/psf/black"><img src="https://img.shields.io/badge/code%20style-black-000000.svg" alt="Code style: black"></a>
<a href="https://opensource.org/licenses/BSD-3-Clause"><img src="https://img.shields.io/badge/License-BSD_3--Clause-blue.svg" alt="BSD License"></a>
<a href="https://github.com/pre-commit/pre-commit"><img src="https://img.shields.io/badge/pre--commit-enabled-brightgreen?logo=pre-commit&logoColor=white" alt="pre-commit powered"></a>
</p>


## Installation

For the python version of the code, change to the directory LatticeGreensFunctions_mpmath and run the command

```bash
$ pip3 install .
```

There is a faster version using the package 'arb' whose installation
is not fully automated. You will need to download (perhaps compile)
working versions of flint and arb. In the directory
LatticeGreensFunctions_arb/src/LatticeGreensFunctions_arb, modify the
Makefile so that PYTHON_LIB ,  ARB_LIB, PYTHON_INC, ARB_INC,
FLINT_INC, and NUMPY_INC point to the
dynamic libraries for arb, flint, and Python, and the locations of
header files (include directories) for arb, python, and numpy.
Once this is done you will be able to type  
```bash
$ make
``` 
in the directory and create the library _LatticeGreensFunctions.so. 


Next go into the directory
LatticeGreensFunctions_arb/src/LatticeGreensFunctions_arb/AllocationFunctions. Point
PYTHON_LIB ,  PYTHON_INC, and NUMPY_INC to the directories for Python
library, Python include files and numpy include files.  Type
 ```bash
$ make
``` 
in the directory and create the library _AllocationFunctionss.so. 


Then go back up to the directory LatticeGreensFunctions_arb and install for Python with 

```bash
$ pip3 install .
```

## Usage

`LatticeGreensFunction` has a Jupyter notebook in the docs directory. It contains an example of how to run each type of code
and generate a matrix of Green's functions.


## License

`LatticeGreensFunctions` was created by Michael Marder. It is licensed under the terms of the
BSD 3-Clause license.

## Credits

This work was funded in part by National Science Foundation grant DMR 1810196 to the University of Texas
at Austin, with Michael Marder as PI . 
`LatticeGreensFunctions` was created with
[`cookiecutter`](https://cookiecutter.readthedocs.io/en/latest/) and the
`py-pkgs-cookiecutter`
[template](https://github.com/py-pkgs/py-pkgs-cookiecutter).

## Bibliography

Papers developing or using this approach include:

Marder, M. and Eftekhari, Behzad and Patzek, Tadeusz W., Solvable model of gas production decline from hydrofractured networks, Phys. Rev. E 104 
065001/1-21 (2021)  https://link.aps.org/doi/10.1103/PhysRevE.104.065001

Marder, M. and Eftekhari, Behzad and Patzek, Tadeusz W., Solvable Model for Dynamic Mass Transport in Disordered Geophysical Media, 
Phys. Rev. Lett (2018) 120 138302/1-4 https://link.aps.org/doi/10.1103/PhysRevLett.120.138302

These Green functions are discussed in section 5.3.2, p. 81, of Economou, E. N., Green's Functions in Quantum Physics, 2nd Edition (Springer, 1983)

The recurrence relations first appear in T. Morita, J. Math. Phys. 12, 1744 (1971); https://doi.org/10.1063/1.1665800





