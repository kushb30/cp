#include <bits/stdc++.h>
using namespace std;
int main(){
	int arr[10010],k=0,n,stor,ind=2,sum;
	cin>>n;
	arr[0]=19;
	while(k!=10000){
		stor=19+(ind-1)*9;
		sum=0;
		while(stor){
			sum+=stor%10;
			stor=stor/10;
		}
		if(sum==10) {
			k++;
			arr[k]=19+(ind-1)*9;
		}
		ind++;
	}
	cout<<arr[n-1];
}