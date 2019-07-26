#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
  int n;
  long long p;
  
  scanf("%d %lld",&n,&p);
  vector<int> ar;
  int tp;
  for(int i=0;i<n;i++) {
    scanf("%d",&tp);
    ar.push_back(tp);
  }
  sort(ar.begin(),ar.end());
  int ans=1;
  for(int i=0;i<n;i++) {
    int j = upper_bound(ar.begin()+i+1,ar.end(),(long long)ar[i]*p)-ar.begin();
    ans = max(ans,j-i);
  }
printf("%d",ans);
  return 0;
}