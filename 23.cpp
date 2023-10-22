#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
//using mint = modint1000000007;
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
void chmin(ll& x,ll y){x = min(x,y);}
void chmax(ll& x,ll y){x = max(x,y);}
ll getnum(ll x, ll y, ll H, ll W) { (void) H; return (x * W + y);}
template<typename T>
void print(vector<T> &p){rep(i,si(p)) cout << p[i] << " "; cout << endl;}

ll divisor_sum(long long n) {//**************************約数列挙************************:
    ll ret = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret += i;
            if (i * i != n) ret += n/i;
        }
    }
    // sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret-n;
}



int main(){

    // ifstream in("???.txt");
    // cin.rdbuf(in.rdbuf());

    set<ll> st;
    vector<ll> u;

    ll ans = 0;

    rng(i,12,28124){
        ll p = divisor_sum(i);
        if(p > i){
            u.push_back(i);
        }
    }

    for(auto A : u){
        for(auto B : u){
            st.insert(A + B);
        }
    }

    rng(i,1,28124){
        if(!st.count(i)){
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}