

template <typename T>
struct mysegtree{
  using FX = function<T(T,T)>;
  int n; FX fx; const T ex; vector<T>dat;
  mysegtree(int n_,FX fx_, T ex_):n(),fx(fx_),ex(ex_),dat(n_*4,ex_){
    int x=1;
    while(n_ > x) x *= 2;
    n = x;
  }

  void set(int i,T x){ dat[i+n-1]=x;}
  void build(){for(int k=n-2;k>=0;k--) dat[k]=fx(dat[2*k+1],dat[2*k+2]);}
  void update(int i,T x){
    i += n-1;
    dat[i]=x;
    while(i>0){
      i=(i-1)/2;
      dat[i] = fx(dat[i*2+1],dat[i*2+2]);
    }
  }
  T get(int a){
    return dat[n+a-1];
  }
  T prod(int a,int b) {return prod_sub(a,b,0,0,n);}
  T prod_sub(int a,int b,int k,int l,int r){
    if(r<=a || b<=l) return ex;
    else if(a<=l && r<=b) return dat[k];
    else{
      T vl = prod_sub(a,b,k*2+1,l,(l+r)/2);
      T vr = prod_sub(a,b,k*2+2,(l+r)/2,r);
      return fx(vl,vr);
    }
  }
};

