#include <bits/stdc++.h>
using namespace std;
int main(){
	int test_cases;
	cin>>test_cases;
	while(test_cases--){
		int row,col;
		cin>>row>>col;
		int cost[row][col];
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++) cin>>cost[i][j];
		}
		int MinCost[row][col];
		MinCost[0][0]=cost[0][0];
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(i==0&&j!=0) MinCost[i][j]=MinCost[i][j-1]+cost[i][j];
				else if(i!=0&&j==0) MinCost[i][j]=MinCost[i-1][j]+cost[i][j];
				else MinCost[i][j]=min(MinCost[i-1][j-1],min(MinCost[i-1][j],MinCost[i][j-1]))+cost[i][j];
			}
		}	
		cout<<MinCost[row-1][col-1]<<endl;
	}
	return 0;
}