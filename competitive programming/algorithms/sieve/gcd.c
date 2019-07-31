#include <bits/stdc++.h>
using namespace std;
int sum[10000001][2];
void sieve (){
	for(int i=0;i<10000001;i++) {
		sum[i][0]=0;
		sum[i][1]=0;
	}
	for(int i=2;i<10000001;i++){
			for(int j=2*i;j<10000001;j+=i){
					sum[j][0]+=j/i;
					sum[j][1]++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	sieve();
	while(t--){
		int n;
		cin>>n;
		cout<<sum[n][0]+(n-sum[n][1]-1)*n+1<<"\n";
	}
	return 0;
}