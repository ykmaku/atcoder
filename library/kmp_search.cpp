#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

vector<int> compute_lps(string s,int m,vector<int> lps){
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i < m){
		if(s[i] == s[len]){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len != 0) len = lps[len-1];
			else{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}

void kmp_search(string pat,string txt){
	int m = pat.length();
	int n = txt.length();

	vector<int> lps(m);
	lps = compute_lps(pat,m,lps);

	int i = 0,j = 0;
	while(i < n){
		if(pat[j] == txt[i]){
			i++;
			j++;
		}

		if(j == m){
			cout << i - j << endl;
			j = lps[j-1];
		}else if(i < n & pat[j] != txt[i]){
			if(j != 0) j = lps[j-1];
			else i++;
		}
	}
}

int main()
{
	string t,p;
	cin >> t >> p;
	kmp_search(p,t);

	return 0;
}