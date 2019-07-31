#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define INITIAL 0
#define WAITING 1
#define VISITED 2
int adjmat[MAX][MAX],maxvert=-1,stat[MAX],count=0;
void initialise();
void create_adjmat();
void rest_vertex();
void traversal_bfs(int start_vert);
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
void rest_vertex(){
	int start_vert;
	cout<<"The left vertices are "<<endl;
	for(int i=0;i<=maxvert;i++){
		if(stat[i]==INITIAL) cout<<i<<" ";
	}
	cout<<endl;
	cout<<"Enter the starting vertex "<<endl;
	cin>>start_vert;
	traversal_bfs(start_vert);
}
void traversal_bfs(int start_vert){
	queue <int> q;
	int stor;
	q.push(start_vert);
	stat[start_vert]=WAITING;
	while(q.size()!=0) {
		stor=q.front();
		q.pop();
		::count++;
		stat[stor]=VISITED;
		for(int i=0;i<=maxvert;i++){
			if(adjmat[stor][i]!=0&&stat[i]==INITIAL){
				q.push(i);
				stat[i]=WAITING;
			}
		}
		cout<<stor<<" ";
	}
	if(::count!=maxvert+1) rest_vertex();
}
int main(){
	int edge,start_vert;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	cout<<"Enter the starting vertex "<<endl;
	cin>>start_vert;
	traversal_bfs(start_vert);
}