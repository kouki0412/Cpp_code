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
    ll n,m,k,s,t,x; cin >> n >> m >> k >> s >> t >> x;
    s--; t--; x--;
    vvll G(n);
    rep(i,0,m){
        ll u,v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    mint ans=0;
    vector<vector<vector<mint>>>dp(k+1,vector<vector<mint>>(n,vector<mint>(2)));
    vector<vector<bool>>seen(k+1,vector<bool>(n));
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>>que;
    dp[0][s][0]=1; que.push({0,0,s});
    while(!que.empty()){
        ll a,b,c; tie(a,b,c)=que.top(); que.pop();
        if(seen[a][c]) continue;
        fore(v,G[c]){
            if(a==k-1){
                if(v==t){
                    ans += dp[a][c][0];
                }
            }
            else{
                if(x==v){
                    dp[a+1][v][0] += dp[a][c][1];
                    dp[a+1][v][1] += dp[a][c][0];
                    que.push({a+1,b+1,v});
                }
                else{
                    dp[a+1][v][0] += dp[a][c][0];
                    dp[a+1][v][1] += dp[a][c][1];
                    que.push({a+1,b,v});
                }
            }
        }
        seen[a][c]=true;
    }
    cout << ans.val() << endl;
}