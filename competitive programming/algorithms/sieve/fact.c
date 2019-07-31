#include <bits/stdc++.h>
using namespace std;
int prime[10000001],spf[10000001];
void sieve (){
	for(int i=0;i<10000001;i++) {
		prime[i]=1;
		spf[i]=i;
	}
	for(int i=2;i<10000001;i++){
		if(prime[i]){
			for(int j=2*i;j<10000001;j+=i){
					prime[j]=0;
					if(spf[j]==j) spf[j]=i;
			}
		}
	}
}
int main(){
//	ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
	int n;
	sieve();
	while(scanf("%d",&n)==1){
		if(n!=1) printf("1 x ");
		while(n!=spf[n]){
			printf("%d x ",spf[n]);
			n=n/spf[n];
		}
		printf("%d\n",n);
	}
	return 0;
}