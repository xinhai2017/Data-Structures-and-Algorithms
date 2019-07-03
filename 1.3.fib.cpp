#include <iostream>
#include<iomanip>
#include<ctime>
using namespace std;

long long fib1(int n)
{
    if(n<1)
        return -1;
    else if(n==1||n==2)
            return 1;
        else
            return fib1(n-1)+fib1(n-2);
}

long double fib2(int n)
{
    long double temp;
    if(n<1)
        return -1;
    //关键字：new，分配一个连续空间（创建数组）将前两项的数值存储起来，查找加和
    long double *a=new long double[n+1]; 
    a[1]=a[2]=1;
    for(int i=3;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2];
        cout<<a[i]<<endl;
    }
    temp=a[n];
    delete []a;//删除数组，释放动态空间 
    return temp;
}

int main()
{
    time_t s,e,sumtime;
    int n;
    cin>>n;//10 30 50 100
    s=clock();
    cout<<fixed<<setprecision(0);
    //cout<<"fib("<<n<<")="<<fib1(n)<<endl;
    cout<<"fib("<<n<<")="<<fib2(n)<<endl;
    e=clock();
    sumtime=e-s;
    cout<<"time:"<<sumtime<<endl;
    return 0;
}
