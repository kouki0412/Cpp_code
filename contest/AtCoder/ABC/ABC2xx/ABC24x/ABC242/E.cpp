//#define _GLIBCXX_DEBUG
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#endif
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<vector<int>>; 
using vvll = vector<vector<ll>>;
const ll INF = 1ll<<60;
const ld EPS = 1.0/1e9;
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define all(x) (x).begin(),(x).end()
#define del(x) sort(all(x)); x.erase(unique(all(x)),x.end());

#define DEBUG_

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
template<typename T>
ostream& operator << (ostream &os, vector<T>& vec){
  os << "{";
  for(int i=0;i<vec.size();i++){
    os << vec[i] << (i+1==vec.size() ? "" : ", ");
  }
  os << "}";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

#define DUMPOUT cerr

void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while(t--){
        ll n; string s; cin >> n >> s;
        string m;
        rep(i,0,n/2) m += char(min(s[i]-'A',s[n-i-1]-'A')+'A');
        if(n%2==1) m += s[n/2];
        vector<vector<mint>>dp(n/2+n%2+1,vector<mint>(26));
        rep(i,0,n/2){
            rep(j,0,26){
                rep(k,0,26){
                    dp[i+1][j]+=dp[i][k]; 
                }
            }
            rep(j,0,m[i]-'A'){
                dp[i][j]++;
            }

        }
        rep(i,0,26) if(n%2==1){
            dp[n/2+1][i] += dp[n/2][i]*26;
            dp[n/2+1][i] += (m[n/2]-'A');
        }
        mint ans=0;
        rep(i,0,26) ans += dp[n/2+n%2][i];
        cout << ans.val()+1 << endl;
    }
}