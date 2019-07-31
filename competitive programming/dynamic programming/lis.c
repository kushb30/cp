#include <bits/stdc++.h>
using namespace std;
int lis_comp(int arr[],int lis[],int size_arr){
	for(int i=1;i<size_arr;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]&&lis[i]<lis[j]+1) lis[i]=lis[j]+1;
		}
	}
	sort(lis,lis+size_arr);
	return lis[size_arr-1];
}
int main(){
	int test_cases;
	cin>>test_cases;
	while(test_cases--){
		int size_arr,maxlen;
		cin>>size_arr;
		int arr[size_arr],lis[size_arr]={1};
		for(int i=0;i<size_arr;i++) cin>>arr[i];
		maxlen=lis_comp(arr,lis,size_arr);
		cout<<maxlen<<endl;	
	}
}