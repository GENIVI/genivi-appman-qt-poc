#!/bin/sh
#
# Copyright(C) 2016 Pelagicore AB
#
# Generates a new set of headers based on the Franca IDL
#
# The generated files are checked into git to avoid complex toolchain
# dependencies on development machines.

# Generate CommonAPI C++ wrappers for dbus
commonAPICodeGen -f appmgrcore-dbus.fdepl -o gen dbus

# Locate introspection data and generate dbus introspection xml
FIRST=$(grep -n introspectionData gen/org/genivi/appfw/AppManagerCoreDBusStubAdapter.cpp | sed 's/:.*//' | head -n1)
LAST=$(grep -n introspectionData gen/org/genivi/appfw/AppManagerCoreDBusStubAdapter.cpp | sed 's/:.*//' | tail -n1)

HEADING=$(echo $LAST-1 | bc)
LENGTH=$(echo $HEADING-$FIRST | bc)

echo '<!DOCTYPE node PUBLIC "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN" "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd"><node name="/org/genivi/appfw/appmanager"><interface name="org.genivi.appfw.AppManagerCore">' > gen/dbus-introspection.xml
head -n$HEADING gen/org/genivi/appfw/AppManagerCoreDBusStubAdapter.cpp | tail -n$LENGTH | grep '^\s*\"' | sed 's/^\s*\"//;s/\"$//;s/\\n$//;s/\\\"/\"/g' >> gen/dbus-introspection.xml
echo '</interface></node>' >> gen/dbus-introspection.xml

# Annotate introspection XML to allow the Qt code generator to work
read -r AWKEXPR << EOE
{print} \
/\(a\{ss\}\)/ {print "<annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"GeniviAppInfo\" />"}
EOE

cat gen/dbus-introspection.xml | awk "$AWKEXPR" > gen/qt-dbus-introspection.xml

# Generate Qt adaptor
qdbusxml2cpp -i geniviappmaninfo.h -a gen/appmanagercore gen/qt-dbus-introspection.xml
