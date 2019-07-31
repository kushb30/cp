#include <bits/stdc++.h>
using namespace std;
#define max1 10000
int adj_mat[max1][max1],path_mat[max1][max1],temp_mat[max1][max1],maxrow=-1,maxcol=-1,maxvert;
void initialise(){
	for(int i=0;i<max1;i++){
		for(int j=0;j<max1;j++) { 
			adj_mat[i][j]=0;
		}
	}
}
void create_adjmat(int edge){
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
void create_pathmat(){
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++) temp_mat[i][j]=adj_mat[i][j];
	}
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++){
			for(int k=0;k<=maxvert;k++){
				if(temp_mat[j][k]==1) path_mat[j][k]=1;
				else if(temp_mat[j][i]==1 && temp_mat[i][k]==1) path_mat[j][k]=1;
				else path_mat[j][k]=0;
			}
		}
		for(int j=0;j<=maxvert;j++){
			for(int k=0;k<=maxvert;k++) temp_mat[j][k]=path_mat[j][k];
		}
	}
}
void display(){
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++) cout<<path_mat[i][j]<<" ";
		cout<<endl;	
	}
}
int main(){
	int edge;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	create_pathmat();
	display();
}