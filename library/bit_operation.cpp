#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>


using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int a = 2, b = 43;

	//and演算
	cout << (a&b) << endl;  // 3
	//or演算
	cout << (a|b) << endl;  // 127
	//xor演算
	cout << (a^b) << endl;  // 124

	cout << ~a << endl;  //not演算

	cout << (a<<2) << endl;  //左シフト 2つ左に1を移動させる 2 -> 8

	int x = (1<<3);  //3番目のbitが1 = 8 = 2^ 3
	cout << x << endl;

	x |= (1<<5);  //さらに5番目のbitを1にする
	cout << x << endl;

	x &= ~(1<<5);  //5番目のbitを消す
	cout << x << endl;

	cout << __builtin_popcount(x) << endl;  //xにいくつbitが立っているか



	int n = 3;
	// {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); bit++)
    {
    	cout << bitset<8>(bit) << endl;
    	//bitに対する処理
    	//{0,1,2}の部分集合列挙
    	vector<int> S;
    	for(int i = 0; i < n; i++){
    		if(bit & (1<<i)) S.push_back(i);
    	}
    	cout << "{";
    	for(int i = 0; i < S.size(); i++){
    		cout << S[i] << " ";
    	}cout  << "}"<< endl;
    }

    printf("\n\n");

    //{0,...,9}から{2,3,5,7}の部分集合の列挙
    n = 10;
    int c = (1<<2) | (1<<3) | (1<<5) | (1<<7);
    for(int bit = c; ; bit = (bit-1) & c){
    	//cout<< bitset<8>(bit) << endl;
    	vector<int> S;
    	for(int i = 0; i < n; i++){
    		if(bit & (1<<i)) S.push_back(i);
    	}
    	cout << "{";
    	for(int i = 0; i < S.size(); i++){
    		cout << S[i] << " ";
    	}cout  << "}"<< endl;

    	if(!bit) break;
    }


	return 0;
}