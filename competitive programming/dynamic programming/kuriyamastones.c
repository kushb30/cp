#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n],b[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		b[i]=arr[i];
	}
	sort(b,b+n);
	long long sumarr[n+1],u[n+1];
	sumarr[0]=0;
	u[0]=0;
	for(int i=0;i<n;i++) {
		sumarr[i+1]=sumarr[i]+arr[i];
		u[i+1]=u[i]+b[i];
	}
	int q;
	cin>>q;
	while(q--){
		int ty,l,r;
		cin>>ty>>l>>r;
		if(ty==1) cout<<sumarr[r]-sumarr[l]+arr[l-1]<<endl;
		else cout<<u[r]-u[l]+b[l-1]<<endl;
	}
	return 0;
}