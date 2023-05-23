/*

vector<long long> MP(string s){
  long long n=s.size();
  vector<long long>a(n);
  a[0]=-1;
  int j=-1;
  for(int i=0;i<n;i++){
    while(j>=0 && s[i]!=s[j]) j=a[j];
    j++; 
    a[i+1]=j;
  }
  return a;
}

*/