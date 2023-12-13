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

    vector<P> pa;//firstが分母、secondが分子
    rng(i,10,100){
        rng(j,10,i){
            //iが分母、jが分子
            string si = to_string(i);
            string sj = to_string(j);
            if(si[0] == sj[0] && si[0] != '0'){
                if(i * ctoi(sj[1]) == j * ctoi(si[1])){
                    P p = {ctoi(si[1]), ctoi(sj[1])};
                    pa.emplace_back(p);
                }
            }
            if(si[1] == sj[0] && si[1] != '0'){
                if(i * ctoi(sj[1]) == j * ctoi(si[0])){
                    P p = {ctoi(si[0]), ctoi(sj[1])};
                    pa.emplace_back(p);
                }
            }
            if(si[0] == sj[1] && si[0] != '0'){
                if(i * ctoi(sj[0]) == j * ctoi(si[1])){
                    P p = {ctoi(si[1]), ctoi(sj[0])};
                    pa.emplace_back(p);
                }
            }
            if(si[1] == sj[1] && si[1] != '0'){
                if(i * ctoi(sj[0]) == j * ctoi(si[0])){
                    P p = {ctoi(si[0]), ctoi(sj[0])};
                    pa.emplace_back(p);
                }
            }
        }
    }

    ll Nume_ans = 1;//分子
    ll Deno_ans = 1;//分母
    rep(i,4){
        Nume_ans *= pa[i].second;
        Deno_ans *= pa[i].first;
    }

    cout << "答えは " << Deno_ans / gcd(Nume_ans, Deno_ans) << endl;//約分したときの分母を求める

    // cout << Nume_ans << " / " << Deno_ans << endl;

    // cout << Nume_ans / gcd(Nume_ans, Deno_ans) << " / " << Deno_ans / gcd(Nume_ans, Deno_ans) << endl;

    return 0;
}