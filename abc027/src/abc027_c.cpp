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

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	ll n;
	cin>>n;
	ll d = -1;
	ll res = n;
	while(res>0){
		res /=2;
		d++;
	}

	ll x = 1;
	int num = 1;
	if(d%2==0){
		while(1){
			if(num>0){
				if(2*x+1>n) x = 2*x;
				else x = 2*x+1;

				if(x > n) break;
				num *= -1;
			}else{
				x = 2*x;
				if(x > n) break;
				num *= -1;
			}
		}
	}else{
		while(1){
			if(num<0){
				if(2*x+1>n) x = 2*x;
				else x = 2*x+1;
				
				if(x > n) break;
				num *= -1;
			}else{
				x = 2*x;
				if(x > n) break;
				num *= -1;
			}
		}
	}
	cout<<(num>0?"Aoki":"Takahashi")<<endl;
	return 0;
}