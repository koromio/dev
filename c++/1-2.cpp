#include<bits/stdc++.h>
using namespace std;
int date,mouth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//判断日期是否合法
string check(int date){
    string s=to_string(date),t=to_string(date);
    reverse(t.begin(),t.end());
    s+=t;
    int year=stoi(s.substr(0,4)),m=stoi(s.substr(4,2)),d=stoi(s.substr(6,2));
    if(m<1 || m>12||d<1 || d>mouth[m]) return "-1";
    return s;
}
//判断日期是否是 ABABBABA 型回文
string check2(int date){
    string s=to_string(date),t=to_string(date);
    reverse(t.begin(),t.end());
    s+=t;
    if(s[0]==s[2] && s[2]==s[5] && s[5]==s[7] && s[1]==s[3] && s[3]==s[4] && s[4]==s[6])
        return s;
    return "-1";
}
signed main(){
    cin>>date;
    string ans1="";
    for(int i=date/10000;;i++){
        if(check(i)=="-1"||check(i)==to_string(date)) continue;
        if(ans1=="") ans1=check(i);
        if(check2(i)!="-1")return cout<<ans1<<'\n'<<check2(i)<<'\n',0;
    }
    return 0;
}
