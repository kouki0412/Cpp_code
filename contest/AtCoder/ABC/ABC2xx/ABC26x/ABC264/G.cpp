//#define _GLIBCXX_DEBUG
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#endif
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>; 
using vvll = vector<vector<ll>>;
const ll INF = 1ll<<60;
const ld EPS = 1.0/1e9;
#define endl "\n"
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
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
    ll n; cin >> n;
    vector<vector<pair<string,ll>>>edge(3);
    rep(i,0,n){
        string s; ll p; cin >> s >> p;
        edge[s.size()-1].emplace_back(s,p);
    }

    fore(e1,edge[1]) fore(e0,edge[0]){
        rep(i,0,2) if(e0.first==e1.first.substr(i,1)) e1.second += e0.second;
    }
    fore(e2,edge[2]) fore(e0,edge[0]){
        rep(i,0,3) if(e0.first==e2.first.substr(i,1)) e2.second += e0.second;
    }
    fore(e2,edge[2]) fore(e1,edge[1]){
        rep(i,0,2) if(e1.first==e2.first.substr(i,2)) e2.second += e1.second;
    }
    vector<vector<ll>>dp(26,vector<ll>(26));

    map<string,ll>hosei;
    fore(e2,edge[2]) hosei[e2.first]=e2.second;

    fore(e0,edge[0]){
        ll u = (e0.first[0]-'a');
        dp[u][u] = e0.second;
    }
    fore(e1,edge[1]){
        ll u = (e1.first[0]-'a');
        ll v = (e1.first[1]-'a');        
        dp[u][v] = e1.second;
    }
    ll ans = -INF;
    rep(i,0,26) rep(j,0,26){
        ans = max(ans,dp[i][j]);
    }
    rep(k,0,26) rep(i,0,26) rep(j,0,26){
        string t =""; 
        t += char(i+'a');
        t += char(k+'a');
        t += char(j+'a');
        dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+hosei[t]);
    }
    rep(i,0,26) rep(j,0,26){
        ans = max(ans,dp[i][j]);
    }
    cout << ans << endl;
}