#include <cppTutorial3>
#include <iostream>
#include <utility>

using namespace std;

void testingSpiralPrint()
{

    int n, m;
    cin >> n >> m;
    int a[100][100];
    int i = 0;
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < m; j++)
        {
            a[k][j] = i;
            i++;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[k][j] << " ";
        }
        cout << endl;
    }

    cout << "Spiral!" << endl;
    spiralPrint(a, n, m);
    cout << endl;
}

void testingMangoTrees()
{
    int n = 6;
    char arr[100][100] = {
        ".##...",
        "#..##.",
        ".#....",
        ".##..#",
        "#..##.",
        ".#....",
    };

    // int n;
    // cin >> n;
    // cin.get();

    // for (int i = 0; i < n; i++)
    // {
    //     cin.getline(arr[i], 100);
    // }

    cout << "The farm:" << endl;
    cout << ".##...\n#..##.\n.#....\n.##..#\n#..##.\n.#...." << endl;
    cout << "the result:" << endl;
    cout << mangoTreeOptimized(arr, n) << endl;
}

int main()
{
    cout << "Working with multi dimensional Arrays." << endl;
    testingSpiralPrint();
    int n, m;
    cin >> n >> m;
    int a[100][100];
    int i = 0;
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < m; j++)
        {
            a[k][j] = i;
            i++;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[k][j] << " ";
        }
        cout << endl;
    }
    int j = 19;

    pair<int, int> out = search2D(a, n, m, j);
    cout << "research" << endl;
    cout << out.first << " " << out.second << endl;

    cout << endl;
    cout << "Mango Trees optimized" << endl;
    testingMangoTrees();

    return 0;
}
