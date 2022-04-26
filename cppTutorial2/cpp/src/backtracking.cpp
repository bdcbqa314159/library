#include "../include/cppTutorial2_bits/backtracking.hpp"
#include <iostream>
#include <iomanip>

QueensProblem::QueensProblem(int numOfQueens) : numOfQueens(numOfQueens)
{
    chessTable.resize(numOfQueens);
    for (auto &chessRow : chessTable)
        chessRow.resize(numOfQueens);
}

void QueensProblem::solve()
{
    if (setQueens(0))
        printQueens();
    else
        std::cout << "There is no solution..." << std::endl;
}

bool QueensProblem::setQueens(int colIndex)
{
    if (colIndex == numOfQueens)
        return true;

    for (int rowIndex = 0; rowIndex < numOfQueens; rowIndex++)
    {
        if (isPlaceValid(rowIndex, colIndex))
        {
            chessTable[rowIndex][colIndex] = 1;
            if (setQueens(colIndex + 1))
                return true;

            chessTable[rowIndex][colIndex] = 0;
        }
    }
    return false;
}

bool QueensProblem::isPlaceValid(int rowIndex, int colIndex) const
{
    for (int i = 0; i < colIndex; i++)
    {
        if (chessTable[rowIndex][i] == 1)
            return false;
    }

    for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--)
    {
        if (chessTable[i][j] == 1)
            return false;
    }

    for (int i = rowIndex, j = colIndex; i < numOfQueens && j >= 0; i++, j--)
    {
        if (chessTable[i][j] == 1)
            return false;
    }
    return true;
}

void QueensProblem::printQueens() const
{
    for (size_t i = 0; i < chessTable.size(); i++)
    {
        for (size_t j = 0; j < chessTable[0].size(); j++)
        {
            if (chessTable[i][j] == 1)
            {
                std::cout << " * ";
            }
            else
                std::cout << " - ";
        }
        std::cout << std::endl;
    }
}

GraphColoring::GraphColoring(const std::vector<std::vector<int>> &graph, int numOfColors) : graphMatrix(graph), numOfColors(numOfColors)
{
    colors.resize(numOfColors);
}

void GraphColoring::operator()()
{
    if (solve(0))
        showResult();
    else
        std::cout << "No solution with the given parameters" << std::endl;
}

bool GraphColoring::solve(size_t nodeIndex)
{
    if (nodeIndex == graphMatrix.size())
        return true;
    for (int colorIndex = 1; colorIndex <= numOfColors; colorIndex++)
    {
        if (isColorValid(nodeIndex, colorIndex))
        {
            colors[nodeIndex] = colorIndex;
            if (solve(nodeIndex + 1))
                return true;
        }
    }
    return false;
}

bool GraphColoring::isColorValid(size_t nodeIndex, size_t colorIndex)
{
    for (size_t i = 0; i < graphMatrix.size(); i++)
        if (graphMatrix[nodeIndex][i] == 1 && colorIndex == colors[i])
            return false;
    return true;
}

void GraphColoring::showResult()
{
    for (size_t i = 0; i < graphMatrix.size(); i++)
        std::cout << "Node " << (i + 1) << " has color index: " << colors[i] << std::endl;
    std::cout << std::endl;
}

const std::array<int, 8> KnightTour::xMoves = {2, 1, -1, -2, -2, -1, 1, 2};
const std::array<int, 8> KnightTour::yMoves = {1, 2, 2, 1, -1, -2, -2, -1};

KnightTour::KnightTour()
{
    solutionMatrix.resize(BOARD_SIZE);

    for (auto &subMatrix : solutionMatrix)
        subMatrix.resize(BOARD_SIZE);

    initializeBoard();
}

void KnightTour::solveKnightTourProblem()
{
    solutionMatrix[0][0] = 0;
    if (!solveProblem(1, 0, 0))
    {
        std::cout << "No feasible solution found...";
        return;
    }
    showSolution();
}

bool KnightTour::solveProblem(int stepCount, int x, int y)
{
    if (stepCount == BOARD_SIZE * BOARD_SIZE)
        return true;
    for (size_t i = 0; i < xMoves.size(); i++)
    {
        int nextX = x + xMoves[i];
        int nextY = y + yMoves[i];

        if (isValidMove(nextX, nextY))
        {
            solutionMatrix[nextX][nextY] = stepCount;

            if (solveProblem(stepCount + 1, nextX, nextY))
                return true;
            solutionMatrix[nextX][nextY] = INT_MIN;
        }
    }
    return false;
}

bool KnightTour::isValidMove(int x, int y)
{
    if (x < 0 || x >= BOARD_SIZE)
        return false;
    if (y < 0 || y >= BOARD_SIZE)
        return false;
    if (solutionMatrix[x][y] != INT_MIN)
        return false;
    return true;
}

void KnightTour::showSolution()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << std::left;
        for (int j = 0; j < BOARD_SIZE; j++)
            std::cout << std::setw(2) << solutionMatrix[i][j] << std::setw(2) << ' ';
        std::cout << std::endl;
    }
}

void KnightTour::initializeBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            solutionMatrix[i][j] = INT_MIN;
}