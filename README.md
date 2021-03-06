![ModelTest-NG](https://github.com/ddlsandbox/assets/blob/master/modeltest/img/header.png?raw=true)

ModelTest-NG is a tool for selecting the best-fit model of evolution
for DNA and protein alignments.
ModelTest-NG supersedes jModelTest and ProtTest in one single tool,
with graphical and command console interfaces.

## Documentation

If you want to read about using ModelTest-NG, a PDF manual is attached to
each [release](https://github.com/ddarriba/modeltest/releases).
You can also browse the [wiki](https://github.com/ddarriba/modeltest/wiki) for
online documentation, and the [FAQ section](https://github.com/ddarriba/modeltest/wiki/FAQ)
for common errors.

## Prerequisites

Core model parameter optimization and likelihood evaluation depend on the
high-level modules for the Phylogenetic Likelihood Library.
The latest compatible version is linked here as a submodule,
so if you are cloning the repository, make sure you initialize the submodules:

```bash
$ git clone --recursive https://github.com/ddarriba/modeltest
```
This step is not necessary if you downloaded the released tarball.

## Install

0. Automatic Build

There are 2 ways of building ModelTest-NG:
  - Using cmake
  - Using autotools

Both should work, so choose the one is more comfortable for you. If you experience
any problem, please try the other one as well.

a) Build ModelTest-NG using `cmake`:

  PTHREADS version:

  ```
  cd modeltest-ng
  mkdir build && cd build
  cmake ..
  make
  ```

  MPI version:

  ```
  cd modeltest-ng
  mkdir build && cd build
  cmake -DUSE_MPI=ON ..
  make
  ```

  ModelTest-NG binaries will be placed in `modeltest-ng/bin` directory.

b) Build ModelTest-NG using `autotools`

  If you have downloaded a complete distribution, check the following files exist:
    - libpll-x.y.z.tar.gz
    - pll-modules-x.y.z.tar.gz
    - build.sh

  Run the installer script:

  ```bash
  $ build.sh
  ```

  This should extract and compile the required libraries and link them statically
  in the ModelTest-NG binaries for console (modeltest-ng, modeltest-mpi) and GUI (modeltest-gui) if
  a valid `qmake` is available.

  Note that, qmake might be available in some linux distributions,
  but NOT a functional QT framework.
  Try running `qmake`, and if you observe and error,
  install `qt5-default` from apt repositories:

  ```bash
  $ sudo apt-get install qt5-default
  ```

  The resulting binaries and libraries will be placed in `build/bin` and `build/lib` directories

1. Graphical User Interface

To install ModelTest-NG GUI type the following commands:

```bash
$ ./build_qmake-sh
$ make -f Makefile.qmake
$ make install -f Makefile.qmake
```

Run 'modeltest-gui' without arguments for loading the GUI

2. Command Console Interface

To install ModelTest-NG type the following commands:

```bash
$ ./configure [--prefix=INSTALL_DIR]
$ make
$ make install
```

Set a custom install directory if you don't have root access or you prefer a
different location.

This will compile pthreads and MPI versions
Run 'modeltest-ng --help' for help about the console interface.

## Windows installation 

To compile a Windows executable, install MinGW and run:

```bash
$ ac_cv_func_malloc_0_nonnull=yes ac_cv_func_realloc_0_nonnull=yes mingw64-configure
$ make
```

In case the configure script does not exist, it must be generated using autotools:

```bash
$ autoreconf -i
```
