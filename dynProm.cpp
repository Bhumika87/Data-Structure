#include<iostream>
using namespace std;

int fib(int n,int *dp)
{
    if(n<=1)
    {
       dp[n]=n;//return krna s phle store
       return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
int bottomUp(int n)
{
    int *dp= new int[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int dp[1000];
    memset(dp,-1,sizeof dp);
    cout<<fib(n,dp)<<endl;
    cout<<bottomUp(n);
    return 0;
}