#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main() {
  int Nc,Np;
  vector<int> c1,c2,p1,p2;
  scanf("%d",&Nc);
  for(int i=0;i<Nc;i++) {
    int tmp;
    scanf("%d",&tmp);
    if(tmp >=0) {
      c1.push_back(tmp);
    }else{
      c2.push_back(tmp);
    }
  }
  scanf("%d",&Np);
  for(int i=0;i<Np;i++) {
    int tmp;
    scanf("%d",&tmp);
    if(tmp >=0) {
      p1.push_back(tmp);
    }else{
      p2.push_back(tmp);
    }
  }
  sort(c1.rbegin(),c1.rend());
  sort(c2.begin(),c2.end());
  sort(p1.rbegin(),p1.rend());
  sort(p2.begin(),p2.end());
  
  int n1=c1.size(),n2=c2.size(),n3=p1.size(),n4=p2.size();
  int ans = 0;
  for(int i=0;i<min(n1,n3);i++) {
    ans+=(c1[i]*p1[i]);
  }
  for(int i=0;i<min(n2,n4);i++) {
    ans+=(c2[i]*p2[i]);
  }
printf("%d\n",ans);



  return 0;
}