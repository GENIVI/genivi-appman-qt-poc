#!/bin/sh
#
# Copyright(C) 2016 Pelagicore AB
#
# Generates a new set of headers based on the Franca IDL
#
# The generated files are checked into git to avoid complex toolchain
# dependencies on development machines.

commonAPICodeGen -f appmgr_core-dbus.fdepl -o gen dbus
