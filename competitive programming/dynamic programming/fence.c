#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,min1,stor=1,sum=0;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		if(i<k-1) sum+=arr[i];
		else if(i==k-1){
			sum+=arr[i];
			min1=sum;
		}
		else {
			sum=sum+arr[i]-arr[i-k];
			if(sum<min1) {
				stor=i+2-k;
				min1=sum;
			}
		}
	//	cout<<sum<<endl;
	}
	cout<<stor<<endl;
	return 0;
}