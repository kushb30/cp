//if a graph has back edge than cycle is present in graph
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define INITIAL 0
#define VISITED 1
#define FINISHED 2
int adjmat[MAX][MAX],maxvert=-1,stat[MAX],dis[MAX],fin[MAX],tim=0;
void initialise(){
	for(int i=0;i<MAX;i++){
		stat[i]=INITIAL;
		for(int j=0;j<MAX;j++) {
			adjmat[i][j]=0;
		}
	}
}
void create_adjmat(int edge){
	int origin,dest;
	for(int i=0;i<edge;i++){
		cout<<"Enter the origin of edge "<<endl;
		cin>>origin;
		cout<<"Enter the destination of edge "<<endl;
		cin>>dest;
		maxvert=max(maxvert,max(origin,dest));
		adjmat[origin][dest]=1;
	}
}
void traversal_dfs(int vert){
	int count[10000]={0};
	tim++;
	dis[vert]=tim;
	stat[vert]=VISITED;
	for(int i=0;i<=maxvert;i++){
		if(adjmat[vert][i]==1){
			if(stat[i]==INITIAL){
				cout<<"The edge is a tree edge between "<<vert<<"and"<<i<<endl;
				traversal_dfs(i);
			}			
			else if(stat[i]==VISITED) cout<<"The edge is a Back edge "<<vert<<"and"<<i<<endl;
			else if(dis[vert]<dis[i]) cout<<"The edge is a Forward edge "<<vert<<"and"<<i<<endl;
			else cout<<"The edge is a cross edge "<<vert<<"and"<<i<<endl;	
		}
	}
	stat[vert]=FINISHED;
	fin[vert]=++tim;
}
int main(){
	int edge,start_vert;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	cout<<"Enter the starting vertex "<<endl;
	cin>>start_vert;
	traversal_dfs(start_vert);
	return 0;
}