#include <bits/stdc++.h>
using namespace std;
#define pii pair<int , int > 
void bfs(int m,int n,int d){
	int stat[m+1][n+1],u,v;
	for(int i=0; i<=m; i++)
		for(int j=0; j<=n; j++)
			stat[i][j]=0;
	queue <pii> q;
	q.push(pii(0,0));
	stat[0][0]=1;
	while(1) {
		u=q.front().first;
		v=q.front().second;
		cout<<u<<" , "<<v<<endl;
		if((q.front().first == d && q.front().second == 0) || (q.front().first == 0 && q.front().second == d)) break;
		if(stat[0][v]==0) {
			q.push(pii(0,v));
			stat[0][v]=1;
		}
		if(stat[u][0]==0) {
			stat[u][0]=1;
			q.push(pii(u,0));
		}
		if(stat[m][v]==0) {
			stat[m][v]=1;		
			q.push(pii(m,v));
		}
		if(stat[u][n]==0) {
			stat[u][n]=1;
			q.push(pii(u,n));
		}
		if(u+v<=m && stat[u+v][0]==0) {
			stat[u+v][0]=1;
			q.push(pii(u+v,0));
		}
		if(u+v>=m && stat[m][u+v-m] == 0) {
			stat[m][u+v-m]=1;
			q.push(pii(m,u+v-m));
		}
		if(u+v<=n && stat[0][n]==0) {
			stat[0][u+v]=1;
			q.push(pii(0,u+v));
		}
		if(u+v>=n && stat[u+v-n][n] == 0) {
			stat[u+v-n][n]=1;
			q.push(pii(u+v-n,n));
		}
		q.pop();
	} 
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int m,n,d;
		cout<<"Enter the amount of the m litre jug "<<endl;
		cin>>m;
		cout<<"Enter the amount of the n litre jug "<<endl;
		cin>>n;
		cout<<"Enter the amount of the d litre jug "<<endl;
		cin>>d;
		bfs(m,n,d);
	}
	return 0;
}