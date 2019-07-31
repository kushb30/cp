#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
vector <int> adj_list[MAX];
int stat[MAX]={0};
void create_adjlist(int edge){
	int origin,dest;
	for(int i=0;i<edge;i++){
		cout<<"Enter the origin of edge "<<endl;
		cin>>origin;
		cout<<"Enter the destination of edge "<<endl;
		cin>>dest;
		adj_list[origin].push_back(dest);
	}
}
void bfs(int start_vert){
	queue <int> q;
	int stor;
	q.push(start_vert);
	stat[start_vert]=1;
	while(q.size()!=0){
		stor=q.front();
		q.pop();
		for(int i=0;i<adj_list[stor].size();i++){
			if(stat[adj_list[stor][i]]!=1) {
				q.push(adj_list[stor][i]);
				stat[adj_list[stor][i]]=1;
			}
		}
		cout<<stor<<" ";
	}
	cout<<endl;
}
int main(){
	int test_cases;
	cout<<"Enter the number of test cases "<<endl;
	cin>>test_cases;
	while(test_cases--){
		int edge,start_vert;
		cout<<"Enter the number of edges "<<endl;
		cin>>edge;
		create_adjlist(edge);
		cout<<"Enter the starting vertex "<<endl;
		cin>>start_vert;
		bfs(start_vert);
	}
}