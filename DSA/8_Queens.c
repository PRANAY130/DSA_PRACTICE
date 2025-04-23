#include <stdio.h>

#define MAX 20

int board[MAX]; // board[i] = column position of queen at row i
int N;

void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row)
{
    if (row == N)
    {
        printSolution();
        return;
    }

    for (int col = 0; col < N; col++)
    {
        int safe = 1;
        for (int i = 0; i < row; i++)
        {
            if (board[i] == col ||           // same column
                board[i] - i == col - row || // same major diagonal
                board[i] + i == col + row)
            { // same minor diagonal
                safe = 0;
                break;
            }
        }

        if (safe)
        {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    printf("Enter the value of N (1-%d): ", MAX);
    scanf("%d", &N);

    if (N < 1 || N > MAX)
    {
        printf("Invalid input. Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Solutions to the %d-Queens problem:\n\n", N);
    solve(0);
    return 0;
}
