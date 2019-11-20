#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> tp;

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
	cin>>n;
	vector<tp> human(n);
	vector<int> R(n);
	rep(i,n){
		int r,h;
		cin>>r>>h;
		human[i]=tp(r,h,i);
		R[i]=r;
	}

	sort(all(R));

	map<P,int> s;
	rep(i,n){
		P p = make_pair(get<0>(human[i]),get<1>(human[i]));
		if(s.find(p)==s.end()) s.emplace(p,1);
		else s[p]+=1;
	}
	vector<tp> ans(n);

	rep(i,n){
		int win=0;
		int hand = get<1>(human[i]);
		int rate = get<0>(human[i]);
		win += lower_bound(all(R),rate) - R.begin();
		if(hand==1) win += s[P(rate,2)];
		else if(hand==2) win += s[P(rate,3)];
		else win += s[P(rate,1)];
		int draw = (int)s[P(rate,hand)]-1;
		// cout<<s.count(P(rate,hand))<<endl;
		ans[get<2>(human[i])] = tp(win, n-win-draw-1, draw);
	}

	rep(i,n)cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<endl;

	return 0;
}