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

The repositor contains a git submodule where the Franca interfaces are
referenced. Thus, run the following commands first to clone the submodule:

```
git submodule init
git submodule update
```

This is a standard qmake project, simply run the following commands to build
and install:

```
qmake
make
make install
```

Running Locally
---------------

If you want to test the example without having to install it, a very basic
example implementation is provided.

This example provides a stubbed implementation of the application database and
can be run standalone using the qmlscene tool.

To run the example locally, i.e. without installing the plugin, you first have
to copy the `qmldir` file into the `imports` directory:

```
cp src/qmldir imports/GeniviAppFw/
```

Having done this, you launch the example and specify that the local `imports`
directory is a QML import path.

```
qmlscene -I ./imports example/example.qml
```

You can now access the interface over d-bus using dbus-send, e.g. listing the
installed apps:

```
$ dbus-send --print-reply --session --dest=org.genivi.appfw /org/genivi/appfw/AppManagerCore org.genivi.appfw.AppManagerCore.getInstalledApps
method return time=1467869897.358102 sender=:1.423 -> destination=:1.428 serial=15 reply_serial=2
   array [
      string "org.genivi.TunerAMFM"
      string "org.genivi.TunerDAB"
      string "org.genivi.Navigation"
      string "org.genivi.Settings"
      string "org.genivi.Telephone"
   ]
```

Getting information about a specific application:

```
$ dbus-send --print-reply --session --dest=org.genivi.appfw /org/genivi/appfw/AppManagerCore org.genivi.appfw.AppManagerCore.getAppInfo string:"org.genivi.Settings"
method return time=1472211399.493666 sender=:1.270 -> destination=:1.273 serial=11 reply_serial=2
   struct {
      array [
         dict entry(
            string "appId"
            string "org.genivi.Settings"
         )
      ]
   }
```

Launching an application:

```
dbus-send --print-reply --session --dest=org.genivi.appfw /org/genivi/appfw/AppManagerCore org.genivi.appfw.AppManagerCore.launchApp string:"org.genivi.Settings"
```

Resulting in the following output from the demo applications:

```
qml: Launching org.genivi.Settings
```

Licenses
--------

- The contents of the franca sub-directory is licensed under MPLv2 unless
  otherwise stated.
- The contents of the src sub-directory is licensed under GPLv2 or later unless
  otherwise stated.

Please refer to the LICENSE.MPLv2 and LICENSE.GPLv2 files for further details.
