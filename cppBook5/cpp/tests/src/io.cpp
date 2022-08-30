#include <cppBook5>
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

double myDivision(int x, int y)
{
    if (y == 0)
        throw string("Error - can't divide by zero");
    else
    {
        return 1. * x / y;
    }
}

void divideInterface()
{

    try
    {
        double z = myDivision(12, 0);
        cout << "All good!" << endl;
    }
    catch (string &e)
    {
        cout << "We tried to divide by zero" << endl;
        cerr << e << endl;
    }
    cout << "End of the program" << endl;
}

void interface1()
{
    double x[3] = {0., 1., 0.};
    double y[3] = {0., 0., 1.};

    ofstream write_output("test.dat");
    assert(write_output.is_open());

    for (int i = 0; i < 3; i++)
        write_output << x[i] << " " << y[i] << endl;
    write_output.close();
}

void interface2()
{
    double x[3] = {0., 1., 0.};
    double y[3] = {0., 0., 1.};

    ofstream write_output("test.dat", ios::app);
    assert(write_output.is_open());
    write_output << "========= hehehe LOL" << endl;
    for (int i = 0; i < 3; i++)
        write_output << x[i] << " " << y[i] << endl;
    write_output.close();
}

void interface3()
{
    double x = 1.8364238;

    ofstream write_output("output.dat");
    assert(write_output.is_open());

    write_output.precision(3);
    write_output << x << endl;

    write_output.precision(5);
    write_output << x << endl;

    write_output.precision(8);
    write_output << x << endl;

    write_output.close();
}

void interface4()
{
    ofstream write_output("multiply.dat");
    assert(write_output.is_open());

    for (int i = 0; i < 6; i++)
        write_output << i << " " << 2 * i << endl;

    write_output.close();

    ifstream read_file("multiply.dat");
    assert(read_file.is_open());

    int x[6], y[6];

    for (int i = 0; i < 6; i++)
        read_file >> x[i] >> y[i];
    read_file.close();

    cout << "In program:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << x[i] << " -- " << y[i] << endl;
    }
}

/*
we can use: while(!read_file.eof()){...}

we can also use read_file.clear();
and read_file.seekg(ios::beg);

we can also test with assert(write_output.good());
*/

void interface6(int argc, char *argv[])
{
    cout << "Number of command line args = " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "arg " << i << " = " << argv[i] << endl;
    }

    string program_name = argv[0];
    int nodes = atoi(argv[1]);
    double conductivity = atof(argv[2]);

    cout << "program name " << program_name << endl;
    cout << "nodes " << nodes << endl;
    cout << "conductivity " << conductivity << endl;
}

/*TIPS
We can use the flag ios::scientific
ios::showpos

Set the precision (already used above...)
*/

void interface7()
{
    ofstream write_file("outputFormatted.dat");
    assert(write_file.is_open());

    write_file.setf(ios::scientific);
    write_file.setf(ios::showpos);
    write_file.precision(13);

    double x = 3.4, y = 0.0000855, z = 984.424;
    write_file << x << " " << y << " " << z << endl;
    write_file.close();
}

void interface8()
{
    double x[4] = {0., 1., 1., 0.};
    double y[4] = {0., 0., 1., 1.};

    string name = "x_and_y.dat";
    ifstream read(name);
    assert(read.is_open());
    read.close();

    cout << "File read & closed successfully" << endl;

    int option = 0;
    cout << "What do you want to do?" << endl;
    cout << "1. append" << endl;
    cout << "2. renew" << endl;

    cin >> option;
    ofstream write;

    if (option == 1)
        write.open("x_and_y.dat", ios::app);
    else if (option == 2)
        write.open("x_and_y.dat");

    assert(write.is_open());
    write.setf(ios::scientific);
    write.setf(ios::showpos);
    write.precision(10);

    for (int i = 0; i < 4; i++)
        write << x[i] << " ";
    write.flush();
    write << endl;

    for (int i = 0; i < 4; i++)
        write
            << y[i] << " ";
    write.flush();
    write << endl;

    write.close();
}

void interface9()
{
    ifstream read_file("x_and_y.dat");
    if (read_file.is_open())
    {
        int no = 0;
        string s;
        while (getline(read_file, s))
        {
            double x1, x2, x3, x4;
            read_file >> x1 >> x2;
            read_file >> x3 >> x4;
            no++;
        }
        cout << "Number of rows: " << no << endl;
        read_file.close();
    }
}

double f(double x, double y)
{
    return -y;
}

void interface10()
{
    int N = 200;
    double x0 = 0., x1 = 1.;
    double h = (x1 - x0) / N;

    double y0 = 1., yn = 0.;

    for (int i = 0; i < N; i++)
    {
        double D = f(x0, y0);
        yn = y0 + D * h;
        cout << yn << " -- " << exp(-x0) << endl;
        x0 += h;
        y0 = yn;
    }
}

int main(int argc, char *argv[])
{
    // divideInterface();
    // interface1();
    // interface2();
    // interface3();
    // interface4();
    // interface6(argc, argv);
    // interface7();
    // interface8();
    // interface9();
    interface10();

    return 0;
}