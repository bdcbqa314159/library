/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_ComplexTest_init = false;
#include "testingCxx.hpp"

static ComplexTest suite_ComplexTest;

static CxxTest::List Tests_ComplexTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ComplexTest( "testingCxx.hpp", 4, "ComplexTest", suite_ComplexTest, Tests_ComplexTest );

static class TestDescription_suite_ComplexTest_TestDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTest_TestDefaultConstructor() : CxxTest::RealTestDescription( Tests_ComplexTest, suiteDescription_ComplexTest, 7, "TestDefaultConstructor" ) {}
 void runTest() { suite_ComplexTest.TestDefaultConstructor(); }
} testDescription_suite_ComplexTest_TestDefaultConstructor;

static class TestDescription_suite_ComplexTest_TestCustomisedConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTest_TestCustomisedConstructor() : CxxTest::RealTestDescription( Tests_ComplexTest, suiteDescription_ComplexTest, 14, "TestCustomisedConstructor" ) {}
 void runTest() { suite_ComplexTest.TestCustomisedConstructor(); }
} testDescription_suite_ComplexTest_TestCustomisedConstructor;

static class TestDescription_suite_ComplexTest_TestCalculatePower : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTest_TestCalculatePower() : CxxTest::RealTestDescription( Tests_ComplexTest, suiteDescription_ComplexTest, 31, "TestCalculatePower" ) {}
 void runTest() { suite_ComplexTest.TestCalculatePower(); }
} testDescription_suite_ComplexTest_TestCalculatePower;

static class TestDescription_suite_ComplexTest_TestAgainstStdLibrary : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTest_TestAgainstStdLibrary() : CxxTest::RealTestDescription( Tests_ComplexTest, suiteDescription_ComplexTest, 51, "TestAgainstStdLibrary" ) {}
 void runTest() { suite_ComplexTest.TestAgainstStdLibrary(); }
} testDescription_suite_ComplexTest_TestAgainstStdLibrary;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
