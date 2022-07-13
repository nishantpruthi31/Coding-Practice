
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
    
    bool isSafe(int row,int col,vector<string> &board,int n)
    {
       int  rowCount=row;
        int colCount=col;
        
        // checking left diagonal condition
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            row--;
            col--;
        }
        
        col=colCount;
        row=rowCount;

        
       // checking left condition
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            col--;
        }
        
        col=colCount;
        row=rowCount;
        
        // checking niche wala diagonal
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            row++;
            col--;
        }
        return true;
    }
   void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n)
   {
       if(col==n)
       {
           ans.push_back(board);
           return;
       }
       
       // for  putting in column we are checking in which row we can place
       for(int row=0;row<n;row++)
       {
           if(isSafe(row,col,board,n))
           {
               board[row][col]='Q';
               solve(col+1,ans,board,n);
               board[row][col]='.';
           }
       }
       
   }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);        // one  board[i] reprsent one column 
        string s(n,'.');         // generating a string of n size which is ....
        
        for(int i=0;i<n;i++)
            board[i]=s;
        
        solve(0,ans,board,n);
        return ans;
        
    
    }
int main()
{
    int n=4;
   
    vector<vector<string>> req = solveNQueens(4);
    cout<<"{ ";
    for(int i=0;i<req.size();i++)
    {
        for(int j=0;j<req[0].size();j++)
        {
            cout<<req[i][j]<<" ";                    // string represnted column wise
           
        }
        if(i!=req.size()-1)
        cout<<","<<endl;
    }
    cout<<"}";
}