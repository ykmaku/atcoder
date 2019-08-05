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

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e6;

int seg_tree[MAXN]= {0};
//int a[MAXN];

void recalculate(int node)  //get the current seg tree condition
{
	seg_tree[node] = min(seg_tree[2*node+1],seg_tree[2*node+2]);
}
void build_segtree(int node,int left,int right)  //node = array's size
{
	if (left == right)  //we are in a leaf node
	{
		seg_tree[node] = 2147483647;
	}else
	{
		int mid = (left+right)/2;
		build_segtree(2*node+1,left,mid);
		build_segtree(2*node+2,mid+1,right);
		recalculate(node);
	}
}

void update(int node,int left,int right,int x,int y) //updete a[x] to y
{
	if (left == right)
	{
		seg_tree[node] = y;
	}else
	{
		int mid = (left+right)/2;
		if (x <= mid)
		{
			update(node*2+1,left,mid,x,y);
		}else
		{
			update(node*2+2,mid+1,right,x,y);
		}
		recalculate(node);
	}
}

ll query(int node,int left,int right,int x,int y) // query for [x,y]
{
	if (x <= left && right <= y)
	{
		return seg_tree[node];
	}else
	{
		ll ans = 2147483647;
		int mid = (left+right)/2;
		if (x <= mid) //search left
		{
			ans = min(ans,query(node*2+1,left,mid,x,y));
		}
		if (mid+1 <= y) //search right
		{
			ans = min(ans,query(node*2+2,mid+1,right,x,y));
		}
		//else (x,y) ^ (left,right) = emptyset , so return -INF

		return ans;
	}
}



int main()
{
	int n,q;
	cin >> n >> q;
	build_segtree(0,1,n);

	for(int i = 0; i < q; i++)
	{
		int com;
		int x,y;
		cin >> com >> x >> y;
		if (com == 0)
		{
			update(0,1,n,x+1,y);
		}else
		{
			cout << query(0,1,n,x+1,y+1) << endl;
		}
	}

	return 0;
}