struct BIT{
    ll N;
    vector<ll> bit;
    BIT(ll N) : bit(N+1),N(N){};

    ll sum(ll i){
        ll s = 0;
        while(i>0){
           s += bit[i];
           i -= i& -i;
        }
        return s;
    }

    void add(ll i,ll x){
        while(i <= N){
            bit[i] += x;
            i += i & -i;
        }
    }
};

//数列の値の範囲を[1,n]に変える
vector<ll> convert_array(vector<ll> z){
    ll n = z.size();
    vector<ll> temp = z;
    sort(all(temp));
    for(int i = 0; i < n; i++){
        z[i] = lower_bound(all(temp), z[i]) - temp.begin() + 1;
    }
    return z;
}

//反転数を求める
ll inverse_number(vector<ll> z){
    ll n = z.size();
    ll inv_num = 0;
    z = convert_array(z);

    BIT b(n);
    for(int i = 0; i <= n; i++){
        b.bit[i] = 0;
    }

    for(int i = 0; i < n; i++){
        inv_num += i - b.sum(z[i]);
        b.add(z[i],1);
    }

    return inv_num;
}