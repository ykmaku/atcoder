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

int calc_mod(string &s,int m){
	int now=0;
	rep(i,s.size()){
		now = now*10 + (s[i]-'0');
		now%=m;
	}
	return now;
}

int main()
{
	int n,a;
	string s;
	cin>>n>>a>>s;
	vector<int> b(n);
	rep(i,n){
		cin>>b[i];
	}
	rep(i,n)b[i]--;
	a--;

	vector<int> num_b(n,-1);
	int len_noncycle=n;
	int len_cycle=0;
	int pos=a;
	num_b[pos]=1;
	rep(i,2*n){
		if(num_b[b[pos]]>0){
			len_noncycle=num_b[b[pos]]-1;
			len_cycle=num_b[pos]-num_b[b[pos]]+1;
			break;
		}
		num_b[b[pos]]=num_b[pos]+1;
		pos=b[pos];
	}
	int mod_k;
	if(s.size()<=6&&stoi(s)<=len_noncycle){
		mod_k=atoi(s.c_str());
	}else{
		mod_k=calc_mod(s,len_cycle);
		while(mod_k<=len_noncycle) mod_k+=len_cycle;
	}

	pos=a;
	rep(i,mod_k-1){
		pos=b[pos];
	}
	cout<<b[pos]+1<<endl;

	return 0;
}