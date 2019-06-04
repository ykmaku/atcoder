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


using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int hour2time(int x,bool is_start){
	x = (x/100)*60 + x%100;
	if(is_start)
		x -= x%5;
	else if(x%5!=0)
		x += 5-x%5;
	return x;
}

int time2hour(int x){
	return ((x-x%60)/60)*100+x%60;
}

int main()
{
	int n;
	cin>>n;
	vector<P> time(n);
	for(int i = 0; i < n; i++){
		string t;
		cin>>t;
		time[i].first = stoi(t.substr(0,4));
		time[i].second = stoi(t.substr(5,4));
	}

	for(int i = 0; i < n; i++){
		time[i].first = hour2time(time[i].first,1);
		time[i].second = hour2time(time[i].second,0);
	}
	sort(all(time));

	vector<P> ans;
	int start=-1,end=-1;
	for(int i = 0; i < n; i++){
		if(start<0) start = time[i].first;
		if(end<0) end = time[i].second;

		if(time[i].first<=end)
			end = max(end,time[i].second);
		else{
			ans.push_back(P(start,end));
			start=time[i].first;
			end=time[i].second;
		}
	}
	ans.push_back(P(start,end));

	for(auto v : ans)
		printf("%04d-%04d\n", time2hour(v.first),time2hour(v.second));

	return 0;
}