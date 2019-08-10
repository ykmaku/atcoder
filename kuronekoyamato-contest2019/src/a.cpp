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

typedef struct{
	int id; //自身のid
	int road_id; //自身が属している道路のid
	int len_from_start; //属している道路のstartからの距離
}point;

typedef struct{
	int flag;
	string start,from;
}query;

class directed_road{
	public:
	int id; //自身のid
	int start,end;
	int length;
	int is_directed;
	vector<point> parking_points;
};

class undirected_road{
	public:
	int id; //自身のid
	int start,end;
	int length;
	vector<point> deli_or_parking_points; // 配達先、駐車点
};

map<string,int> road_id_map,park_id_map,deli_id_map;
vector<directed_road> directed_roads;
vector<undirected_road> undirected_roads;
vector<query> queries;


void input_main(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	input_road(a);
	input_cross(b);
	input_park(c);
	input_deli(d);
	input_query(e);
}
void input_road(int num){
	for (int i = 0; i < num; i++){
		string id;
		int l,flag;
		cin>>id>>l>>flag;

		if(flag==1){

		}
	}
}
void input_cross(int num){

}
void input_park(int num){

}
void input_deli(int num){

}
void input_query(int num){
	
}


int main()
{

	return 0;
}