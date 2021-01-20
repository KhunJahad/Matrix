#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void read_input(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

int main(){
	read_input();
	int r,c,k;
	cin>>r>>c;
	int grid[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++) cin>>grid[i][j];
	}
	int ans=0;
	int ind=-1;
	for (int i=0;i<r;i++){
		int ones=0;
		for (int j=0;j<c;j++){
			if (grid[i][j]==1) ones++;
		}
		if (ans<ones){
			ans=ones;
			ind=i;
		}
		if (ans==c){
			break;
		}
	}
	cout<<ind<<"\n";

	return 0;
}

