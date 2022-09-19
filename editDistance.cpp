#include<iostream>
#include <cstring>
using namespace std;
int editDistance(char* s1,char* s2,int i,int j,int dp[][1000])
{
    //base case
    if(j=0)
    {
        return i;
    }
    if(i=0)
    {
        return j;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

//recursive case
     if(s1[i-1] == s2[i-1])
     {
        return dp[i][j]=editDistance(s1,s2,i-1,j-1,dp);
     }else{
        return dp[i][j]=
        min(editDistance(s1,s2,i-1,j,dp),
        min(editDistance(s1,s2,i,j-1,dp),
        editDistance(s1,s2,i-1,j-1,dp)))+1
     }
     return dp[n-1][m-1];

}

int main()
{
    char s1[]="sunday";
    char s2[]="saturday";
    int dp[100][100];
    memset(dp,-1,sizeof dp);
    cout<<editDistance(s1,s2,strlen(s1),strlen(s2),dp)<<endl;
    return 0;

}