/*
struct Edge{
  int to;
  long long w;
  Edge(int to,long long w):to(to),w(w){}
};

using Graph=vector<vector<Edge>>;

template<typename X> bool chmin(X &a,X b){
  if(a>b){
    a=b;
    return true;
  }
  else return false;
}

long long dijk(Graph &G,int s){
  long long N=G.size();
  vector<long long>dist(N,(1ll<<60));
  priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>que;
  dist[s]=0;
  que.push(make_pair(dist[s],s));
  while(!que.empty()){
    int v=que.top().second;
    long long d=que.top().first;
    que.pop();
    if(d>dist[v]) continue;
    for(auto e:G[v]){
      if(chmin(dist[e.to],dist[v]+e.w)){
        que.push(make_pair(dist[e.to],e.to));
      }
    }
  }
  return dist[N-1];
}

*/
