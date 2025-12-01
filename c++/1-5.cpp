#include<bits/stdc++.h>
using namespace std;

bool check(int x){
    while(x){
        if(x%10 == 2 || x%10 == 4) return false;
        x /= 10;
    }
    return true;
}
bool flag[2020];
signed main(){
    int ans = 0;
    for (int i = 1; i <= 2019;i++)if(check(i)) flag[i] = 1;
    for(int i=1;i<2019;i++)
        for (int j=i+1; j<=2019; j++){
            int k = 2019 - i - j;
            if(j<k && k<= 2019 && flag[i] && flag[j] && flag[k])
                ans++;
        }
    cout << ans << '\n';
    return 0;
}
