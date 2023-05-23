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

vector<bool>seen,finished;
stack<ll>hist;
ll pos = -1;

void dfs(vvll& G,ll p,ll v){
    seen[v] = true;
    hist.push(v);
    fore(nv,G[v]) if(nv!=p){
        if(finished[nv]){
            continue;
        }
        if(seen[nv] and !finished[nv]){
            pos = nv;
            return;
        }
        dfs(G,v,nv);
        if(pos!=-1) return;
    }
    hist.pop();
    finished[v] = true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    seen.resize(n);
    finished.resize(n);
    vvll G(n);
    vll u(n),v(n);
    rep(i,0,n){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    dfs(G,-1,0);
    vll mp(n);
    while (!hist.empty()) {
        int t = hist.top();
        mp[t] = 1;
        hist.pop();
        if (t == pos) break;
    }
    ll q; cin >> q;
    dsu D(n);
    rep(i,0,n){
        if(!(mp[u[i]] and mp[v[i]])) D.merge(u[i],v[i]);
    }
    while(q--){
        ll x,y; cin >> x >> y;
        x--; y--;
        if((mp[x] and mp[y]) or (!D.same(x,y))) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}