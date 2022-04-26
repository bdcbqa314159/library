#include <cppTutorial2>
#include <iostream>

using namespace std;

int main()
{
    cout << "Backtracking with N Queens problem" << endl;

    QueensProblem problem(8);
    problem.solve();

    cout << "Coloring problem" << endl;
    const vector<vector<int>> graphMatrix = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}};

    constexpr int numOfColors = 3;

    GraphColoring graphColoring(graphMatrix, numOfColors);
    graphColoring();

    cout << "Knight tour problem" << endl;
    KnightTour knightTour;
    knightTour.solveKnightTourProblem();

    return 0;
}