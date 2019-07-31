#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define INITIAL 0
#define WAITING 1
#define VISITED 2
int adjmat[MAX][MAX],maxvert=-1,stat[MAX],dis[MAX],pred[MAX],count=0;
void initialise(){
	for(int i=0;i<MAX;i++){
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
void short_dis(int vert,int pre){
	dis[vert]=dis[pre]+1;
	pred[vert]=pre;
	
}
void traversal_bfs(int start_vert){
	queue <int> q;
	int stor,pre=-1;
	for(int i=0;i<=maxvert;i++) stat[i]=INITIAL;
	q.push(start_vert);
	stat[start_vert]=WAITING;
	dis[start_vert]=0;
	pred[start_vert]=-1;
	while(q.size()!=0) {
		stor=q.front();
		q.pop();
		stat[stor]=VISITED;
		for(int i=0;i<=maxvert;i++){
			if(adjmat[stor][i]!=0&&stat[i]==INITIAL){
				q.push(i);
				stat[i]=WAITING;
				short_dis( i, stor);
			}
		}
		cout<<stor<<" ";
	}
}
void printdis(int vert){
	vector <int> v;
	int num=dis[vert];
	cout<<"The shortest distance is "<<dis[vert]<<endl;
	cout<<"The path is "<<endl;
	for(int i=0;i<=num;i++){
		v.push_back(vert);
		vert=pred[vert];
	}
	for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";
	cout<<endl;
}
int main(){
	int edge,start_vert,vert;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	cout<<"Enter the starting vertex "<<endl;
	cin>>start_vert;
	traversal_bfs(start_vert);
	cout<<endl;
	cout<<"Enter the vertex to which shortest distance is to be calculated "<<endl;
	cin>>vert;
	printdis(vert);
	return 0;
}