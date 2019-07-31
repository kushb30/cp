#include <bits/stdc++.h>
using namespace std;
int main(){
	int num,count=1,stor,max1=-1;
	cin>>num;
	int arr[num];
	for(int i=0;i<num;i++) cin>>arr[i];
	stor=arr[0];
	for(int i=1;i<num;i++){
		if(arr[i]>=stor) {
			count++;
			stor=arr[i];
		}
		else {
			max1=max(max1,count);
			count=1;
			stor=arr[i];
		}
	}
	cout<<max(max1,count)<<endl;
	return 0;
}