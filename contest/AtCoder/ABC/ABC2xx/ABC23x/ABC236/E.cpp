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
    ll n; cin >> n;
    vll a(n); cin >> a;
    vll odd,even;
    rep(i,0,n){
        odd.push_back(a[i]);
        swap(odd,even);
    }
    sort(all(odd));
    sort(all(even));
    ll odn=odd.size();
    ll evn=even.size();
    // 中央値
    ll oddc=odd[(odn+1)/2];
    ll evec=even[(evn+1)/2];
    vll x=odd,y=even;
    rep(i,0,odn) if(evec<odd[i]) y.push_back(odd[i]);
    rep(i,0,evn) if(oddc<even[i]) x.push_back(even[i]);
    sort(all(x)); sort(all(y));
    dump(x,y);
    ll ans=max(x[(x.size()+1)/2-1],y[(y.size()+1)/2-1]);
    // 平均値
    ll oddsum=0;
    ll evesum=0;
    fore(c,odd) oddsum+=c;
    fore(c,even) evesum+=c;
    ld oddave=1.0*oddsum/odn;
    ld eveave=1.0*evesum/evn;
    ll odnc=odn, evnc=evn;
    rrep(i,evn-1,0) if(even[i]>=oddave){
        oddsum+=even[i];
        odnc++;
        oddave=oddsum/odnc;
    }
    rrep(i,odn-1,0) if(odd[i]>=eveave){
        evesum+=odd[i];
        evnc++;
        eveave=evesum/evnc;
    } 
    dump(oddave,eveave);
    cout << fixed << setprecision(15) << max(oddave,eveave) << endl; 
    cout << ans << endl;
}