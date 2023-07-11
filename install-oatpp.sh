#!/bin/env bash

###################################################################################################
# Cleanup function
###################################################################################################

function cleanup {
  echo "Cleanup:"
  if [ -d "${wd}" ]
  then
    rm -rf "${wd}"
    echo "  - delete temporary working directory"
  fi
}

trap "cleanup" EXIT

###################################################################################################
# Installer function
###################################################################################################

function install_module() {
  module_name=${1}
  cmake_defines=${@}

  git clone --depth=1 https://github.com/oatpp/${module_name}.git

  cmake ${cmake_defines} -B build-${module_name} -S ${module_name}
  cmake --build build-${module_name} -j $(nproc)
  cmake --install build-${module_name} --prefix ${prefix}
}

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
   case ${option} in
      h)
        help
        exit;;
      p)
        prefix=${OPTARG};;
     \?)
        echo "Error: Invalid option"
        echo
        help
        exit;;
   esac
done

if [ -z "${prefix}" ]
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
# Install Oat++ modules
###################################################################################################

install_module oatpp \
  -D CMAKE_BUILD_TYPE=Release \
  -D OATPP_BUILD_TESTS=OFF \
  -D OATPP_DISABLE_ENV_OBJECT_COUNTERS=OFF

install_module oatpp-sqlite \
  -D oatpp_ROOT=${prefix} \
  -D CMAKE_BUILD_TYPE=Release \
  -D OATPP_BUILD_TESTS=OFF \
  -D OATPP_SQLITE_AMALGAMATION=ON

install_module oatpp-swagger \
  -D oatpp_DIR=${prefix}/lib/cmake/oatpp-1.3.0 \
  -D CMAKE_BUILD_TYPE=Release \
  -D OATPP_BUILD_TESTS=OFF
