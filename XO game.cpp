#include <iostream>
#include <string>
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
                cout << ' ';
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
void tutorial()
{
    int help = 1;
    cout << "\n\nHELP:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << help;
            if (j < 2)
                cout << "  |  ";
            help++;
        }

        cout << endl;
        if (i < 2)
            cout << "--------------" << endl;
    }
    cout << "\n\n";
}
void checkTurn(char player)
{
    if (player == 'X')
        cout << "Player (X): ";
    else
        cout << "Player (O): ";
}



int main()
{
    srand(time(0));
    bool isComputer = false;
    int n;
    char list[2] = {'X', 'O'};
    char jika = 1 + (rand() % 2);
    char player = list[jika-1];
    int choice;
    int board[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    // X = 88
    // O = 79
    

    cout << " ------- XO game -------\n";
    cout << "1. Play against computer\n";
    cout << "2. Play against player\n";
    cout << "3. Exit\n";
    cin >> choice;
    while (choice < 1 || choice>3)
    {
        cout << "Invalid choice: ";
        cin >> choice;
    }
    if (choice == 3)
        return 0;
    printBoard(board);
    tutorial();
    checkTurn(player);
    while (isTheGameStill(board))
    {
        if (choice == 1)
            if (isComputer)
            {
                n = 1+(rand() % 9);
                while (!checkIfValueExist(n, board))
                {
                    n = rand() % 9 + 1;
                }
            }
            else
            {
                cin >> n;
            }
        else if (choice == 2)
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
        tutorial();
        if (checkBoard(board))
        {
            if (isComputer && choice == 1)
                cout << "The winner is Computer\n";

            if (player == 'X')
                cout << "The winner is Player (X)";
            else if (player == 'O')
                cout << "The winner is Player (O)";
            return 0;
        }

            

        if (isTheGameStill(board) == false)
        {
             cout << "The game is Draw." << endl;
             return 0;
        }
        changePlayer(player);
        checkTurn(player);
        if (isComputer)
            isComputer = false;
        else
            isComputer = true;
    }
    return 0;
}
