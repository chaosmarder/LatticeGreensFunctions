# LatticeGreensFunctions

Computes lattice Green's functions for square lattices

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
LatticeGreensFunctions_arb/src/LatticeGreensFunctions_arb, modify the Makefile to point to the
dynamic libraries for arb, flint, and Python, and the locations of
header files (include directories) for arb, python, and numpy.

Once this is done you will be able to type 'make' in the directory and create the library _LatticeGreensFunctions.so. 
Then return to the directory LatticeGreensFunctions_arb and install for Python with 

```bash
$ pip3 install .
``

## Usage

`LatticeGreensFunction` has a Jupyter notebook in the docs directory. It contains an example of how to run each type of code
and generate a matrix of Green's functions.


## License

`LatticeGreensFunctions` was created by Michael Marder. It is licensed under the terms of the
BSD 3-Clause license.

## Credits

This work was funded in part by an National Science Foundation grant to the University of Texas
at Austin, with Michael Marder as PI . 
`bluebonnet` was created with
[`cookiecutter`](https://cookiecutter.readthedocs.io/en/latest/) and the
`py-pkgs-cookiecutter`
[template](https://github.com/py-pkgs/py-pkgs-cookiecutter).

## Bibliography

Papers developing or using this approach include:


