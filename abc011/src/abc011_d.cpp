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
#include <cassert>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

double C[1010][1010] = {};  //C[n][k] == nCk

void pascal(ll n){
	double div = 2.0;
	C[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= n; j++){
			if(i<j) C[i][j] = 0;
			else if(j==0||i==j) C[i][j] = 1/div;
			else{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
				C[i][j] /= 2;
			}
		}
		div *= 2;
	}
}


int main()
{
	int n,d,x,y;
	cin>>n>>d>>x>>y;
	x = abs(x);
	y = abs(y);
	if(x%d!=0 || y%d!=0){
		cout<<0<<endl;
		return 0;
	}
	int nx = x/d, ny = y/d;
	if(nx+ny>n){
		// cout<<nx<<" "<<ny<<endl;
		cout<<0<<endl;
		return 0;
	}
	pascal(n);
	double ans = 0;
	for (int k = 0; k <= n; k++){
		if((k+nx)%2!=0 || (n-k+ny)%2!=0 || k<nx || n-k<ny) continue;
		int a = (k+nx)/2, b = (n-k+ny)/2;
		if(a>k||b>n-k) continue;
		ans += C[n][k]*C[k][a]*C[n-k][b];
	}

	printf("%0.15f\n",ans);

	// rep(i,n+1){
	// 	rep(j,n+1)cout<<C[i][j]<<" ";
	// 	cout<<endl;
	// }
	return 0;
}