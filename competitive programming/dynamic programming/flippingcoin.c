#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n],pos[n+1],max1=-1;
	pos[0]=0;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		if(arr[i-1]==1) pos[i]=1+pos[i-1];
		else pos[i]=pos[i-1];
	//	cout<<pos[i]<<endl;
		for(int j=i+1;j<=n;j++){
			if(arr[j-1]==1) pos[j]=1+pos[j-1];
			else pos[j]=pos[j-1];
			if(j-i-pos[j]+1>pos[j]) max1=max(max1,j-i-2*pos[j]+1);
			//cout<<pos[j]<<endl;
		}
		pos[i]=0;
	}
	int count=0;
	for(int i=0;i<n;i++)
		if(arr[i]==1) count++;
	if(n==1&&arr[0]==0) cout<<"1 "<<endl;
	else cout<<count+max1<<endl;
	return 0;
}
//a better program at bottom
/*#include <iostream>

using namespace std;

int main()
{
    int n, a, count1(0), extra0(0), extra0max(-1);
    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a == 1)
        {
            count1 += 1;
            if (extra0 > 0)
            {
                extra0 -= 1;
            }
        }
        else
        {
            extra0 += 1;
            if (extra0 > extra0max)
            {
                extra0max = extra0;
            }
        }
    }
    cout << count1 + extra0max << endl;
    return 0;
} */