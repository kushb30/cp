#include <bits/stdc++.h>
using namespace std;
#define max1 10000
#define INFI 999999
#define NIL -1
int adj_mat[max1][max1],path_mat[max1][max1],temp_mat[max1][max1],maxvert=-1,pred[max1][max1];
void initialise(){
	for(int i=0;i<max1;i++){
		for(int j=0;j<max1;j++) { 
			adj_mat[i][j]=INFI;
			pred[i][j]=NIL;
		}
	}
}
void create_adjmat(int edge){
	int origin,dest,wt;
	for(int i=0;i<edge;i++) {
		cout<<"Enter the origin of edge "<<endl;
		cin>>origin;
		cout<<"Enter the destination of edge "<<endl;
		cin>>dest;
		cout<<"Enter the weight assosciated with edge "<<endl;
		cin>>wt;
		maxvert=max(maxvert,max(origin,dest));
		adj_mat[origin][dest]=wt;
		pred[origin][dest]=origin;
	}
}
void floydWarshall(){
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++) temp_mat[i][j]=adj_mat[i][j];
	}
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++){
			for(int k=0;k<=maxvert;k++){
				if(temp_mat[j][k]!=INFINITY) {
					if(temp_mat[j][k]>temp_mat[j][i]+temp_mat[i][k]){
						path_mat[j][k]=temp_mat[j][i]+temp_mat[i][k];
						pred[j][k]=pred[i][k];
					}
					else {
						path_mat[j][k]=temp_mat[j][k];
					}
				}
			}
		}
		for(int j=0;j<=maxvert;j++){
			for(int k=0;k<=maxvert;k++) temp_mat[j][k]=path_mat[j][k];
		}
	}
}
void display(){
	for(int i=0;i<=maxvert;i++){
		for(int j=0;j<=maxvert;j++) {
			vector <int> v;
			int stor=j;
			if(path_mat[i][j]!=INFI){
				v.push_back(j);
				cout<<"The shortest distane from vertex "<<i<<" to vertex "<<j<<" is "<<path_mat[i][j]<<endl;
				while(pred[i][stor]!=i){
					v.push_back(pred[i][stor]);
					stor=pred[i][stor];
				}
				v.push_back(i);
				cout<<"The path is "<<endl;
				for(int k=v.size()-1;k>=0;k--) cout<<v[k]<<" ";
				cout<<endl;
			}
			else cout<<"NO path "<<endl;
		}	
	}
}
int main(){
	int edge;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	initialise();
	create_adjmat(edge);
	floydWarshall();
	display();
}