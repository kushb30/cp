#include <bits/stdc++.h>
using namespace std;
int adj[10000][10000],maxvert=-1,level[10000],stat[10000];
void init(){
	for(int i=0;i<10000;i++){
		stat[i]=0;
		for(int j=0;j<10000;j++) adj[i][j]=0;
	}
}
void creategraph(int edg){
	int org,dest;
	for(int i=0;i<edg;i++){
		cin>>org>>dest;
		adj[org][dest]=1;
		maxvert=max(maxvert,max(org,dest));
	}
}
void bfs(){
	queue <int> q;
	q.push(0);
	int stor;
	level[0]=0;
	stat[0]=1;
	while(q.size()){
		stor=q.front();
		q.pop();
		for(int i=0;i<=maxvert;i++){
			if(adj[stor][i]){
				if(stat[i]==0){
					q.push(i);
					stat[i]=1;
					level[i]=level[stor]+1;
				}
			}
		}
	}
}
void nooflev(int edg){
	int count_eve=0,count_odd;
	for(int i=0;i<=maxvert;i++){
	//	cout<<level[i]<<endl;
		if(level[i]%2) count_odd++;
		else count_eve++;
	}
	cout<<count_eve*count_odd-edg<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int edg;
		cin>>edg;
		init();
		creategraph(edg);
		bfs();
		nooflev(edg);
	}
	return 0;
}