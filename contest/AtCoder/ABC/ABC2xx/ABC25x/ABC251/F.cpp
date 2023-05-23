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

void dfs(ll v,vector<bool>&seen2,vector<vector<pair<ll,ll>>>&G,vector<pair<ll,ll>>&t1,vll &x,vll &y){
    seen2[v]=true;
    fore(nv,G[v]){
        ll to,id; tie(to,id)=nv;
        if(seen2[to]) continue;
        seen2[to]=true;
        t1.push_back({x[id]+1,y[id]+1});
        dfs(to,seen2,G,t1,x,y);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m; cin >> n >> m;
    ll l=m-(n-1);
    vll x(m),y(m);
    vector<vector<pair<ll,ll>>>G(n);
    rep(i,0,m){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        G[x[i]].push_back({y[i],i});
        G[y[i]].push_back({x[i],i});
    }
    vector<pair<ll,ll>>t1,t2;
    vector<bool>seen(n),seen2(n);
    seen[0]=true; queue<ll>que;
    que.push(0);
    while(!que.empty()){
        ll v=que.front(); que.pop();
        fore(nv,G[v]){
            ll to,id; tie(to,id)=nv;
            if(seen[to]) continue;
            seen[to]=true;
            t2.push_back({x[id]+1,y[id]+1});
            que.push(to);
        }
    }
    dfs(0,seen2,G,t1,x,y);
    rep(i,0,n-1) cout << t1[i].first << " " << t1[i].second << endl;
    rep(i,0,n-1) cout << t2[i].first << " " << t2[i].second << endl;
}