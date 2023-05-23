/*

template<typename X>
struct PartialPersitentArrey{
  vector<vector<pair<int,X>>>b;
  int last=0;
  PartialPersitentArrey(vector<X> a){
    b.resize(a.size());
    for(int i=0;i<a.size();i++){
      b[i].push_back(make_pair(-1,a[i]));
    }
  }
  void set(int i,X val){
    b.push_back(make_pair(last++,val));
  }
  void get(int i,int time){
    int ok=0, ng=b[i].size();
    while(ng-ok>1){
      int mid = (ok+ng)/2;
      if(b[i][mid].first<=time) ok=mid;
      else ng=mid;
    }
    return b[i][ok].second;
  }
};

*/