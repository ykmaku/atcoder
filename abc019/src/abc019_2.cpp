#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	string s;
	cin>>s;
	string ans="";
	char target=s[0];
	int cnt=0;
	rep(i,s.size()){
		if(s[i]!=target){
			ans+=s[i-1];
			ans+=to_string(cnt);
			target=s[i];
			cnt=1;
		}else cnt++;
	}
	ans+=s[s.size()-1];
	ans+=to_string(cnt);
	cout<<ans<<endl;
	return 0;
}