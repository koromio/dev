#include<iostream>
using namespace std;

int main(){
    const double f2i=1/12;
    const double i2m=0.0254;
    const double p2k=0.453592;
    cout<<"Please input your height and weight";
    int feet,inch,weight;
    cin>>feet>>inch>>weight;
    int height=(feet*f2i+inch)*i2m;
    cout<<"Your height is "<<height<<" m."<<endl;
    return 0;
}
