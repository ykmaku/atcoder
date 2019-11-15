#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,char> P;

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
	int n;
	ll l;
	cin>>n>>l;
	vector<P> rabbit;
	rep(i,n){
		ll x;
		char d;
		cin>>x>>d;
		rabbit.push_back(P(x,d));
	}

	// if(rabbit[n-1].second=='R'){
	// 	rabbit.push_back(P(l+1,'L'));
	// }
	// rabbit.push_back(P(l+2,'R'));

	ll ans=0;
	ll Lbegin=0,Lend=0,Rbegin=0,Rend=0;
	ll Lcnt=0,Rcnt=0;



	vector<ll> Lx,Rx;
	bool is_right=true;
	rep(i,rabbit.size()){
		if(is_right){
			if(rabbit[i].second=='R'){
				Rx.push_back(rabbit[i].first);
				Rcnt++;
				Rend=rabbit[i].first;
			}else{
				is_right=false;
				Lx.push_back(rabbit[i].first);
				Lbegin=rabbit[i].first;
				Lcnt++;
			}
		}else{
			if(rabbit[i].second=='R'){

				ll cnt=1;
				if(Rcnt>1){
					repr(k,Rcnt-2,0){
						ans += Rend-cnt-Rx[k];
						cnt++;
					}
				}
				cnt=1;
				if(Lcnt>1){
					repr(k,1,Lcnt){
						ans+=Lx[k]-cnt-Lbegin;
					}
				}

				if(Lcnt>Rcnt){
					ll res=(Lbegin-1-Rend)*Lcnt;
					ans+=res;
				}else{
					ll res=(Lbegin-1-Rend)*Rcnt;
					ans+=res;
				}

				Lx.clear();
				Rx.clear();
				Lcnt=0;Rcnt=0;

				is_right=true;
				Rx.push_back(rabbit[i].first);
				Rend=rabbit[i].first;
				Rcnt++;
			}else{
				Lx.push_back(rabbit[i].first);
				Lcnt++;
			}
		}
	}


	cout<<ans<<endl;
	return 0;
}