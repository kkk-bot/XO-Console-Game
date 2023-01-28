#include <iostream>
using namespace std;

bool isTheGameStill(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (board[i][j] <= 9)
                return true;
    }
    return false;
}
bool checkBoard(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == board[i][0] && board[i][j] == board[i][1] && board[i][j] == board[i][2]) // if it's horizantally equal ---
                return true;
            else if (board[i][j] == board[0][j] && board[i][j] == board[1][j] && board[i][j] == board[2][j]) // if it's vertically equal |
                return true;
            else if (board[i][j] == board[0][0] && board[i][j] == board[1][1] && board[i][j] == board[2][2]) // if it's Cross equal X
                return true;
            else if (board[i][j] == board[0][2] && board[i][j] == board[1][1] && board[i][j] == board[2][0]) // if it's Cross equal X
                return true;
        }

    }
    return false;
}
void printBoard(int board[3][3])
{
    // X = 88
    // O = 79
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] > 9)
                cout << (char)board[i][j];
            else
                cout << board[i][j];
            if (j < 2)
                cout << "  |  ";
        }

        cout << endl;
        if (i < 2)
            cout << "--------------" << endl;
    }
}
void changePlayer(char& x)
{
    if (x == 'X')
        x = 'O';
    else
        x = 'X';
}
bool checkIfValueExist(int x, int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (board[i][j] == x)
                return true;
    }
    return false;
}

int main(void)
{
    char player = 'X';
    int n;
    int board[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    // X = 88
    // O = 79
    printBoard(board);

    cout << "Player (X): ";

    while (isTheGameStill(board))
    {
        cin >> n;
        if (n < 1 || n>9)
        {
            cout << "invalid value: ";
            continue;
        }
        if (checkIfValueExist(n, board) == false)
        {
            cout << "Position already taken: ";
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                if (n == board[i][j])
                {
                    if (player == 'X')
                    {
                        board[i][j] = 88;
                    }
                    else
                    {
                        board[i][j] = 79;
                    }

                }
            cout << endl;
        }
        system("cls");
        printBoard(board);
        if (checkBoard(board))
            if (player == 'O')
            {
                cout << "The winner is Player (O)\n";
                return 0;
            }
            else
            {
                cout << "The winner is Player (X)\n";
                return 0;
            }

        if (isTheGameStill(board) == false)
        {
             cout << "The game is is Draw." << endl;
             return 0;
        }

        if (player == 'O')
        {
            cout << "Player (X): ";
            changePlayer(player);
        }
        else
        {
            cout << "Player (O): ";
            changePlayer(player);
        }
    }
    return 0;
}
