#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define INITIAL 0
#define VISITED 1
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
void traversal_dfs(int start_vert){
	stack <int> s;
	int stor,count[10000]={0};
	s.push(start_vert);
	while(s.size()!=0){
		stor=s.top();
		s.pop();
		stat[stor]=VISITED;
		for(int i=maxvert;i>=0;i--){
			if(stat[i]==INITIAL&&adjmat[stor][i]==1){
				s.push(i);
			}
		}
		if(count[stor]==0) {
			cout<<stor<<" ";
			count[stor]++;
		}
	}
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