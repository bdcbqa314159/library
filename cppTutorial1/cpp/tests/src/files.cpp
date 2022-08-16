#include <cppTutorial1>
#include <iostream>
#include <fstream>

using namespace std;

void writing()
{

    // ofstream outFile;
    fstream outFile;
    string outputFileName = "text.txt";
    // outFile.open(outputFileName);
    outFile.open(outputFileName, ios::out);

    if (outFile.is_open())
    {
        outFile << "Hello there" << endl;
        outFile << 123 << endl;
        outFile.close();
    }

    else
    {
        cout << "Could not create file :" << outputFileName << endl;
    }
}

void reading()
{
    string inFileName = string{"/Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/bin/text.txt"};
    ifstream inFile;

    inFile.open(inFileName);

    if (inFile.is_open())
    {
        string line;
        // inFile >> line;
        while (inFile)
        {
            getline(inFile, line);
            cout << line << endl;
        }

        inFile.close();
    }

    else
    {
        cout << "Cannot open file: " << inFileName << endl;
    }
}

int parsing()
{
    string inFileName = string{"/Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/bin/stats.txt"};

    ifstream input;

    input.open(inFileName);

    if (!input.is_open())
    {
        return 1;
    }

    while (input)
    {
        string line;
        getline(input, line, ':');
        int population;
        input >> population;

        // input.get();
        // Below c++11:
        input >> ws;

        if (!input)
            break;
        cout << "'" << line << "'"
             << " --- "
             << "'" << population << "'" << endl;
    }

    input.close();
    return 0;
}

#pragma pack(push, 1)

struct PersonFile
{
    // Can't use string for binary files because we use extra memory.
    char name[50];
    int age;
    double height;
};

#pragma pack(pop)

int main()
{
    // cout << sizeof(PersonFile) << endl;

    string fileName = "testingBinFiles";
    PersonFile someone = {"Frodo", 220, 0.8};

    // Write binary file
    ofstream outputFile;

    outputFile.open(fileName, ios::binary);

    if (outputFile.is_open())
    {

        // outputFile.write((char *)&someone, sizeof(Person)); Old way

        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(PersonFile));

        outputFile.close();
    }

    else
    {
        cout << "Could not create file " + fileName << endl;
    }

    // Read binary file
    string inFilePath = string{"/Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/bin/testingBinFiles"};

    PersonFile someoneElse = {};
    ifstream inputFile;

    inputFile.open(inFilePath, ios::binary);

    if (inputFile.is_open())
    {

        // inputFile.write((char *)&someone, sizeof(Person)); Old way

        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(PersonFile));

        inputFile.close();
    }

    else
    {
        cout << "Could not read file " + fileName << endl;
    }

    cout << someoneElse.name << " " << someoneElse.age << " " << someoneElse.height << endl;
    cout << someone.name << " " << someone.age << " " << someone.height << endl;

    return 0;
}

/* There is a upcoming issue because the pre padding which set the size with more bytes that we need.
 */