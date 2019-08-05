#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template<class T, class V>
typename enable_if<is_class<T>::value == 0>::type fill(T &t, const V &v) {
    t = v;
}
template<class T, class V>
typename enable_if<is_class<T>::value != 0>::type fill(T &t, const V &v){
    for (auto &e : t) fill(e, v);
}

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }

#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }



vector<long long> LISLDS(long long N, long long A, long long B) {
    vector<long long> res;
    for (long long i = B-1; i >= 0; --i) res.push_back(i);
    if (A == 1) return res;
    long long rem = N - B;
    long long p = rem / (A-1);
    long long r = rem % (A-1);
    long long b = r;
    long long c = A-1-r;
    for (int i = 0; i < b; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p+1; ++j) {
            res.push_back(size + p - j);
        }
    }
	for(auto x:res)cout<<x+1<<" ";
	cout<<endl;
    for (int i = 0; i < c; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p; ++j) {
            res.push_back(size + p-1 - j);
        }
    }
    return res;
}


int main() {
    long long N, A, B;
    while (cin >> N >> A >> B) {
        if (A + B > N+1 || A * B < N) cout << -1 << endl;
        else {
            auto res = LISLDS(N, A, B);
            for (auto v : res) cout << v+1 << " ";
            cout << endl;
        }
    }
}
