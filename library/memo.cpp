//構造体ソート

struct edge
{
	int cost;
	int u,v;
};

bool comp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}


e1,e2の並び

>だったらe2,e1

sort(
        index.begin(),
        index.end(),
        [&](int x, int y){return vec[x] < vec[y];}
    );

//小さい順に並ぶよ

struct edge
{
	int u,v,l;

	edge()
	{
		l = INF;
	}

	bool operator<(const edge& e) const
    {
        return l > e.l;
    }
};

priority_queue< edge > que;


//vectorから最大値を取り出す
std::vector<int> v;
int max = *max_element(v.begin(),v.end());

vector<int> v;
sort(v.begin(),v.end());
sort(v.begin(),v.end(),greater<int>());

//総和
#include <numeric>

int main() 
{int a[50] = {0},n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		a[i] = i+1;
	}

	int sum = accumulate(a,a+n,0);

	cout << sum << endl;

	return 0;
    
}



vector<int> v(N);
   for(int i = 0; i < N; i++)
   {
  	 v[i] = hoge;
   }       // v に 1, 2, ... N を設定
    while( next_permutation(v.begin(), v.end())      // 次の順列を生成
    {
    	for(int i = 0; i < N; i++)
    	{

    		for(auto x : v) cout << x << " "; cout << "\n";    // v の要素を表示
    		a[v[i]] hogehoge;
    	}
    }