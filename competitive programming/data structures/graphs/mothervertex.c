#include <bits/stdc++.h>
using namespace std;
#define max1 10000
int adj_mat[max1][max1],maxvert=-1,status[max1];
void initialise(){
	for(int i=0;i<max1;i++){
		status[i]=0;
		for(int j=0;j<max1;j++) { 
			adj_mat[i][j]=0;
		}
	}
}
void create_adjmat(int edge){
	int origin,dest;
	for(int i=0;i<edge;i++) {
		cout<<"Enter the origin of edge "<<endl;
		cin>>origin;
		cout<<"Enter the destination of edge "<<endl;
		cin>>dest;
		maxvert=max(maxvert,max(origin,dest));
		adj_mat[origin][dest]=1;
	}
}
void dfs(int vert){
	for(int i=0;i<=maxvert;i++){
		if(adj_mat[vert][i]==1 && status[i]==0){
			status[i]=1;
			dfs(i);
		}
	}
}
void mother_vertex()
{
	int mother_vert,count=0;
	for(int i=0;i<=maxvert;i++)
	{
		if(status[i]==0){
			dfs(i);
			mother_vert=i;
		}
	}
	for(int i=0;i<=maxvert;i++) status[i]=0;
	dfs(mother_vert);
	for(int i=0;i<=maxvert;i++)
		if(status[i])
			count++;
	if(count==maxvert) cout<<"The mother vertex is : "<<mother_vert<<endl;
	else cout<<"No mother vertex exists"<<endl;	
}
int main() {
	int edge;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	mother_vertex();
	return 0;
}