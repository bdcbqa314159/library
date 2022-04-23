#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{
    cout << "Coin Change Problem" << endl;
    float change = 17.61;
    cout << "Minimal number of change for ";
    cout << change << " is " << endl;
    MinimalChangeCoin(change);

    cout << "Huffman Codes" << endl;
    //    char arr[] = { 'a', 'e', 'i', 's', 't', ' ', 'n' };
    //    int freq[] = { 10, 15, 12, 3, 4, 13, 1 };
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    cout << "Fibonacci numbers..." << endl;
    cout << fib2(10) << " <- this is the 10th Fibonacci number :)." << endl;

    cout << endl;
    cout << "CAPTCHA" << endl;
    cout << GenerateCaptcha(10) << endl;

    cout << endl;
    cout << "Coin Change Dynamic Programming" << endl;

    int S[] = {2, 5, 3, 6};
    size = 4;
    int n = 10;

    cout << count(S, size, n) << endl;
    cout << "Random numbers:" << endl;

    Random r(1024);
    cout << "Not that random:" << endl;
    cout << r.randomInt() << endl;

    return 0;
}
