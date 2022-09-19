#include<iostream>
using namespace std;
//n is no of item
int knapsack(int *price,int *weight,int n,int cap,int dp[][100])
{
    if(n ==0  || cap==0)
    {
        return dp[n][cap]=0;

    }
    if(dp[n][cap] != -1)
    {
        return dp[n][cap];
    }
    //recursive case
    int op1,opt2;
    op1=opt2=INT_MIN;
    if(weight[n-1]<=cap)
    {
        op1=price[n-1]+knapsack(price,weight,n-1,cap-weight[n-1],dp);

    }
    opt2=0+knapsack(price,weight,n-1,cap,dp);
    return dp[n][cap] = max(op1,opt2);

}
int bottomUp(int *pri,int *wt,int n,int capacity)
{
    int dp[100][100]={0};
    int opt1,opt2;
    for(int N=1;N<=n;++N)
    {
        for(int cap=1;cap<=capacity;++cap)
        {
            opt1=opt2=INT_MIN;
            if(wt[N-1] <= cap)
            {
                opt1=pri[N-1]+dp[N-1][cap-wt[N-1]];
            }
            opt2=0+dp[N-1][cap];
            dp[N][cap]=max(opt1,opt2);
            
        }
    }
    for(int N=0;N<=n;++N)
    {
        for(int cap=0;cap<=capacity;++cap)
        {
            cout<<dp[N][cap]<<"  ";
        }
        cout<<endl;
    }
    return dp[n][capacity];
}
int main()
{
    int pri[]={4,6,3,5};
    int wei[]={2,3,4,2};
    int cap=6;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    int n=sizeof(pri)/sizeof(int);
    cout<<knapsack(pri,wei,n,cap,dp)<<endl;
    cout<<bottomUp(pri,wei,n,cap)<<endl;


    return 0;
}