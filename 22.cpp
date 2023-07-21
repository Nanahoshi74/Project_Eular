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

    ifstream in("0022_names.txt");
    cin.rdbuf(in.rdbuf());

    ll ans = 0;
    string s;
    cin >> s;
    vector<string> s_list;
    ll cnt = 0;
    string t;
    rep(i,si(s)){
        if(s[i] == '"'){
            cnt++;
        }
        if(cnt % 2 == 1 && s[i] != '"' && s[i] != ','){
            t += s[i];
        }
        if(cnt != 0 && cnt % 2 == 0 && s[i] == '"'){
            s_list.push_back(t);
            t.clear();
        }
    }
    sort(all(s_list));
    rep(i,si(s_list)){
        ll tmp = 0;
        rep(j,si(s_list[i])){
            tmp += (s_list[i][j] - 'A') + 1;
        }
        ans += (i + 1) * tmp;
    }

    cout << ans << endl;

    return 0;
}