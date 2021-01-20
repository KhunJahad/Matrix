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
	cin>>k;
	int start=0;
	int end=r-1;
	while(start<=end){
		int mid=(start+end)/2;
		int mid_min=grid[mid][0];
		int mid_max=grid[mid][c-1];
		if (mid_max==k || mid_min==k){
			cout<<"True";
			break;
		}
		if (mid_min==mid_max){
			if (mid_min>k) end=mid-1;
			else start=mid+1;
		}
		else{
			if (mid_min>k){
				end=mid-1;
			}
			else if (mid_max<k) {
				start=mid+1;
			}
			else{
				if (binary_search(grid[mid],grid[mid]+c,k)){
					cout<<"True";
					break;
				}
				break;
			}
		}
	}
	cout<<"false";

	return 0;
}

/*

tc 1:
3 4
1 3 5 7 
10 11 16 20
23 30 34 60
2

tc 2:




*/