#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define INITIAL 0
#define VISITED 1
#define FINISHED 2
int adjmat[MAX][MAX],maxvert=-1,stat[MAX];
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
	if(count[vert]==0){
		cout<<vert<<" ";
		count[vert]++;
	}
	stat[vert]=VISITED;
	for(int i=0;i<=maxvert;i++){
		if(stat[i]==INITIAL&&adjmat[vert][i]==1){
			traversal_dfs(i);				
		}
	}
	stat[vert]=FINISHED;
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