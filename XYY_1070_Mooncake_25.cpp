#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
const int maxn = 1010;
struct Mooncake{
  double store;
  double avg;
  double price;
}mooncake[maxn];

bool cmp(const Mooncake &a,const Mooncake &b){
  return a.avg > b.avg;
}
int main() {
  int n;
  double d;
  scanf("%d %lf",&n,&d);
  for(int i=0;i<n;i++) {
    scanf("%lf",&mooncake[i].store);
  }
  for(int i=0;i<n;i++) {
    scanf("%lf",&mooncake[i].price);
    mooncake[i].avg = mooncake[i].price/mooncake[i].store;
  }
  sort(mooncake,mooncake+n,cmp);
  double ans = 0,sell = 0;
  for(int i=0;i<n;i++) {
    if(mooncake[i].store<=d) {
      d-=mooncake[i].store;
      ans+=mooncake[i].price;
    }else{
      ans+=mooncake[i].avg*d;
      break;
    }
  }
  printf("%.2f\n",ans);
  return 0;
}