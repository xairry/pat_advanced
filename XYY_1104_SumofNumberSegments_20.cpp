#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


int main() {
  int n;
  scanf("%d",&n);
  
  double ans = 0,tp;
  for(int i=1;i<=n;i++) {
    scanf("%lf",&tp);
    ans+=tp*i*(n-i+1);

  }
  printf("%.2f",ans);
  return 0;
}