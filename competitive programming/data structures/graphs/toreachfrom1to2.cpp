#include <bits/stdc++.h>
using namespace std;
int main() {
	int mat[100][100],n,adj[1000][1000],node=0,source,dest;
	cin>>n;
	int level[1000],stat[1000]={0};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin>>mat[i][j];
	}
	for(int i=0;i<n*n;i++)
		for(int j=0;j<n*n;j++)
			adj[i][j]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0; j<n; j++)
		{
			if(mat[i][j]==3)
			{
				if(mat[i-1][j]!=0 && i-1!=-1)
				{
					adj[node][node-1]=1;
					adj[node-1][node]=1;
				}
				if(mat[i+1][j]!=0 && i+1!=n)
				{
					adj[node][node+1]=1;
					adj[node+1][node]=1;
				}
				if(mat[i][j-1]!=0 && j-1!=-1)
				{
					adj[node][node-n]=1;
					adj[node-n][node]=1;
				}
				if(mat[i][j+1]!=0 && j+1!=n)
				{
					adj[node][node+n]=1;
					adj[node+n][node]=1;
				}
			}
			if(mat[i][j]==1)
				source=node;
			if(mat[i][j]==2)
				dest=node;
			node++;
		}
	}
	queue <int> q;
	q.push(source);
	level[source]=0;
	stat[source]=1;
	cout<<source<<endl;
	while(q.size())
	{
		int stor=q.front();
		for(int i=0;i<n*n;i++)
		{
			if(adj[stor][i]==1 && stat[i]==0)
			{
				q.push(i);
				stat[i]=1;
				level[i]=level[stor]+1;
			}
		}
		q.pop();
	}
	//for(int i=0;i<n*n;i++)
	//	cout<<level[i]<<endl;
	//cout<<dest<<endl;
	return 0;
}