#include <iostream>
#include <string>

using namespace std;

class SecsTransformer
{
    int numSecs, secs, hours, mins;

public:
    SecsTransformer(int numSecs) : numSecs(numSecs), secs(0), hours(0), mins(0) {}
    void operator()();
    void showSolution();
};

void SecsTransformer::operator()()
{
    secs = numSecs;
    mins = secs / 60;
    secs %= 60;
    hours = mins / 60;
    mins %= 60;
}

void SecsTransformer::showSolution()
{
    cout << "The initial number of secs " << numSecs << " is decomposed in: " << endl;
    cout << hours << "h:" << mins << "m:" << secs << "s." << endl;
}

void showDots()
{
    for (int i = 1; i <= 10000; i++)
    {
        if (i % 100 == 0)
            cout << i << ": "
                 << ". " << endl;
    }
}

int main()
{
    cout << "Simple stuff with arithmetic: " << endl;

    int a = 7, b = 2;
    cout << a << "/" << b << " = " << a / b << endl;
    cout << "This was euclidean division." << endl;
    cout << "If we want the real version of quotient:" << endl;
    cout << "Then multiply by 0.1" << endl;
    cout << .1 * a / b << endl;
    cout << "Voila :)" << endl;

    cout << "Using +=, -=, /=" << endl;
    int x = 94382;
    cout << "x = " << x << endl;
    x += 10;
    cout << "+=10: " << x << endl;
    x -= 10;
    cout << "-=10: " << x << endl;
    x /= 10;
    cout << "/=10: " << x << endl;

    cout << "x % 4 = " << x % 4 << endl;
    cout << "The order of the expressions are respected just as with Matths" << endl;

    cout << "Seconds transformer: " << endl;
    cout << "Give a number of secs: ";
    int numSecs;
    cin >> numSecs;
    SecsTransformer secsTransformer(numSecs);
    secsTransformer();
    secsTransformer.showSolution();
    cout << endl;

    cout << "Iterating 10 000 times but showing a single dot every 100th iteration." << endl;
    showDots();
    cout << endl;

    return 0;
}