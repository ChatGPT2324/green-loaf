#include<bits/stdc++.h>
using namespace std;
vector<int> board;
int n;
bool isSafe(int row,int col){
    for(int r=0;r<row;r++){
        int c=board[r];
        if(c==col) return false;
        else if(row-col==r-c) return false;
        else if(row+col==r+c) return false;

    }
    return true;
}
bool nqueens(int row){
if(row==n) return true;
for(int col=0;col<n;col++){
    if(isSafe(row,col)){
        board[row]=col;
        if(nqueens(row+1))
            return true;
        board[row]=-1;
    }
}
return false;
}
int main(){
   n=4;
   board.assign(n,-1);
   nqueens(0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i]==j){
                cout<<"Q";
            }else{
                cout<<".";
            }

        }
        cout<<"\n";
    }
    return 0;
}