/*
struct rolling_hash{
  string s;
  int n;
  const vector<long long>mods={999999937ll, 1000000007ll};
  long long base;
  vector<long long>hashs[2];
  vector<long long>pows[2];
  rolling_hash(string const &t,long long b=10007):s(t),base(b){
    for(int i=0;i<2;i++){
      n=(int)s.size();
      hashs[i].assign(n+1,0ll); pows[i].assign(n+1,1);
      for(int j=0;j<n;j++){
        hashs[i][j+1]+=(hashs[i][j]*base+s[j])%mods[i];
        pows[i][j+1]=(pows[i][j]*base)%mods[i];
      }
    }
  }
  inline long long get(int l,int r,int id=0){
    long long res=hashs[id][r] - hashs[id][l]*pows[id][r-l]%mods[id];
    if(res<0) res+=mods[id];
    return res;
  }
};
*/