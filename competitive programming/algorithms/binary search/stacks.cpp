#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int binary_search(int x){
	int beg=0, end=v.size()-1,mid;
	if(v.size()==1)
	{
		if(x<v[0])
			return beg;
		else 
			return -1;
	}
	if(v.size()==2){
		if(x<v[0]) return 0;
		else if(x<v[1]) return 1;
		else return -1;
	}
	while(beg<end){
		 mid=(beg+end)/2;
		if(x-v[mid]<0)
			end=mid;
		else beg=mid+1;
	}
	return beg;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,res;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		v.push_back(arr[0]);
		for(int i=1;i<n;i++){
		//	for(int j=0;j<v.size();j++) cout<<v[j]<<" ";
		//		cout<<endl;
			res=binary_search(arr[i]);
			if(res==-1) v.push_back(arr[i]);
			else {
				if(v[res]>arr[i]) v[res]=arr[i];
				else v.push_back(arr[i]);
			}
		}
		cout<<v.size()<<" ";
		for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
		v.erase(v.begin(),v.end());
		cout<<endl;
	}
	return 0;
}