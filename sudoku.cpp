#include<iostream>
#include<vector>
using namespace std;
const int n=9;


void print_sudoku(const vector<vector<int>>&grid )
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<"|";
        }
        cout<<endl;
    }
}
bool check_sudoku(vector<vector<int>>&grid,int row,int col,int num)
{
    for(int i=0;i<n;i++)
    {
        if((grid[i][col]==num)||(grid[row][i]==num))
        {
            return false;
        }
    }

     int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool solve(vector<vector<int>>& grid)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (check_sudoku(grid, row, col, num))
                    {
                        grid[row][col] = num;
                        if (solve(grid)) {
                            return true;
                        }
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false; 
            }
        }
    }
    return true;
}



int main ()
{
    cout<<"HELLO ENTER YOUR SUDOKU WITH BLANK SPACES AS ZEROES ";
vector<vector<int>>grid;
grid.resize(n, vector<int>(n, 0));

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cin>>grid[i][j];
    }
}
if (solve(grid)) {
        cout << "Sudoku Solved:\n";
        print_sudoku(grid);
    } 
    else {
        cout << "No solution exists.\n";
    }






    return 0;

}
