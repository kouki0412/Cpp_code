/*

vector<long long> linear_sieve(n){
  vector<long long>lp(n+1);
  vector<long long>pr;
  for(int i=2;i<=n;i++){
    if(lp[i]==0){
      lp[i]=i;
      pr.push_back(i);
    }
    for(int j=0;j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n;j++){
      lp[i*pr[j]]=pr[j];
    }
  }
  return lp;
}

*/
