#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,a[N],flag[N];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)flag[j]=0;
        int num=1,pos=i,sum=0,cnt=0;
        while(1){
            if(cnt==n||num>n)break;
            if(flag[pos]==1){
                if(pos==n)pos=1;
                else pos++;
                continue;
            }
            if(num==a[pos]){
                sum+=a[pos];
                cnt++;
                num=1;
                flag[pos]=1;
                if(pos==n)pos=1;
                else pos++;
            } else{
                num++;
                if(pos==n)pos=1;
                else  pos++;
            }
        }
    if(sum>ans)ans=sum;
    }
    cout<<ans<<'\n';
    return 0;
}
