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
	// this is to change the track of the continuous ones from the previous row's
	for (int i=1;i<r;i++){
		for (int j=0;j<c;j++){
			if (grid[i][j]==1) grid[i][j]+=grid[i-1][j];
		}
	}

	// now grid has bar size (continuous) like a histogram

	// now to find the area of each row histogram
	int running_area=0;
	int max_area=0;
	int ans=0;
	int tp;

	for (int j=0;j<r;j++){
		stack <int> s;
		int i = 0;
		while(i<c){
			if (s.empty() || grid[j][s.top()]<=grid[j][i]) s.push(i++);
			else{
				tp=s.top();
				s.pop();
				running_area=grid[j][tp]*(s.empty() ? i:i-s.top()-1);
				max_area=max(running_area,max_area);
			}
		}
		while(!s.empty()){
			tp=s.top();
			s.pop();
			running_area=grid[j][tp]*(s.empty() ? i: i-s.top()-1);
			max_area=max(running_area,max_area);
		}
		
		ans=max(max_area,ans);
	}
	cout<<ans<<"\n";
	return 0;
}

