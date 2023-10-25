#include <iostream>
#include <vector>
using namespace std;
void printBoard(const vector<vector<int>> &board)
{
    int N = board.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}
void printQueenPositions(const vector<vector<int>> &board)
{
    vector<int> positions;
    int N = board.size();
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (board[row][col] == 1)
            {
                positions.push_back(col);
                break;
            }
        }
    }
    cout << "Queen positions (in terms of column number for each row) : <";
    for (int i = 0; i < N; i++)
    {
        cout << positions[i] + 1;
        if (i != N - 1)
            cout << ", ";
    }
    cout << ">" << endl;
}
bool isSafe(const vector<vector<int>> &board, int row, int col)
{
    int N = board.size();
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }
    return true;
}
bool solveNQ(vector<vector<int>> &board, int col)
{
    int N = board.size();
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQ(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
void solveNQueens()
{
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!solveNQ(board, 0))
    {
        cout << "Solution does not exist." << endl;
    }
    else
    {
        cout << "Solution found:" << endl;
        printQueenPositions(board);
        printBoard(board);
    }
}
int main()
{
    solveNQueens();
    return 0;
}
