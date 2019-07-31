 # include <bits/stdc++.h>
using namespace std;
int EditStr_comp(int size_str1,int size_str2){
		string str1,str2;
		int EditStr[size_str1+1][size_str2+1];
		cin>>str1>>str2;
		for(int i=str1.size();i>=0;i--){
			for(int j=str2.size();j>=0;j--){
				if(i==str1.size()) EditStr[i][j]=str2.size()-j;
				else if(j==str2.size()) EditStr[i][j]=str1.size()-i;
				else if(str1[i]==str2[j]) EditStr[i][j]=EditStr[i+1][j+1];
				else EditStr[i][j]=1+min(EditStr[i][j+1],min(EditStr[i+1][j],EditStr[i+1][j+1]));
			}
		}
		return EditStr[0][0];
}
int main(){
	int test_cases;
	cin>>test_cases;
	while(test_cases--){
		int size_str1,size_str2,EditStr;
		cin>>size_str1>>size_str2;
		EditStr=EditStr_comp(size_str1,size_str2);
		cout<<EditStr<<endl;
	}
}