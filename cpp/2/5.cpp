#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter a Celsius value:";
    float celsius;
    cin>>celsius;
    float fahrenheit=(celsius*9/5)+32;
    cout<<"Fahrenheit value is:"<<fahrenheit<<endl;
    return 0;
}
