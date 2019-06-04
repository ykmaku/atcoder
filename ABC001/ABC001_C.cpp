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

string dir(int d){
	string res;
	d = (double)d;
	if(112.5<=d&&d<337.5) res = "NNE";
	else if(337.5<=d&&d<562.5) res = "NE";
	else if(562.5<=d&&d<787.5) res = "ENE";
	else if(787.5<=d&&d<1012.5) res = "E";
	else if(1012.5<=d&&d<1237.5) res = "ESE";
	else if(1237.5<=d&&d<1462.5) res = "SE";
	else if(1462.5<=d&&d<1687.5) res = "SSE";
	else if(1687.5<=d&&d<1912.5) res = "S";
	else if(1912.5<=d&&d<2137.5) res = "SSW";
	else if(2137.5<=d&&d<2362.5) res = "SW";
	else if(2362.5<=d&&d<2587.5) res = "WSW";
	else if(2587.5<=d&&d<2812.5) res = "W";
	else if(2812.5<=d&&d<3037.5) res = "WNW";
	else if(3037.5<=d&&d<3262.5) res = "NW";
	else if(3262.5<=d&&d<3487.5) res = "NNW";
	else res ="N";

	return res;
}

int wind(int w){
	double res = (double)w/60;
	//cout << res << endl;

	if (0.0 <= res && res<0.25) w = 0;
    else if (0.25 <= res && res<1.55) w = 1;
    else if (1.55 <= res && res<3.35) w = 2;
    else if (3.35 <= res && res<5.45) w = 3;
    else if (5.45 <= res && res<7.95) w = 4;
    else if (7.95 <= res && res<10.75) w = 5;
    else if (10.75 <= res && res<13.85) w = 6;
    else if (13.85 <= res && res<17.15) w = 7;
    else if (17.15 <= res && res<20.75) w = 8;
    else if (20.75 <= res && res<24.45) w = 9;
    else if (24.45 <= res && res<28.45) w = 10;
    else if (28.45 <= res && res<32.65) w = 11;
    else w = 12;

    return w;
}

int main()
{
	int d,w;
	cin>>d>>w;
	w = wind(w);
	string di = dir(d);
	if(w==0) di = "C";

	cout<<di<<" "<<w<<endl;

	return 0;
}
