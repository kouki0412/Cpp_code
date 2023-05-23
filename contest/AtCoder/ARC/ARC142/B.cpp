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
    vvll ans(n,vll(n));
    rep(N,1,n+1){
        vll Min,Max;
        rep(i,0,N) Max.push_back(N*N-i);
        rep(i,0,N) Min.push_back((N-1)*(N-1)+i+1);
        ll ind=0;
        for(int i=N-2;i>=0;i-=2){
            ans[N-1][i]=Min[ind];
            ind ++;
        }
        for(int i=N-2;i>=0;i-=2){
            ans[i][N-1]=Min[ind];
            ind++;
        }
        ind = 0;
        rrep(i,N-1,0) if(ans[i][N-1]==0 and ind<Max.size()){
            ans[i][N-1] = Max[ind];
            ind ++;
        }
        rrep(i,N-1,0) if(ans[N-1][i]==0 and ind<Max.size()){
            ans[N-1][i] = Max[ind];
            ind ++;
        }

    }
    set<ll>st;
    rep(i,0,n){
        rep(j,0,n){
            cout << ans[i][j] << " ";
            st.insert(ans[i][j]);
        }
       cout << endl;
    }
    /*rep(i,1,n-1) rep(j,1,n-1){
        ll sum=0;
        rrep(x,1,-1) rrep(y,1,-1){
            if(x==0 and y==0) continue;
            if(ans[i][j]<ans[i+x][j+y]) sum++;
            else sum--;
        }
        if(sum==0) cout << i << " " << j << endl;
    }*/
}