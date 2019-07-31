 # include <bits/stdc++.h>
using namespace std;
int lcs_comp(int size_str1,int size_str2){
		string str1,str2;
		int lcs[size_str1+1][size_str2+1];
		cin>>str1>>str2;
		for(int i=0;i<=str1.size();i++){
			for(int j=0;j<=str2.size();j++){
				if(i==0||j==0) lcs[i][j]=0;
				else{
					if(str1[i-1]==str2[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
					else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]); 
				}
			}
		}
		return lcs[size_str1][size_str2];
}
int main(){
	int test_cases;
	cin>>test_cases;
	while(test_cases--){
		int size_str1,size_str2,lcs;
		cin>>size_str1>>size_str2;
		lcs=lcs_comp(size_str1,size_str2);
		cout<<lcs<<endl;
	}
}