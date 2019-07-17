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
	int n,d;
	cin>>n>>d;
	int p[11][11];
	for (int i = 0; i < n; i++){
		for(int j = 0; j < d; j++){
			cin>>p[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			int dist = 0;
			for (int k = 0; k < d; k++){
				dist += (p[i][k]-p[j][k])*(p[i][k]-p[j][k]);
			}
			for (int l = 2; l <= 130; l++){
				while(dist%(l*l)==0){
					dist/=(l*l);
				}
			}
			if(dist==1)ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
