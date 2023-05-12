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

int main(){

    vector<string> s;
    s.pb("73167176531330624919225119674426574742355349194934");
    s.pb("96983520312774506326239578318016984801869478851843");
    s.pb("85861560789112949495459501737958331952853208805511");
    s.pb("12540698747158523863050715693290963295227443043557");
    s.pb("66896648950445244523161731856403098711121722383113");
    s.pb("62229893423380308135336276614282806444486645238749");
    s.pb("30358907296290491560440772390713810515859307960866");
    s.pb("70172427121883998797908792274921901699720888093776");
    s.pb("65727333001053367881220235421809751254540594752243");
    s.pb("52584907711670556013604839586446706324415722155397");
    s.pb("53697817977846174064955149290862569321978468622482");
    s.pb("83972241375657056057490261407972968652414535100474");
    s.pb("82166370484403199890008895243450658541227588666881");
    s.pb("16427171479924442928230863465674813919123162824586");
    s.pb("17866458359124566529476545682848912883142607690042");
    s.pb("24219022671055626321111109370544217506941658960408");
    s.pb("07198403850962455444362981230987879927244284909188");
    s.pb("84580156166097919133875499200524063689912560717606");
    s.pb("05886116467109405077541002256983155200055935729725");
    s.pb("71636269561882670428252483600823257530420752963450");

    string t;
    rep(i,si(s)){
        t += s[i];
    }
    ll ans = -1;
    rep(i,988){
        ll cnt = 1;
        rep(j,13){
            cnt *= ctoi(t[i + j]);
        }
        ans = max(ans,cnt);
    }

    cout << ans << endl;

    return 0;
}