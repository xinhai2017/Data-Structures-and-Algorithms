#include<iostream>
#include<string>
using namespace std;

int next[1000+5];

void get_next(string t) //求模式串T的next函数值
{ 
	int j=1, k=0;
	next[1]=0;
	while (j<t.length()) //模式串t的长度
		if (k==0||t[j-1]==t[k-1])
			next[++j]=++k;
		else
			k=next[k];
	for(int i=1;i<=t.length();i++) 
		cout<<next[i]<<" ";
}

int KMP(string s,string t,int pos)
{
	get_next(t);
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
			j=next[j];  //j回退到next[j]
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
	cout<<KMP(s,t,pos)<<endl;
	return 0;
 } 
