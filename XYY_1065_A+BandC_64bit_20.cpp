#include<stdio.h>

using namespace std;

int main() {
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++) {
    long long  a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    long long res = a+b;
    bool flag;
    if(a>0 &&b>0 && res<0) flag=true;
    else if(a<0&&b<0&&res>=0) flag = false;
    else if(res>c)flag = true;
    else flag = false;
    if (flag == true){
      printf("Case #%d: true\n",i);
    }else{
      printf("Case #%d: false\n",i);
    }
  }

  return 0;
}