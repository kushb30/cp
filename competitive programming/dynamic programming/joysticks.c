#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,count=0,max1;
	cin>>a>>b;
	max1=a+b;
	for(int i=0;i<max1;i++){
		count++;
		if(a<=0||b<=0) break;
		if(a==1&&b==1) break;
		if(a>b) {
			a=a-2;
			b=b+1;
		}
		else {
			a=a+1;
			b=b-2;
		}
	//	cout<<a<<" "<<b<<endl;
	}
	cout<<count-1<<endl;
	return 0;
}