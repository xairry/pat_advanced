#include<stdio.h>

using namespace std;

int main() {
  int a1,b1,c1,a2,b2,c2;
  scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
  int ca = 0;
  int a3,b3,c3;
  c3 = (c1+c2)%29;
  ca = (c1+c2)/29;
  b3 = (b1+b2+ca)%17;
  ca = (b1+b2+ca)/17;
  a3 = (a1+a2+ca);
  printf("%d.%d.%d",a3,b3,c3);


  return 0;
}