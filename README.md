A Qt GENIVI AppMan PoC.

Copyright(C) 2016 Pelagicore AB

Introduction
------------

This is a PoC implementation of the GENIVI AppMan interfaces using Franca IDL
and CommonAPI C++ as a QML plugin.

Usage
-----

The idea is that the plugin can be imported into a QtAS System UI, allowing the
integration of the GENIVI AppMan interfaces into a QtAS-based system. The same
plugin can be used in any Qt-based system, as long as the application
management concepts are compatible with the GENIVI standard.

Building
--------

This is a standard qmake project, simply run the following commands to build
and install:

```
qmake
make
make install
```

Licenses
--------

- The contents of the franca sub-directory is licensed under MPLv2 unless
  otherwise stated.
- The contents of the src sub-directory is licensed under GPLv2 or later unless
  otherwise stated.

Please refer to the LICENSE.MPLv2 and LICENSE.GPLv2 files for further details.
