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
	int r,c;
	cin>>r>>c;
	int grid[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++) cin>>grid[i][j];
	}
	// r and c should be same otherwise it won't work
	for (int i=0;i<r/2;i++){
		for (int j=i;j<c-i-1;j++){
			int temp=grid[i][j];
			grid[i][j]=grid[r-1-j][i];
			grid[r-1-j][i]=grid[r-1-i][c-j-1];
			grid[r-1-i][c-j-1]=grid[j][c-i-1];
			grid[j][c-i-1]=temp;
		}
	}

	for (int i=0;i<r;i++){
		for(int j=0;j<c;j++) cout<<grid[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}

