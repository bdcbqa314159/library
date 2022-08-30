#include <cppBook5>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cxxtest/TestSuite.h>

using namespace std;

void readFile(const string &filename, vector<double> &x, vector<double> &y)
{
    ifstream read_file(filename.c_str());

    if (read_file.is_open() == false)
    {
        throw(Exception("FILE", "File can't be opened"));
    }

    int n = x.size(), m = y.size();
    if (n != m)
    {
        throw(Exception("ERROR SIZE", "input must have same size"));
    }

    for (int i = 0; i < n; i++)
    {
        read_file >> x[i] >> y[i];
    }

    read_file.close();

    cout << filename << " read successfully" << endl;
}

void myExceptionTest()
{
    vector<double> x(6), y(6);

    try
    {
        readFile("newOutputu.dat", x, y);
    }

    catch (Exception &error)
    {
        error.PrintDebug();

        cout << "Could not open file" << endl;
        cout << "Give alternative location" << endl;
        string filename;
        getline(cin, filename);
        readFile(filename, x, y);
    }
}

class ComplexTest : public CxxTest::TestSuite
{
public:
    void TestDefaultConstructor(void)
    {
        ComplexNumber z;
        double mod_z = z.calculateModulus();
        TS_ASSERT_DELTA(mod_z, 0.0, 1.e-16);
    }
};

int main()
{
    cout << "Need to work on boost test." << endl;
    ComplexTest testing;

    testing.TestDefaultConstructor();
    return 0;
}