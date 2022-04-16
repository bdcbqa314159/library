#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bernardocohen/repos/library/cppDSA/cpp/XCode
  /usr/local/Cellar/cmake/3.22.0/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/Debug/libcppDSA.dylib /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/Debug/libcppDSA.dylib /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/Debug/libcppDSA.dylib
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bernardocohen/repos/library/cppDSA/cpp/XCode
  /usr/local/Cellar/cmake/3.22.0/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/Release/libcppDSA.dylib /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/Release/libcppDSA.dylib /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/Release/libcppDSA.dylib
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bernardocohen/repos/library/cppDSA/cpp/XCode
  /usr/local/Cellar/cmake/3.22.0/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/MinSizeRel/libcppDSA.dylib /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/MinSizeRel/libcppDSA.dylib /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/MinSizeRel/libcppDSA.dylib
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bernardocohen/repos/library/cppDSA/cpp/XCode
  /usr/local/Cellar/cmake/3.22.0/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/RelWithDebInfo/libcppDSA.dylib /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/RelWithDebInfo/libcppDSA.dylib /Users/bernardocohen/repos/library/cppDSA/cpp/XCode/RelWithDebInfo/libcppDSA.dylib
fi

