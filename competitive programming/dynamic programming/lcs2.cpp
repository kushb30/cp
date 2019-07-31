#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str1,str2,str3;
	cin>>str1>>str2;
	int x[str1.size()+1][str2.size()+1],y[str1.size()+1][str2.size()+1],dp[str1.size()+1][str2.size()+1];
	char v[str1.size()+1][str2.size()+1];
	for(int i=0;i<=str1.size();i++)
	{
		for(int j=0;j<=str2.size();j++)
		{
			if(i==0 || j==0) {
				v[i][j]='\0';
				x[i][j]=i;
				y[i][j]=j;
				dp[i][j]=0;
			}
			else
			{
				if(str1[i-1]==str2[j-1])
				{
					//str3=v[i-1][j-1]+str1[j-1];
					v[i][j]=str1[i-1];
					x[i][j]=i-1;
					y[i][j]=j-1;
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else 
				{
					if(dp[i-1][j]>=dp[i][j-1])
					{
						dp[i][j]=dp[i-1][j];
						v[i][j]=v[i-1][j];
						x[i][j]=x[i-1][j];
						y[i][j]=y[i-1][j];
					}
					else
					{
						dp[i][j]=dp[i][j-1];
						v[i][j]=v[i][j-1];
						x[i][j]=x[i][j-1];
						y[i][j]=y[i][j-1];
					}
				}	
			}
		}
	}
	int m=str1.size(),n=str2.size(),a,b;
	while(1)
	{
		if(v[m][n]=='\0') break;
	//	cout<<v[m][n];
		str3=v[m][n]+str3;
		a=m;
		b=n;
		m=x[a][b];
		n=y[a][b];
	}
	cout<<str3<<endl;
	return 0;
}