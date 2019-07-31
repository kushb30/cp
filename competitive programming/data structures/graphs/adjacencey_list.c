#include <bits/stdc++.h>
using namespace std;
vector <int> vec[100000];
int edge;
void addanedge(char type){
	int origin,dest;
	cout<<"Enter the number of edges "<<endl;
	cin>>edge;
	for(int i=0;i<edge;i++){
		cout<<"Enter the origin of the edge "<<endl;
		cin>>origin;
		cout<<"Enter thr destination of edge "<<endl;
		cin>>dest;
		if(type=='D') vec[origin].push_back(dest);
		else {
			vec[origin].push_back(dest);
			vec[dest].push_back(origin);
		}
	}
}
void delanedge(char type){
	int origin,dest,stor;
	cout<<"Enter the origin of edge to be deleted "<<endl;
	cin>>origin;
	cout<<"Enter the dest of edge to be deleted "<<endl;
	cin>>dest;
	for(int i=0;i<vec[origin].size();i++)
		if(vec[origin][i]==dest) stor=i;
	if (type=='D') vec[origin].erase(vec[origin].begin()+stor);
	else {
		vec[origin].erase(vec[origin].begin()+stor);
		for(int i=0;i<vec[dest].size();i++)
			if(vec[dest][i]==origin) stor=i;
		vec[dest].erase(vec[dest].begin()+stor);
	}
}
void display(){
	for(int i=0;i<edge;i++){
		cout<<"Origin is "<<i<<endl;
		for(int j=0;j<vec[i].size();j++){
			cout<<"All destinations from this origin are "<<vec[i][j]<<" ";
		}
		if(vec[i].size()==0) cout<<"There are no edge from this vertex "<<endl;
		cout<<endl;
	}
}
int main(){
	int choice;
	char type;
	cout<<"Enter D for directed graph and U for undirected graph "<<endl;
	cout<<"Enter your choice "<<endl;
	cin>>type;
	do{
		cout<<"Enter 1 to add a edge "<<endl;
		cout<<"Enter 2 to delete a edge "<<endl;
		cout<<"Enter 3 to check the adjacency list "<<endl;
		cout<<"Enter 4 to exit "<<endl;
		cout<<"Enter your choice "<<endl; 
		cin>>choice;
		switch(choice){
			case 1:
				addanedge(type);
				break;
			case 2:
				delanedge(type);
				break;
			case 3:
				display();
				break;	
			case 4:
				cout<<"Thank you "<<endl;
				break;
			default:
				cout<<"Wrong choice "<<endl;
				break;			
		}

	}while(choice!=4);
	return 0;
}