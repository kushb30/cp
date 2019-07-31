#include <bits/stdc++.h>
using namespace std;
#define NIL -1
#define INFI 9999999
#define MAX 10000
int adjmat[MAX][MAX],maxvert=-1,pathlen[MAX],pred[MAX],count=1;
void initialise (){
	for(int i=0;i<MAX;i++) {
		pathlen[i]=INFI;
		pred[i]=NIL;
		for(int j=0;j<MAX;j++) adjmat[i][j]=0;
	}
}
void create_adjmat(int edge){
	int origin,dest,wt;
	for(int i=0;i<edge;i++){
		cout<<"Enter the origin of edge "<<endl;
		cin>>origin;
		cout<<"Enter the destination of edge "<<endl;
		cin>>dest;
		cout<<"Enter the wieght associated with edge "<<endl;
		cin>>wt;
		maxvert=max(maxvert,max(origin,dest));
		adjmat[origin][dest]=wt;
	}
}
void bellmanford(int current_vert){
	vector <int> v;
	v.push_back(current_vert);
	while(v.size()!=0){
		if(::count>maxvert) break;
		for(int i=0;i<=maxvert;i++){
			bool flag=0;
			if(adjmat[v[0]][i]){
				if(pathlen[i]>pathlen[v[0]]+adjmat[v[0]][i]){
					pred[i]=v[0];
					pathlen[i]=pathlen[v[0]]+adjmat[v[0]][i];
					for(int j=0;j<v.size();j++){
						if(v[j]==i) {
							flag=1;
							break;
						}
					}
					if(flag==0) {
						v.push_back(i);
						if(i==current_vert) ::count++;
					}	
				}
			}
		}
		v.erase(v.begin());
	}
}
void print_path(int start_vert){
	int stor;
	if(::count==maxvert) cout<<"The graph contains negative cycle "<<endl;
	else {
		for(int i=0;i<=maxvert;i++){
			vector <int> v;
			stor=i;
			cout<<"The minimum distance from source vertex to vertex "<<i<<" is "<<pathlen[i]<<endl;
			cout<<"The path is "<<endl;
			while(stor!=start_vert){
				v.push_back(stor);
				stor=pred[stor];
			}
			v.push_back(stor);
			for(int j=v.size()-1;j>=0;j--) cout<<v[j]<<" ";
			cout<<endl;
			v.erase(v.begin(),v.end());
		}
	}
}
int main(){
	int edge,start_vert,vert;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	cout<<"Enter the source vertex "<<endl;
	cin>>start_vert;
	pathlen[start_vert]=0;
	bellmanford(start_vert);
	print_path(start_vert);
	return 0;
}