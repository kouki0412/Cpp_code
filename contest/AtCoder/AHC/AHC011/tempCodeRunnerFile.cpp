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

#include<atcoder/dsu>
using namespace atcoder;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    clock_t start = clock();
    int n,t; cin >> n >> t;
    vector<string>s(n); cin >> s;
    vector<vector<int>>com(n,vector<int>(n));
    int sx=-1,sy=-1;
    rep(i,0,n) rep(j,0,n){
        if(s[i][j]<='9') com[i][j] = s[i][j]-'0';
        else com[i][j] = s[i][j]-'a'+10;
        
        if(com[i][j]==0){
            sx = i; sy = j;
        }
    }
    deque<tuple<int,int,int,string,vector<vector<int>>,int>>que;
    que.push_back({sx,sy,-1,"",com,0});
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    char C[] = {'U','L','D','R'};

    int Max = -1; string ans;
    map<vector<vector<int>>,bool>mp;
    
    while(!que.empty()){
        if(2.85*CLOCKS_PER_SEC <=  static_cast<double>(clock()-start)){
          cout << ans;
          return 0;
        }
        int x,y,p,cnt; string str; vector<vector<int>>co; tie(x,y,p,str,co,cnt)=que.front(); que.pop_front();
        rep(i,0,4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 or ny<0 or nx>=n or ny>=n) continue;
            if(p==0 and i==2) continue;
            if(p==2 and i==0) continue;
            if(p==1 and i==3) continue;
            if(p==3 and i==1) continue;
            swap(co[x][y],co[nx][ny]);
            if(mp[co]) continue;
            mp[co]=true;
            dsu d(n*n);
            rep(l,0,n) rep(j,0,n){
                if(l<n-1 and co[l][j]&8 and co[l+1][j]&2) d.merge(n*l+j,n*(l+1)+j); 
                if(j<n-1 and co[l][j]&4 and co[l][j+1]&1) d.merge(n*l+j,n*l+j+1); 
            }
            int L = 0;
            fore(c,d.groups()) L = max(L,int(c.size()));
            int len=str.size();
            if(L > Max){
                Max = L; ans = str + C[i];
                if(len <t) que.push_front({nx,ny,i,str + C[i],co,0});
            }
            else{
                if(cnt>8) break;
                if(len<t) que.push_back({nx,ny,i,str + C[i],co,cnt+1});
            }
          	if(2.85*CLOCKS_PER_SEC <=  static_cast<double>(clock()-start)){
          		cout << ans;
          		return 0;
        	}
        }
    }
    cout << ans << endl;
}