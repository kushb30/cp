#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define blue 1
#define red 2
int adjmat[MAX][MAX],maxvert=-1,stat[MAX];
void initialise(){
	for(int i=0;i<MAX;i++){
		stat[i]=0;
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
		adjmat[dest][origin]=1;
	}
}
int bfs(){
	queue <int> q;
	q.push(0);
	stat[0]=red;
	int stor,flag=0;
	while(q.size()){
		stor=q.front();
		for(int i=0;i<=maxvert;i++){
			if(adjmat[stor][i]==1 && stat[i]==0){
				if(stat[stor]==red)
					stat[i]=blue;
				else 
					stat[i]=red;
				q.push(i);
			}
			if(adjmat[stor][i]==1 && stat[i]==red && stat[stor]==red) 
				flag=1;
			if(adjmat[stor][i]==1 && stat[i]==blue && stat[stor]==blue) 
				flag=1;
		}
		q.pop();
	}
	return flag;
}
int main(){
	int edge,flag;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	flag=bfs();
	if(flag) cout<<"Not a bipartite"<<endl;
	else cout<<"bipartite"<<endl;
	return 0;
}