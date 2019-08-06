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
	int t,n,m;
	cin>>t>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++)cin>>a[i];
	cin>>m;
	vector<int>b(m);
	for(int i=0;i<m;i++)cin>>b[i];
	int pos = 0;
	if(m>n){
		cout<<"no"<<endl;
		return 0;
	}
	for (int i = 0; i < m; i++){
		while(a[pos]+t<b[i] && pos<n) pos++;
		if(pos==n || a[pos]>b[i]){
			cout<<"no"<<endl;
			return 0;
		}
		pos++;
	}
	cout<<"yes"<<endl;
	return 0;
}