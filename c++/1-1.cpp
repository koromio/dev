#include<iostream>
using namespace std;
int cnt[10];
bool check(int x){
    while(x){
        int b=x%10;
        if(b==1){
            if (cnt[1]==0) return false;
            cnt[1]--;
        }
        x/=10;
    }
    return true;
}
signed main(){
    for(int i=0;i<10;i++) cnt[i]=2021;
    for(int i=1;;i++){
        if(!check(i)) return cout<<i-1<<'\n',0;
    }
    return 0;
}
