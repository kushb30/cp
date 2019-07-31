#include <bits/stdc++.h>
using namespace std;
int prime[100000];
vector <int> v;
void sieve (){
	for(int i=0;i<sqrt(1000000000);i++) prime[i]=1;
	for(int i=2;i<sqrt(1000000000);i++){
	//	cout<<prime[i]<<endl;
		if(prime[i]){
			v.push_back(i);
			for(int j=2*i;j<sqrt(1000000000);j+=i){
					prime[j]=0;
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	sieve();
	while(t--){
		bool flag=0;
		int m,n;
		cin>>m>>n;
		//cout<<prime[2];
		for(int i=m;i<=n;i++) {
			flag=0;
			for(int j=0;j<v.size();j++){
				if(i%v[j]==0&&i!=v[j]) {
					flag=1;
					break;
				}
			}
			if(flag==0&&i!=1) cout<<i<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}