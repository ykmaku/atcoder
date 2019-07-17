#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n;
	cin>>n;
	vector<int> t(n),x(n),y(n);
	for (int i = 0; i < n; i++)
	{
		cin>>t[i]>>x[i]>>y[i];
	}
	int prev_x=0,prev_y=0,prev_t=0;;
	for (int i = 0; i < n; i++)
	{
		int dist = abs(prev_x-x[i]) + abs(prev_y-y[i]);
		int time = t[i]-prev_t;
		if(dist > time){
			cout<<"No"<<endl;
			return 0;
		}else{
			if((dist%2==0 && time%2!=0) || (dist%2!=0 && time%2==0)){
				cout<<"No"<<endl;
				return 0;
			}
		}
		prev_x = x[i];
		prev_y = y[i];
		prev_t = t[i];
	}
	cout<<"Yes"<<endl;
	
	
	return 0;
}