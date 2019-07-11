#include<stdio.h>
#include<algorithm>
using namespace std;
const int MaxN = 100005;
int dis[MaxN],a[MaxN];
int main() {
  int N,sum=0;
  scanf("%d",&N);
  
  for(int i=1;i<=N;i++) {
    scanf("%d",&a[i]);
    sum += a[i];
    dis[i] = sum;
  }
  int m;
  scanf("%d",&m);
  for(int i=0;i<m;i++) {
    int le,ri;
    scanf("%d %d",&le,&ri);
    if(le > ri) swap(le,ri);
    int tmp = dis[ri-1] - dis[le-1];
    printf("%d\n",min(tmp,sum-tmp));
  }


  return 0;
}