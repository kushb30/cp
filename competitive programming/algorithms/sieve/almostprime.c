#include <bits/stdc++.h>
using namespace std;
int prime[3010],spf[3010];
void sieve (){
	for(int i=0;i<3010;i++) {
		prime[i]=1;
		spf[i]=i;
	}
	for(int i=2;i<3010;i++){
		if(prime[i]){
			for(int j=2*i;j<3010;j+=i){
					prime[j]=0;
					if(spf[j]==j) spf[j]=i;
			}
		}
	}
}
int main(){
	int n,stor,c2=0;
	cin>>n;
	stor=n;
	for(int i=1;i<=stor;i++){
		n=i;
		int count[3010]={0},c1=0;
		while(n!=1){
			count[spf[n]]++;
			n=n/spf[n];
		}
		for(int i=0;i<3010;i++){
			if(count[i]==1) c1++;
		}
		if(c1==2) c2++;
	}
	cout<<c2;
	return 0;
}