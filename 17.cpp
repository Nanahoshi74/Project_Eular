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

    // ll ans = 0;

    ll ans2 = 0;

    map<string,ll> mp;
    map<char,ll> u;
    u['0'] = 0;
    u['1'] = 3;//one
    u['2'] = 3;//two
    u['3'] = 5;//three
    u['4'] = 4;//four
    u['5'] = 4;//five
    u['6'] = 3;//six
    u['7'] = 5;//seven
    u['8'] = 5;//eight
    u['9'] = 4;//nine
    mp["10"] = 3;//ten
    mp["11"] = 6;//eleven
    mp["12"] = 6;//twelve
    mp["13"] = 8;//thirteen
    mp["14"] = 8;//fourteen
    mp["15"] = 7;//fifteen
    mp["16"] = 7;//sixteen
    mp["17"] = 9;//seventeen
    mp["18"] = 8;//eighteen
    mp["19"] = 8;//nineteen
    mp["20"] = 6;//twenty
    mp["30"] = 6;//thirty
    mp["40"] = 5;//forty
    mp["50"] = 5;//fifty
    mp["60"] = 5;//sixty
    mp["70"] = 7;//seventy
    mp["80"] = 6;//eighty
    mp["90"] = 6;//ninety


    rng(i,1,1001){
        ll ans = 0;
        string s = to_string(i);
        if(si(s) == 1){//一桁
            char x = itoc(i);
            ans += u[x];
        }
        else if(si(s) == 2){
            if(s[1] == '0'){
                ans += mp[s];
            }
            else{
                if(s[0] == '1'){
                    ans += mp[s];
                }
                else{
                    string t = s;
                    t.pop_back();
                    t.push_back('0');
                    ans += mp[t];
                    ans += u[s[1]];
                }
            }
        }
        else if(si(s) == 3){
            ans += u[s[0]];
            ans += 7;//hundred
            if(s[1] == '0' && s[2] == '0'){
                
            }
            else if(s[1] == '0' && s[2] != '0'){
                ans += 3;//and
                ans += u[s[2]];
            }
            else if(s[1] == '1'){
                ans += 3;//and
                string t;
                t += s[1];
                t += s[2];
                ans += mp[t];
            }
            else{
                ans += 3;//and
                string t;
                t += s[1];
                t += s[2];
                t.pop_back();
                t.push_back('0');
                ans += mp[t];
                ans += u[s[2]];
            }
        }
        else{
            ans += 11;//one thousand
        }
        ans2 += ans;
        cout << s << " " << ans << endl;
    }

    cout << ans2 << endl;

    return 0;
}