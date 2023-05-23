
struct factorial{
    int n, mod;
    vector<long long>fac,rev;
    factorial(int n_,int mod_):n(n_),mod(mod_){
        fac.resize(n_+1,1); rev.resize(n_+1,1);
        for(int i=1;i<=n_;i++){
            fac[i] = (fac[i-1] * i) % mod_;
            rev[i] = (rev[i-1] * Pow(i,mod_-2)) % mod_;
        }
    }
    long long Pow(long long x, long long y) {
        long long ret = 1;
        while(y > 0) {
            if(y & 1) (ret *= x) %= mod;
                (x *= x) %= mod;
                y >>= 1;
        }
        return ret;
    }
    long long aCb(int a,int b){
        assert(a>=b);
        long long ret = 1;
        ret = (ret*fac[a])%mod;
        ret = (ret*rev[a-b])%mod;
        ret = (ret*rev[b])%mod;
        return ret;
    }
    void print(){
        for(int i=0;i<=n;i++){
            cout << fac[i] << endl;
        }
    }
};
