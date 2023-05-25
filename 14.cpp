#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
//using mint = modint998244353;
// using mint;  /*このときmint::set_mod(mod)のようにしてmodを底にする*/
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = a; i <= (int)(b); i++)
#define rng(i,a,b) for(int i = a; i < (int)(b); i++)
#define rrng(i,a,b) for(int i = a; i >= (int)(b); i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define si(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ret(x) { cout<<(x)<<endl;}
typedef long long ll;
using namespace std;
using P = pair<ll,ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
ll mul(ll a, ll b) { if (a == 0) return 0; if (LINF / a < b) return LINF; return min(LINF, a * b); }
ll mod(ll x, ll y){return (x % y + y) % y;}
char itoc(int x){return x + '0';}
int ctoi(char c){return c - '0';}

ll f(ll n,map<ll,bool> &mp,map<ll,ll>&v){
    if(n == 1){
        return 1;
    }
    if(mp[n]){
        return v[n];
    }
    if(n % 2 == 0){
        ll g = f(n/2,mp,v);
        mp[n] = true;
        v[n] = g + 1;
        return g + 1;
    }
    else{
        ll g = f(3*n+1,mp,v);
        mp[n] = true;
        v[n] = g + 1;
        return g + 1;
    }
}



int main(){

    map<ll,bool> mp;
    map<ll,ll> v;
    v[1] = 1;
    mp[1] = true;

    ll num = -1;
    ll ans = -1;

    rng(i,1,1e+6 + 1){
        ll cnt = 0;
        cnt = f(i,mp,v);
        if(num < cnt){
            num = cnt;
            ans = i;
        }
    }

    cout << ans << endl;




    return 0;
}