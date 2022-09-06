# LatticeGreensFunctions

Computes lattice Green's functions for square lattices

<p align="center">
<a href="https://github.com/psf/black"><img src="https://img.shields.io/badge/code%20style-black-000000.svg" alt="Code style: black"></a>
<a href="https://bluebonnet.readthedocs.io/en/latest/?badge=latest"><img src="https://readthedocs.org/projects/bluebonnet/badge/?version=latest" alt="Documentation"></a>
<a href="https://opensource.org/licenses/BSD-3-Clause"><img src="https://img.shields.io/badge/License-BSD_3--Clause-blue.svg" alt="BSD License"></a>
<a href="https://github.com/pre-commit/pre-commit"><img src="https://img.shields.io/badge/pre--commit-enabled-brightgreen?logo=pre-commit&logoColor=white" alt="pre-commit powered"></a>
</p>

![bluebonnets in bloom](https://github.com/frank1010111/bluebonnet/raw/main/docs/_static/bluebonnets.jpg)

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

Once this is done you will be able to type 'make' in the directory and 

## Usage

`bluebonnet` has a collection of tools for performing reservoir simulation in
tight oil and shale gas reservoirs. The main tools are:

1. `fluids` for modeling PVT and viscosity of oil, water, and gas;
2. `flow` for building physics-based production curves; and
3. `forecast` for fitting and forecasting unconventional production.

Examples can be found in
[the documentation](https://bluebonnet.readthedocs.io/en/latest/flow.html).

## Contributing

Interested in contributing? Check out the
[contributing guidelines](https://bluebonnet.readthedocs.io/en/latest/contributing.html)
to get started. Please note that this project is released with a Code of
Conduct. By contributing to this project, you agree to abide by its terms.

### Contributor Hall of Fame

Michael Marder

## License

`LatticeGreensFunctions` was created by Frank Male. It is licensed under the terms of the
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


