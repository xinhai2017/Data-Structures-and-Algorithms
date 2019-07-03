#include<iostream>
#include<cmath>//使用pow 
#include<ctime>
using namespace std;
const int n=1e8;

int sum1(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=pow(-1,i);//表示（-1）^i 
    return sum;
}

int sum2(int n)
{
    int sum=0;
    if(n%2==0)
        sum=0;
    else
        sum=-1;
    return sum;
}

int main()
{
    time_t s,e,sumtime;
    s=clock();
    cout<<"sum:"<<sum1(n)<<endl;
//    cout<<"sum:"<<sum2(n)<<endl;
    e=clock();
    sumtime=e-s;
    cout<<"time:"<<sumtime<<endl;
    return 0;
}
