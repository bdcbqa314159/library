#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/XCode
  make -f /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/XCode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/XCode
  make -f /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/XCode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/XCode
  make -f /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/XCode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/XCode
  make -f /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/XCode/CMakeScripts/ReRunCMake.make
fi

