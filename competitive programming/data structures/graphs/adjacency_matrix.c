#include <bits/stdc++.h>
using namespace std;
int main(){
	int vertex,origin,dest,choice;
	char type;
	cout<<"Type 'U' for undirected graph and 'D' for directed graph  ";
	cin>>type;
	cout<<endl;
	cout<<"Enter no of vertices ";
	cin>>vertex;
	cout<<endl;
	int count=0,adjmat[vertex][vertex];
	if(count==0) {
		for(int i=0;i<vertex;i++){
			for(int j=0;j<vertex;j++) adjmat[i][j]=0;
		}
		count++;
	}
	do{
		cout<<"Enter 1 to insert a edge "<<endl;
		cout<<"Enter 2 to delete a edge "<<endl;
		cout<<"Enter 3 to quit "<<endl;
		cout<<"Enter your choice ";
		cin>>choice;
		switch(choice) {
			case 1:
				cout<<"Enter origin and destination of edge to be inserted"<<endl;
				cin>>origin>>dest;
				if(type=='D') adjmat[origin-1][dest-1]=1;
				else {
					adjmat[dest-1][origin-1]=1;
					adjmat[origin-1][dest-1]=1;
				}
				break;
			case 2:
				cout<<"Enter origin and destination of edge to be deleted "<<endl;
				cin>>origin>>dest;
				if(type=='D') adjmat[origin-1][dest-1]=0;
				else {
					adjmat[dest-1][origin-1]=0;
					adjmat[origin-1][dest-1]=0;
				}
				break;	
			case 3:
				cout<<"Thank you "<<endl;
				break;
			default:
				cout<<"Enter a valid choice "<<endl;
				break;			 
		}
	}while(choice!=3);
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++) cout<<adjmat[i][j]<<" ";
		cout<<endl;	
	}
	return 0;
}