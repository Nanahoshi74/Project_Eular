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

vector<int> subtraction(vector<int> digit_a, vector<int> digit_b) {//////////////////vetor同士の引き算//////////
    int N = max(digit_a.size(), digit_b.size()); // a と b の大きい方
    vector<int> digit_ans(N); // 長さ N の配列 digit_ans を作る
    for(int i = 0; i < N; ++i) {
        digit_ans[i] = (i < digit_a.size() ? digit_a[i] : 0) - (i < digit_b.size() ? digit_b[i] : 0);
        // digit_ans[i] を digit_a[i] - digit_b[i] にする (範囲外の場合は 0)
    }
    return carry_and_fix(digit_ans); // 2-4 節「繰り上がり計算」の関数です
}

vector<int> multiplication(vector<int> digit_a, vector<int> digit_b) {/////////////vector同士の掛け算////////
    int NA = digit_a.size(); // A の桁数
    int NB = digit_b.size(); // B の桁数
    vector<int> res(NA + NB - 1);
    for(int i = 0; i < NA; ++i) {
        for(int j = 0; j < NB; ++j) {
            res[i+j] += digit_a[i] * digit_b[j];
            // 答えの i+j の位に digit_a[i] * digit_b[j] を足す
        }
    }
    return carry_and_fix(res);
}

int compare_bigint(vector<int> digit_a, vector<int> digit_b) {
    int NA = digit_a.size(); // A の桁数
    int NB = digit_b.size(); // B の桁数
    if(NA > NB) return +1; // 左が大きい
    if(NA < NB) return -1; // 右が大きい
    for(int i = NA - 1; i >= 0; --i) {
        if(digit_a[i] > digit_b[i]) return +1; // 左が大きい
        if(digit_a[i] < digit_b[i]) return -1; // 右が大きい
    }
    return 0;
}

vector<int> division(vector<int> digit_a, vector<int> digit_b) {
    int NA = digit_a.size(), NB = digit_b.size();
    if(NA < NB) return { 0 };
    // ----- ステップ 1. A ÷ B の桁数を求める ----- //
    int D = NA - NB;
    // digit_a_partial : A の上 NB 桁を取り出したもの
    vector<int> digit_a_partial(digit_a.begin() + (NA - NB), digit_a.end());
    if(compare_bigint(digit_a_partial, digit_b) >= 0) {
        // (A の上 NB 桁) が B 以上だったら...？
        D = NA - NB + 1;
    }
    // ----- ステップ 2. A ÷ B を筆算で求める ----- //
    if(D == 0) return { 0 };
    vector<int> remain(digit_a.begin() + (D - 1), digit_a.end());
    vector<int> digit_ans(D);
    for(int i = D - 1; i >= 0; --i) {
        digit_ans[i] = 9;
        for(int j = 1; j <= 9; ++j) {
            vector<int> x = multiplication(digit_b, { j });
            if(compare_bigint(x, remain) == 1) {
                digit_ans[i] = j - 1;
                break;
            }
        }
        vector<int> x_result = multiplication(digit_b, { digit_ans[i] });
        remain = subtraction(remain, x_result);
        if(i >= 1) {
            // 新しく 10^(i-1) の位が降りてくる
            remain.insert(remain.begin(), digit_a[i - 1]);
        }
    }
    return digit_ans;
}


int main(){

	vector<int> a;
	a.pb(1);
	vector<int> b;
	b.pb(1);
	rng(i,3,INF){
		vector<int> f = addition(a,b);
		if(si(f) >= 1000){
			cout << i << endl;
			return 0;
		}
		a = b;
		b = f;
	}

    return 0;
}