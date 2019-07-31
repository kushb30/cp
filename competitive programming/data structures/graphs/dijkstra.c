#include <bits/stdc++.h>
using namespace std;
#define NIL -1
#define INFI 9999999
#define TEMP 0
#define PERM 1
#define MAX 10000
int adjmat[MAX][MAX],maxvert=-1,stat[MAX],pathlen[MAX],pred[MAX];
void initialise (){
	for(int i=0;i<MAX;i++) {
		stat[i]=TEMP;
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
int determine_currentvert(){
	int min_pathlen=INFI;
	int current_vert=NIL;
	for(int i=0;i<=maxvert;i++){
		if(min_pathlen>pathlen[i]&&stat[i]==TEMP){
			min_pathlen=pathlen[i];
			current_vert=i;
		}
	}
	return current_vert;
}
void dijkstra(int current_vert){
	while(1){
		stat[current_vert]=PERM;
		if(current_vert==NIL) break;
		for(int i=0;i<=maxvert;i++){
			if(adjmat[current_vert][i]&&stat[i]==TEMP){
				if(adjmat[current_vert][i]+pathlen[current_vert]<pathlen[i]){
					pred[i]=current_vert;
					pathlen[i]=adjmat[current_vert][i]+pathlen[current_vert];
				}
			}
		}
		current_vert=determine_currentvert();
	}
}
void print_path(int start_vert){
	int stor;
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
int main(){
	int edge,start_vert,vert;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	cout<<"Enter the source vertex "<<endl;
	cin>>start_vert;
	pathlen[start_vert]=0;
	dijkstra(start_vert);
	print_path(start_vert);
	return 0;
}