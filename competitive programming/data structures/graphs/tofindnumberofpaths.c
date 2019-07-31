#include <bits/stdc++.h>
using namespace std;
int adj[10000][10000],maxvert=-1;
void init(){
	for(int i=0;i<10000;i++){
		for(int j=0;j<10000;j++) adj[i][j]=0;
	}
}
void creategraph(int edg){
	int org,dest;
	for(int i=0;i<edg;i++){
		cout<<"origin and dest"<<endl;
		cin>>org>>dest;
		adj[org][dest]=1;
		maxvert=max(maxvert,max(org,dest));
	}
}
void bfs(int org,int dest){
	queue <int> q;
	q.push(org);
	int stor,count=0;
	while(q.size()!=0){
		stor=q.front();
		for(int i=0;i<=maxvert;i++){
			if(adj[stor][i]==1) {
				q.push(i);
				if(i==dest) count++;
			}
		}
		q.pop();
	}
	cout<<count<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int edg,org,dest;
		cin>>edg;
		init();
		cout<<"Enter the starting and the destination vertex "<<endl;
		cin>>org>>dest;
		creategraph(edg);
		bfs(org,dest);
	}
	return 0;
}