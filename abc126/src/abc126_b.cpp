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

bool ismonth(int x){
	return 1<=x && x<=12;
}
bool isyear(int x){
	return 0<=x && x<= 99;
}

int main()
{
	string s;
	cin>>s;
	int x = stoi(s);
	int a = x/100;
	int b = x%100;

	if(isyear(a) && ismonth(b)){
		if(ismonth(a) && isyear(b))
			cout<<"AMBIGUOUS"<<endl;
		else
			cout<<"YYMM"<<endl;
	}else if(ismonth(a) && isyear(b)){
		if(isyear(a) && ismonth(b))
			cout<<"AMBIGUOUS"<<endl;
		else
			cout<<"MMYY"<<endl;
	}else{
		cout<<"NA"<<endl;
	}

	return 0;
}