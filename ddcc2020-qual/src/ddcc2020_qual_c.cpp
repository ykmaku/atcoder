#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	int h,w,k;
	cin>>h>>w>>k;
	vector<string> s(h);
	rep(i,h)cin>>s[i];

	vector<vector<int>> a(h,vector<int>(w,0));

	int cnt=1;

	rep(i,h){
		rep(j,w){
			if(s[i][j]=='#'){
				a[i][j] = cnt;
				cnt++;
			}
		}
	}

	// cnt=1;
	// rep(i,h){
	// 	rep(j,w){
	// 		if(a[i][j]==cnt){
	// 			int l=0;
	// 			while(a[i][l]>0)l++;
	// 			while(l<w&&a[i][l]==0){
	// 				a[i][l]=a[i][j],l++;
	// 				if(a[i][l]>0 && a[i][l]!=a[i][j]){
	// 					// cout<<a[i][l]<<endl;
	// 					break;
	// 				}
	// 			}
	// 			cnt++;
	// 		}
	// 	}

		// rep(i,h){
		// rep(j,w){
		// 	cout<<a[i][j]<<" ";
		// }
		// cout<<endl;
		// }
		// cout<<endl;
	// }

	// rep(i,h){
	// 	rep(j,w){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	rep(i,h){
		rep(j,w-1){
			if(a[i][j+1]==0)a[i][j+1] = a[i][j];
		}
	}
	rep(i,h){
		repr(j,w-1,1)if(a[i][j-1]==0)a[i][j-1]=a[i][j];
	}

	rep(i,h-1){
		rep(j,w){
			if(a[i+1][j]==0)a[i+1][j]=a[i][j];
		}
	}
	repr(i,h-1,1){
		rep(j,w){
			if(a[i-1][j]==0)a[i-1][j]=a[i][j];
		}
	}

	rep(i,h){
		rep(j,w){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	
	return 0;
}