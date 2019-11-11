#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<double,double> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

double cross(P p,P q){
    return p.first*q.second-p.second*q.first;
}

double dot(P p,P q){
    return p.first*q.first+p.second*q.second;
}

double norm(P p){
    return sqrt(pow(p.first,2)+pow(p.second,2));
}

int ccw(P p0,P p1,P p2){ //p0p1が基準
    p1.first -= p0.first;
    p1.second -= p0.second;
    p2.first -= p0.first;
    p2.second -= p0.second;

    if(cross(p1,p2) > 0) return 1; // counter_clockwise
    if(cross(p1,p2) < 0) return -1; // clockwise
    if(dot(p1,p2)<0) return -2 ;//on_line back
    if(norm(p1)<norm(p2)) return 2; //on_line front
    return 0; // on_segment
}


vector<P> convex_hull(vector<P> ps){

    for(int i = 0; i < ps.size(); i++){
        double x = ps[i].first;
        ps[i].first = ps[i].second;
        ps[i].second = x;
    }
    sort(all(ps));
    for(int i = 0; i < ps.size(); i++){
        double x = ps[i].first;
        ps[i].first = ps[i].second;
        ps[i].second = x;
    }
    int n = ps.size(),k=0;
    vector<P> ch(n*2);
    for(int i = 0; i < n; i++){
        while(k>=2 && ccw(ch[k-2],ch[k-1],ps[i])< 0) k--;
        ch[k] = ps[i];
        k++;
    }
    int t = k+1;
    for(int i = n-2; i >= 0; i--){
        while(k >= t && ccw(ch[k-2],ch[k-1],ps[i])< 0) k--;
        ch[k] = ps[i];
        k++;
    }

    ch.resize(k-1);
    return ch;
}

int main()
{
    int n;
    cin >> n;
    vector<P> p;
    for(int i = 0; i < n; i++){
        double x,y;
        cin >> x >> y;
        p.push_back(P(x,y));
    }

    vector<P> pp = convex_hull(p);
    //sort(all(pp));
    cout << pp.size() << endl;
    for(int i = 0; i < pp.size(); i++){
        cout << pp[i].first << " " << pp[i].second << endl;
    }
    return 0;
}