#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int main() {
  int K;
  scanf("%d\n",&K);
  while(K--) {
    int N;
    scanf("%d",&N);
    int a[N];
    memset(a,0,sizeof(a));
    bool flag = false;
    for(int i=0;i<N;i++) {
      scanf("%d",&a[i]);
      for(int j=0;j<i;j++) {
        if(a[i] == a[j] || abs(a[i]-a[j])==abs(i-j)){
          flag = true;
          break;
        }
      }
    }
    cout<<(flag==true?"NO":"YES")<<endl;
  }


  return 0;
}