/*

template<typename X>struct weighted_unionfind{
  vector<int>par; vector<int>rank; vector<X>diffs;
  weighted_unionfind(int n=1,X sum=0){
    init(n,sum);
  }
  void init(int n=1,X sum=0){
    par.resize(n); rank.resize(n); diffs.resize(n);
    for(int i=0;i<n;i++){
      par[i]=i; rank[i]=0; diffs[i]=sum;
    }
  }
  int root(int x){
    if(par[x]==x) return x;
    else{
      int r=root(par[x]);
      diffs[x] += diffs[par[x]];
      return par[x]=r;
    }
  }
  X weight(int x){
    root(x);
    return diffs[x];
  }
  bool same(int x,int y){
    return root(x)==root(y);
  }
  bool merge(int x,int y, X w){
    w+=weight(x); w-=weight(y);
    x=root(x); y=root(y);
    if(x==y) return false;
    if(rank[x]<rank[y]){
      swap(x,y); w=-w;
    }
    if(rank[x]==rank[y]) rank[x]++;
    par[y]=x;
    diffs[y]=w;
    return true;
  }
  X diff(int x,int y){
    return weight(y)-weight(x);
  }
};

*/