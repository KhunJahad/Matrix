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
	vector <int> ans;
	for (int i=0;i<r;i++){
		for(int j=0;j<c;j++) ans.push_back(grid[i][j]);
	}
	
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

	return 0;
}

