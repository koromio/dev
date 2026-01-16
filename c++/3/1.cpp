#include<iostream>
using namespace std;

int main(){
    const int  p=12;
    cout<<"Please input your height(feet):______\b\b\b\b\b";
    int h;
    cin>>h;
    int height_in_inches=h*12;
    cout<<"Your height is "<<height_in_inches<<" inches."<<endl;
    return 0;
}
