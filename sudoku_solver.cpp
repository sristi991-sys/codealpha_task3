#include <iostream>
using namespace std;

const int SIZE = 9;

void printBoard(int board[SIZE][SIZE])
{
    cout<<"\n=================================\n";

    for(int i=0;i<SIZE;i++)
    {
        if(i%3==0 && i!=0)
            cout<<"---------------------------------\n";

        for(int j=0;j<SIZE;j++)
        {
            if(j%3==0)
                cout<<"| ";

            cout<<board[i][j]<<" ";
        }

        cout<<"|\n";
    }

    cout<<"=================================\n";
}

bool isSafe(int board[SIZE][SIZE], int row, int col, int num)
{
    for(int x=0;x<9;x++)
        if(board[row][x]==num) return false;

    for(int x=0;x<9;x++)
        if(board[x][col]==num) return false;

    int startRow = row-row%3;
    int startCol = col-col%3;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[startRow+i][startCol+j]==num)
                return false;

    return true;
}

bool solveSudoku(int board[SIZE][SIZE])
{
    int row=-1,col=-1;
    bool empty=false;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                row=i;
                col=j;
                empty=true;
                break;
            }
        }
        if(empty) break;
    }

    if(!empty) return true;

    for(int num=1;num<=9;num++)
    {
        if(isSafe(board,row,col,num))
        {
            board[row][col]=num;

            if(solveSudoku(board))
                return true;

            board[row][col]=0;
        }
    }

    return false;
}

int main()
{
    int board[9][9];

    cout<<"===== SUDOKU SOLVER =====\n";
    cout<<"Enter Sudoku Puzzle (Use 0 for empty cells)\n";

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>board[i][j];

    if(solveSudoku(board))
    {
        cout<<"\nSolved Puzzle:\n";
        printBoard(board);
    }
    else
        cout<<"\nNo Solution Exists!\n";

    return 0;
}
