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
	int max_grid[r][c];
	int ans=INT_MIN;
	max_grid[r-1][c-1]=grid[r-1][c-1];

	for (int i=c-2;i>=0;i--) max_grid[r-1][i]=max(max_grid[r-1][i+1],grid[r-1][i]);
	for (int i=r-2;i>=0;i--) max_grid[i][c-1]=max(max_grid[i+1][c-1],grid[i][c-1]);

	for (int i=r-2;i>=0;i--){
		for(int j=c-2;j>=0;j--){
			ans=max(max_grid[i+1][j+1]-grid[i][j],ans);
			max_grid[i][j]=max(grid[i][j],max(max_grid[i+1][j],max_grid[i][j+1]));
		}
	}

	cout<<ans<<"\n";


	return 0;
}

