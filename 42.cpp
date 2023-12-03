#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
//using mint = modint1000000007;
// using mint = modint;  /*このときmint::set_mod(mod)のようにしてmodを底にする*/
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i = a; i <= (ll)(b); i++)
#define rng(i,a,b) for(ll i = a; i < (ll)(b); i++)
#define rrng(i,a,b) for(ll i = a; i >= (ll)(b); i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define si(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ret(x) { cout<<(x)<<endl;}
using namespace std;
using P = pair<ll,ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
ll mul(ll a, ll b) { if (a == 0) return 0; if (LINF / a < b) return LINF; return min(LINF, a * b); }
ll mod(ll x, ll y){return (x % y + y) % y;}
char itoc(int x){return x + '0';}
int ctoi(char c){return c - '0';}
void chmin(ll& x,ll y){x = min(x,y);}
void chmax(ll& x,ll y){x = max(x,y);}
ll getnum(ll x, ll y, ll H, ll W) { (void) H; return (x * W + y);}
template<typename T>
void print(vector<T> &p){rep(i,si(p)) cout << p[i] << " "; cout << endl;}
ll ceil(ll x , ll y){return (x+y-1)/y;}


int main(){

    string s;
    cin >> s;

    ll len = si(s);

    string t;

    ll ans = 0;

    unordered_set<ll> st;
    rng(i,1,(ll)1e6){
        ll num = (i * (i+1)) / 2;
        st.insert(num);
    }

    auto f = [&](string str) -> bool{
        ll n = si(str);
        ll a = 0;
        rep(i,n){
            a += ((str[i] - 'A') + 1);
        }
        if(st.count(a)){
            return true;
        }
        return false;
    };

    ll cnt = 0;

    rep(i,len){
        if(s[i] == '"'){
            if(cnt % 2 == 1){
                if(f(t)){
                    ans++;
                }
                t.clear();
            }
            cnt++;
        }
        else if(s[i] == ','){
            continue;
        }
        else{
            t += s[i];
        }
    }

    cout << ans << endl;

    return 0;
}