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
    ll n,m; cin >> n >> m;
    vll a(m),b(m),c(m);
    vector<vector<pair<ll,ll>>>G(n);
    map<pair<ll,ll>,ll>mp;
    rep(i,0,m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        G[a[i]].push_back({b[i],c[i]});
        G[b[i]].push_back({a[i],c[i]});
        mp[{a[i],b[i]}]=i+1;
        mp[{b[i],a[i]}]=i+1;
    }
    queue<ll>que; vector<ll>dist(n,INF);
    que.push(0); dist[0]=0;
    while(!que.empty()){
        ll v=que.front(); que.pop();
        fore(nv,G[v]){
            if(dist[nv.first]<=dist[v]+nv.second) continue;
            dist[nv.first]=dist[v]+nv.second;
            que.push(nv.first);
        }
    }
    vector<pair<ll,ll>>sorted(n);
    rep(i,0,n) sorted[i]={dist[i],i};
    sort(all(sorted));
    vector<bool>seen(n);
    vector<pair<ll,ll>>ans;
    fore(c,sorted){
        ll i,j; tie(j,i)=c;
        if(seen[i]) continue;
        queue<ll>que2; que2.push(i);
        while(!que2.empty()){
            ll v=que2.front(); que2.pop();
            if(seen[v]) continue;
            seen[v]= true; 
            fore(nv,G[v]){
                if(dist[v]-nv.second==dist[nv.first]){
                    que2.push(nv.first);
                    ans.push_back({v,nv.first});
                }
            }
        }
    }
    dsu D(n);
    vll nans;
    fore(c,ans){
        if(D.same(c.first,c.second)) continue;
        D.merge(c.first,c.second);
        nans.push_back(mp[{c.first,c.second}]);
    }
    rep(i,0,n-1){
        if(i) cout << " ";
        cout << nans[i];
    }
}