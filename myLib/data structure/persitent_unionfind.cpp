/*

struct persistentUnionFind{
    int last;
    vector<int>par,siz,time;
    vector<vector<pair<int,int>>>num;
    persistentUnionFind(int n){
        last=0;
        par.resize(n);
        num.resize(n);
        siz.resize(n,1);
        time.resize(n,(INT_MAX));
        for(int i=0;i<n;i++){
            par[i] = i;
            num[i].emplace_back(make_pair(0,1));
        }
    }
    int root(int x,int t){
        if(t<time[x]) return x;
        else root(par[x],t);
    }
    bool same(int x,int y, int t){
        return root(x,t)==root(y,t);
    }
    bool merge(int x, int y){
        last++;
        x=root(x,last); y=root(y,last);
        if(x==y) return false;
        if(siz[x]<siz[y]) swap(x,y);
        num[x].push_back(make_pair(last,size(x,last)+size(y,last)));
        par[y]=x;
        time[y]=last;
        if(siz[x]==siz[y]) siz[x]++;
        return true;
    }
    int size(int x,int t){
        x = root(x,t);
        int ok=0; int ng=num[x].size();
        while(ng - ok>1){
            int mid = (ok+ng)/2;
            if(num[x][mid].first<=t) ok=mid;
            else ng=mid;
        }
        return num[x][ok].second;
    }
};

*/