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
	int passes;
	if (r%2==0) passes=r/2;
	else passes=(r/2 +1);
	int cur=0;
	int total =r*c;
	for (int i=0;i<passes;i++){
		for(int j=i;j<c-i;j++){
			cout<<grid[i][j]<<" ";
			cur++;
		}
		if (cur==total) return 0;

		for (int j=i+1;j<r-i;j++){
			cout<<grid[j][c-i-1]<<" ";
			cur++;
		}
		if (cur==total) return 0;
		
		for (int j=c-i-2;j>i;j--){
			cout<<grid[r-i-1][j]<<" ";
			cur++;
		}
		if (cur==total) return 0;
		
		for (int j=r-i-1;j>i;j--){
			cout<<grid[j][i]<<" ";
			cur++;
		}
		if (cur==total) return 0;

	}
	return 0;
}
/*

tc 1: 

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

3 4
1 2 3 4
5 6 7 8
9 10 11 12



*/