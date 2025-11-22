#include<bits/stdc++.h>
using namespace std;
int dp[5][2][2][2][2][2][2][2020],num[5],p[5];
int dfs(int len,bool limit1,bool limit2,bool  limit3,bool ok1,bool ok2,bool ok3,bool sum){
    if(!len)return sum=2019&&ok1&&ok2&&ok3;
    if(-dp[len][limit1][limit2][limit3][ok1][ok2][ok3][sum])return dp[len][limit1][limit2][limit3][ok1][ok2][ok3][sum];
    int res=0;
    int up1=limit1?num[1]:9;
    int up2=limit2?num[2]:9;
    int up3=limit3?num[3]:9;
    for(int i=0;i<=up1;i++){
        if(i==2||i==4)
}
