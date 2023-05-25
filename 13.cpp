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

vector<int> string_to_bigint(string S) {///////string から足し引きするためのvectorへ(逆順)//////
    int N = S.size(); // N = (文字列 S の長さ)
    vector<int> digit(N);
    for(int i = 0; i < N; ++i) {
        digit[i] = S[N - i - 1] - '0'; // 10^i の位の数
    }
    return digit;
}


string bigint_to_string(vector<int> digit) {/////////////////////vector からstring へ(逆順にすることで正しい順数字になっている)
    int N = digit.size(); // N = (配列 digit の長さ)
    string str = "";
    for(int i = N - 1; i >= 0; --i) {
        str += digit[i] + '0';
    }
    return str;
}

vector<int> carry_and_fix(vector<int> digit) {////////繰り上がり処理///////////////
    int N = digit.size();
    for(int i = 0; i < N - 1; ++i) {
        // 繰り上がり処理 (K は繰り上がりの回数)
        if(digit[i] >= 10) {
            int K = digit[i] / 10;
            digit[i] -= K * 10;
            digit[i + 1] += K;
        }
        // 繰り下がり処理 (K は繰り下がりの回数)
        if(digit[i] < 0) {
            int K = (-digit[i] - 1) / 10 + 1;
            digit[i] += K * 10;
            digit[i + 1] -= K;
        }
    }
    // 一番上の桁が 10 以上なら、桁数を増やすことを繰り返す
    while(digit.back() >= 10) {
        int K = digit.back() / 10;
        digit.back() -= K * 10;
        digit.push_back(K);
    }
    // 1 桁の「0」以外なら、一番上の桁の 0 (リーディング・ゼロ) を消す
    while(digit.size() >= 2 && digit.back() == 0) {
        digit.pop_back();
    }
    return digit;
}

vector<int> addition(vector<int> digit_a, vector<int> digit_b) {//////////////vector同士の足し算///////////
    int N = max(digit_a.size(), digit_b.size()); // a と b の大きい方
    vector<int> digit_ans(N); // 長さ N の配列 digit_ans を作る
    for(int i = 0; i < N; ++i) {
        digit_ans[i] = (i < digit_a.size() ? digit_a[i] : 0) + (i < digit_b.size() ? digit_b[i] : 0);
        // digit_ans[i] を digit_a[i] + digit_b[i] にする (範囲外の場合は 0)
    }
    return carry_and_fix(digit_ans); // 2-4 節「繰り上がり計算」の関数です
}

int main(){

    vector<vector<int>> a(100,vector<int>(50));

    rep(i,100){
        string s;
        cin >> s;
        a[i] = string_to_bigint(s);
    }
    vector<int> ans;
    ans = addition(a[0],a[1]);
    rng(i,2,100){
        ans = addition(ans,a[i]);
    }

    string t = bigint_to_string(ans);

    rep(i,10){
        cout << t[i];
    }
    cout << endl;


    return 0;
}