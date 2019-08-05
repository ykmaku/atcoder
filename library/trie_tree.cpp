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


struct trie{
	bool leaf;
	trie* node[256];
	trie(){
		for(int i = 0; i < 256; i++){
			node[i] = (trie*)0;
		}
	}

	void insert(const string &s){
		trie* r = this;
		for(int i = 0; i < s.length(); i++){
			char c = s[i];
			if(!r->node[c]) r->node[c] = new trie;
			r = r->node[c];
		}
		r->leaf = true;
	}

	bool find(const string &s){
		const trie* r = this;
		for(int i = 0; i < s.length(); i++){
			char c = s[i];
			if(!r->node[c]) return false;
			r = r->node[c];
		}
		return r->leaf;
	}

	void check(const string &s){
		cout << s << "    ";
		cout << (find(s)?"":"not") << " find" << endl;
	}
};

int main()
{
	trie t;
	t.insert("01");
	t.check("0")
;
	return 0;
}