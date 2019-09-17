#include <iostream>
#include <vector>
#include <set>


using namespace std;

typedef long long int ll;

#define rep(i,n) for(int i=0;i<(n);++i)


int main()
{
	int n;
	cin>>n;
	vector<ll> p(n),pos(n+1,0);
	rep(i,n){
		cin>>p[i];
		pos[p[i]] = i+1;
	}
	ll ans = 0;

	multiset<ll> s;
	s.insert(0);
	s.insert(0);
	s.insert(n+1);
	s.insert(n+1);
	for (ll now = n; now >= 1; now--){
		auto it = s.lower_bound(pos[now]);
		ll pos_r = *it;

		it++;
		ll pos_rr = *it;

		it--;
		it--;
		ll pos_l = *it;

		it--;
		ll pos_ll = *it;

		ans += now*(pos_r-pos[now])*(pos_l-pos_ll);
		ans += now*(pos_rr-pos_r)*(pos[now]-pos_l);

		s.insert(pos[now]);
	}
	cout<<ans<<endl;
	
	return 0;
}
