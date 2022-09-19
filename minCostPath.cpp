#include<iostream>
using namespace std;
int minCostPath(int cost[][4],int n,int m)
{
    int dp[1000][1000]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=cost[i][j];
            }else{
                dp[i][j]=min(
                    (j-1>=0 ? dp[i][j-1]:INT_MAX),
                    i-1>=0?dp[i-1][j]:INT_MAX)+cost[i][j];
            }

        }
    }


    //for print 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n-1][m-1];
}
int main()
{
int cost[][4]={
    {1,2,3,5},
    {8,1,1,6},
    {10,9,1,1},
    {5,3,6,1}
};
   cout<<minCostPath(cost,4,4);
   return 0;
}