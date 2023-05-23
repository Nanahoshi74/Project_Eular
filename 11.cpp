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

bool isvalid(int x, int y) {
    if(0 <= x && x < 20 && 0 <= y && y < 20) {return true;}
    else {return false;}
}

int main(){

    vector<vector<ll>> a(20,vector<ll>(20));
    rep(i,20){
        rep(j,20){
            cin >> a[i][j];
        }
    }

    ll ans = -1;
    rep(i,20){
        rep(j,20){
            ////////////右
            ll p = a[i][j];
            if(isvalid(i,j+1)){
                p *= a[i][j+1];
            }
            if(isvalid(i,j+2)){
                p *= a[i][j+2];
            }
            if(isvalid(i,j+3)){
                p *= a[i][j+3];
            }
            ans = max(ans,p);
            ////////////////下
            p = a[i][j];
            if(isvalid(i+1,j)){
                p *= a[i+1][j];
            }
            if(isvalid(i+2,j)){
                p *= a[i+2][j];
            }
            if(isvalid(i+3,j)){
                p *= a[i+3][j];
            }
            ans = max(ans,p);
            ////////////////////斜め右
            p = a[i][j];
            if(isvalid(i+1,j+1)){
                p *= a[i+1][j+1];
            }
            if(isvalid(i+2,j+2)){
                p *= a[i+2][j+2];
            }
            if(isvalid(i+3,j+3)){
                p *= a[i+3][j+3];
            }
            ans = max(ans,p);
            ///////////////////斜め左
            p = a[i][j];
            if(isvalid(i+1,j-1)){
                p *= a[i+1][j-1];
            }
            if(isvalid(i+2,j-2)){
                p *= a[i+2][j-2];
            }
            if(isvalid(i+3,j-3)){
                p *= a[i+3][j-3];
            }
            ans = max(ans,p);
        }
    } 

    cout << ans << endl;


    return 0;
}