#!/bin/env bash

###################################################################################################
# Cleanup Script
###################################################################################################

function cleanup {
  echo "Cleanup:"
  if [ -d "$wd" ]
  then
    rm -rf "$wd"
    echo "  - delete temporary working directory"
  fi
}

trap "cleanup" EXIT

###################################################################################################
# Help message
###################################################################################################

function help() {
   echo "Installer script for Oat++"
   echo
   echo "Syntax: install-oatpp.sh [-h] -p <prefix>"
   echo "options:"
   echo "h     Print this Help."
   echo "p     Install prefix."
   echo
}

###################################################################################################
# Parse command line options
###################################################################################################

while getopts ":hp:" option; do
   case $option in
      h)
        help
        exit;;
      p)
        prefix=$OPTARG;;
     \?)
        echo "Error: Invalid option"
        echo
        help
        exit;;
   esac
done

if [ -z "$prefix" ]
then
  echo "Error: Install prefix is required"
  echo
  help
  exit
fi

###################################################################################################
# Create working directory
###################################################################################################

wd=$(mktemp -d)
cd $wd

###################################################################################################
# Get source code
###################################################################################################

git clone --depth=1 https://github.com/oatpp/oatpp.git

cmake \
  -D CMAKE_BUILD_TYPE=Release \
  -D OATPP_BUILD_TESTS=OFF \
  -D OATPP_DISABLE_ENV_OBJECT_COUNTERS=OFF \
  -B build \
  -S oatpp
cmake --build build -j $(nproc)
cmake --install build --prefix $prefix
