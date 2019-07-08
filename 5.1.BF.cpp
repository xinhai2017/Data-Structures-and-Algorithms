#include<iostream>
#include<string>
using namespace std;
//input:
// abaabaabeca
// abaabe
// 1

int BF(string s,string t,int pos)
{
	int i=pos,j=1,sum=0;
	int slen=s.length();
	int tlen=t.length();
	while(i<=slen&&j<=tlen)
    {
        sum++;
        if(s[i-1]==t[j-1]) //如果相等，则继续比较后面的字符
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2; //i回退到上一轮开始比较的下一个字符
			j=1;  //j回退到第1个字符
		}
    }
	cout<<"一共比较了"<<sum<<"次"<<endl;
	if (j>tlen) // 匹配成功
		return i-tlen;
	else
		return 0;
}

int main()
{
	string s,t;
	int pos;
	cin>>s>>t>>pos;
	cout<<BF(s,t,pos)<<endl;
	return 0;
 } 
