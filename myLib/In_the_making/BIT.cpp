/*

template<typename X> struct BIT{
  int n; vector<X>bits[2];
  BIT(int n_){init(n_);}
  void init(int n_){
    n = n_+ 1 ;
    bits[0].assign(n,0); bits[1].assign(n,0);
  }
  void add_sub(int s,X x,int id=0){
    for(int j=s;j<n;j+=(j & -j)){
      bits[id][j]+= x;
    }
  }
  void add(int l,int r,X x){
    add_sub(l, -x * (l - 1), 0); add_sub(r, x * (r - 1), 0);
    add_sub(l, x, 1); add_sub(r, -x, 1);
  }
  X sum_sub(int x,int id=0){
    X res=0;
    for(int j=x;j>0;j-=(j & -j)){
      res += bits[id][j];
    }
    return res;
  }
  X sum(int i){
    return sum_sub(i,0)+sum_sub(i,1)*i;
  }
  X query(int l, int r){
    return sum(r - 1)-sum(l - 1);
  }
  int lower_bound(X w){
    if(w<=0){
      return 0;
    }
    else{
      int x=0; int r=1;
      while(r<n) r=(r<<1);
      for(int len=r;len>0;len=len>>1){
        if(x+len<n && bits[0][x+len]<w){
          w-=bits[0][x+len]; x+=len;
        }
      }
      return x+1;
    }
  }
};

*/