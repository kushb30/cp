#include <bits/stdc++.h>
using namespace std;
#define max1 10000
int edge,adj_mat[max1][max1],path_mat[max1][max1],mult[max1][max1],temp_mat[max1][max1],maxrow=-1,maxcol=-1,maxvert;
void initialise(){
	for(int i=0;i<max1;i++){
		for(int j=0;j<max1;j++) { 
			adj_mat[i][j]=0;
			mult[i][j]=0;
			path_mat[i][j]=0;
		}
	}
}
void create_adjmat(){
	cout<<"Yes ";
	int origin,dest;
	for(int i=0;i<edge;i++) {
		cout<<"Enter the origin of edge "<<endl;
		cin>>origin;
		cout<<"Enter the destination of edge "<<endl;
		cin>>dest;
		maxrow=max(maxrow,origin);
		maxcol=max(maxcol,dest);
		adj_mat[origin][dest]=1;
	}
	maxvert=max(maxrow,maxcol);
}
void multiply(){
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++){
			for(int k=0;k<=maxvert;k++) {
				mult[i][j]+=adj_mat[i][k]*temp_mat[k][j];
			}
		}
	}
}
void create_pathmat(){
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++) temp_mat[i][j]=adj_mat[i][j];
	}
	for(int i=0;i<=maxvert;i++){
		multiply();
		for(int j=0;j<=maxvert;j++){
			for(int k=0;k<=maxvert;k++) {
				path_mat[j][k]+=temp_mat[j][k];
				temp_mat[j][k]=mult[j][k];
			}
		}
	}
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++){
			path_mat[i][j]+=temp_mat[i][j];
			if(path_mat[i][j]) cout<<"1 ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
}
int main(){
	cout<<"Enter the no of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat();
	create_pathmat();
	return 0;
}