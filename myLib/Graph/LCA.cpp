struct Edge{
    long long to; 
};

using Graph = vector<vector<Edge>>;

struct LCA{
    vector<vector<int>>parent;
    vector<int>dist;
    LCA(const Graph &G,int root=0){
        init(G,root);
    }
    void init(const Graph &G,int root){
        int n = G.size();
        int logk = 1;
        while((1<<logk)<n) logk++;
        parent.assign(logk,vector<int>(n,-1));
        dist.assign(n,-1);
        dfs(G,root,-1,0);
        for(int k=0;k<logk-1;k++){
            for(int v=0;v<n;v++){
                if(parent[k][v]<0){
                    parent[k+1][v]=-1;
                }
                else{
                    parent[k+1][v]=parent[k][parent[k][v]];
                }
            }
        }
    }
    void dfs(const Graph &G,int v,int p,int d){
        parent[0][v]=p;
        dist[v]=d;
        for(auto e:G[v]) if(e.to!=p){
            dfs(G,e.to,v,d+1);
        }
    }

    int query(int u,int v){
        if(dist[u]<dist[v]) swap(u,v);
        int logk=parent.size();
        for(int k=0;k<logk;k++){
            if((dist[u]-dist[v])>>k&1){
                u = parent[k][u];
            }
        }
        if(u==v) return u;
        for(int k=logk-1;k>=0;k--){
            if(parent[k][u]!=parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};