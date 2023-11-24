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

bool isprime(long long N) {
    if (N < 2) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main(){

    ll ans = 0;

    map<ll,ll> mp;

    rng(i,2,1000001){
        if(mp[i] == 2){
            continue;
        }
        else if(mp[i] == 1){
            // cout << i << endl;
            ans++;
        }
        else{
            string s = to_string(i);
            deque<char> dq;
            vector<ll> p;
            bool ok = true;
            rep(j,si(s)){
                dq.push_back(s[j]);
            }
            rep(j,si(s)){
                char c = dq.front();
                string t;
                rep(k,si(s)){
                    t += dq[k];
                }
                ll v = stoll(t);
                p.push_back(v);
                if(!isprime(v)){
                    ok = false;
                    mp[v] = 2;
                }
                else{
                    mp[v] = 1;
                }
                dq.pop_front();
                dq.push_back(c);
            }
            if(ok){
                ans++;
                // cout << i << endl;
            }
            else{
                for(auto v : p){
                    mp[v] = 2;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}