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

bool uruu(int y){
	bool ch = false;
 
	if (y % 400 == 0) ch = !ch;
	else if (y % 100 != 0 && y % 4 == 0)ch = !ch;
	return ch;
}

int main()
{
	int y,m,d;
	char d1,d2;
	cin >> y >> d1 >> m >> d2 >> d;

	while(y % (m*d) != 0)
	{
		if (uruu(y)){
			if (m == 2){
				if (d == 29){
					d = 1;
					m = 3;
				}else{
					d++;
				}
			}else if (m == 4 || m == 6 || m == 9 || m == 11){
				if (d == 30){
					d = 1;
					m++;
				}else{
					d++;
				}
			}else{
				if (d == 31){
					if (m == 12){
						y++;
						d = 1;
						m = 1;
					}else{
						d = 1;
						m++;
					}
				}else{
					d++;
				}
			}
		}else{
			if (m == 2){
				if (d == 28){
					d = 1;
					m = 3;
				}else{
					d++;
				}
			}else if (m == 4 || m == 6 || m == 9 || m == 11){
				if (d == 30){
					d = 1;
					m++;
				}else{
					d++;
				}
			}else{
				if (d == 31){
					if (m == 12){
						y++;
						d = 1;
						m = 1;
					}else{
						d = 1;
						m++;
					}
				}else{
					d++;
				}
			}
		}
	}

	printf("%d/%02d/%02d\n",y,m,d);

	return 0;
}