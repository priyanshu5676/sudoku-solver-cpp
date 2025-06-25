#include <iostream>
using namespace std;

const int N = 9;

void printGrid(int grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
            if((j+1)%3==0 && j!=8) cout<<"| ";
        }
        cout<<"\n";
        if((i+1)%3==0 && i!=8) cout<<"---------------------"<<endl;
    }
}

bool isSafe(int row,int col,int x,int grid[N][N]){
    for(int k=0;k<N;k++){
        if(grid[row][k]==x || grid[k][col]==x) return false;
    }
    int rs =  row - row % 3;
    int cs =  col - col % 3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+rs][j+cs]==x) return false;
        }
    }
    return true;
}

bool solve(int grid[N][N]){
    int i;
    int j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(grid[i][j]==0) break;
        }
    }
    if(i==N && j==N) return true;
    for(int x=1;x<=N;x++){
        if(isSafe(i,j,x,grid)){
            grid[i][j] = x;
            if(solve(grid)) return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

int main(){
      int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    cout<<"Original Sudoku:\n";
    printGrid(grid);
    if(solve(grid)){
        cout<<"Solved Sudoku:\n";
        printGrid(grid);
    }
    else cout<<"No solution exists.\n";

    return 0;
}