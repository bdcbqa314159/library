#ifndef BACKTRACKING_H
#define BACKTRACKING_H
#include <vector>
#include <array>

class QueensProblem
{

    std::vector<std::vector<int>> chessTable;
    int numOfQueens = 0;

public:
    QueensProblem(int numOfQueens);
    void solve();

private:
    bool setQueens(int colIndex);
    bool isPlaceValid(int rowIndex, int colIndex) const;
    void printQueens() const;
};

class GraphColoring
{
    std::vector<std::vector<int>> graphMatrix;
    int numOfColors;
    std::vector<int> colors;

public:
    GraphColoring(const std::vector<std::vector<int>> &graph, int numOfColors);
    void operator()();

private:
    bool solve(size_t nodeIndex);
    bool isColorValid(size_t nodeIndex, size_t colorIndex);
    void showResult();
};

class KnightTour
{
    std::vector<std::vector<int>> solutionMatrix;
    const static std::array<int, 8> xMoves;
    const static std::array<int, 8> yMoves;

    constexpr static int BOARD_SIZE = 8;

public:
    KnightTour();
    void solveKnightTourProblem();
    bool solveProblem(int stepCount, int x, int y);
    bool isValidMove(int x, int y);
    void showSolution();

private:
    void initializeBoard();
};

#endif