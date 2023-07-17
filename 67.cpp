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

    const ll n = 100;

    vector<vector<ll>> triangle(n);
    vector<vector<ll>> dp(n,vector<ll>(n,0));

    ifstream in("67.txt");
    cin.rdbuf(in.rdbuf());

    rep(i,n){
        vector<ll> a(i+1);
        rep(j,i+1){
            cin >> a[j];
        }
        triangle[i] = a;
    }
    dp[0][0] = triangle[0][0];

    rng(i,0,n-1){
        rep(j,i+2){
            if(j == 0){
                dp[i+1][j] = dp[i][j] + triangle[i+1][j];
            }
            else if(j == i+1){
                dp[i+1][j] = dp[i][j-1] + triangle[i+1][j];
            }
            else{
                dp[i+1][j] = max(dp[i][j] + triangle[i+1][j],dp[i][j-1] + triangle[i+1][j]);
            }
        }
    }

    cout << *max_element(all(dp[n-1])) << endl;
    

    return 0;
}