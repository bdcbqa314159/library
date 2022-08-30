
#include <cxxtest/TestSuite.h>
#include <cppBook5>
class ComplexTest : public CxxTest::TestSuite
{
public:
    void TestDefaultConstructor(void)
    {
        ComplexNumber z;
        double mod_z = z.calculateModulus();
        TS_ASSERT_DELTA(mod_z, 0.0, 1.e-16);
    }

    void TestCustomisedConstructor(void)
    {
        double real = 4.;
        double imaginary = -3.;

        ComplexNumber z(real, imaginary);

        double modulus = z.calculateModulus();
        double true_modulus = 5.;

        TS_ASSERT_DELTA(modulus, true_modulus, 1.e-8);

        double argument = z.calculateArgument();
        double true_argument = -asin(3. / 5.);
        TS_ASSERT_DELTA(argument, true_argument, 1.e-8);
    }

    void TestCalculatePower(void)
    {
        double real = 4.;
        double imaginary = -3.;

        ComplexNumber z(real, imaginary);

        double modulus = z.calculateModulus();
        double argument = z.calculateArgument();

        ComplexNumber z_squared = z.calculatePower(2.);

        double modulus_z_squared = z_squared.calculateModulus();

        double argument_z_squared = z_squared.calculateArgument();

        TS_ASSERT_DELTA(modulus_z_squared, modulus * modulus, 1.e-8);
        TS_ASSERT_DELTA(argument_z_squared, 2. * argument, 1.e-8);
    }

    void TestAgainstStdLibrary(void)
    {
        ComplexNumber z(4., -3);
        complex<double> std_z(4., -3);

        TS_ASSERT_DELTA(z.calculateArgument(), arg(std_z), 1.e-8);
        TS_ASSERT_DELTA(z.calculateModulus(), abs(std_z), 1.e-8);

        ComplexNumber z_5 = z.calculatePower(5.);
        complex<double> std_z_5 = pow(std_z, 5.);

        TS_ASSERT_DELTA(z_5.calculateArgument(), arg(std_z_5), 1.e-8);
        TS_ASSERT_DELTA(z_5.calculateModulus(), abs(std_z_5), 1.e-8);
    }
};
