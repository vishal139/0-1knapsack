/*
Problem Description

Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

Also given an integer C which represents knapsack capacity.

Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

NOTE:

You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/
#include<iostream>
#include<vector>
using namespace std;

// function this will return the max value of subset of A 
int solve(vector<int> &A, vector<int> &B, int C) {

    int n = A.size();
    int dp[n+1][C+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=C;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j] = 0;
            }
            else if(B[i-1]<=j)
            {
                dp[i][j] = max((A[i-1] + dp[i-1][j-B[i-1]]),dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][C];
}

int main()
{
    vector<int> A , B;
    int C;
    A = {60,100,120};
    B = {10,20,30};
    C = 10;
    int ans = solve(A,B,C);
    cout<<ans;
    return 0;
}



