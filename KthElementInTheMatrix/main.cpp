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
	map <int,int> mp;

	for (int i=0;i<c;i++) mp[grid[0][i]]=1;

	for (int i=1;i<r;i++){
		for(int j=0;j<c;j++){
			if (mp[grid[i][j]]==i) mp[grid[i][j]]++;
		}
	}
	
	for(auto itr=mp.begin();itr!=mp.end();itr++){
		if (itr->second==r) cout<<itr->first<<" ";
	}
	return 0;
}
