#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int nearS = 1e9;
int main() {
  int n,S;
  scanf("%d %d",&n,&S);
  int arr[n+1];
  int sum[n+1];
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
    if(i==1) {
      sum[i] = arr[i];
    }else{
      sum[i] = sum[i-1]+arr[i];
    }
  }
  for(int i=1;i<=n;i++) {
    int j = upper_bound(i,n+1,sum[i-1]+S)-sum;
    if(sum[j-1]-sum[i-1] == S) {
      nearS = S;
      break;
    }else if(j<=n && sum[j]-sum[i-1]<nearS){
      nearS = sum[j] - sum[i-1];
    }
  }
  for(int i=1;i<=n;i++) {
    int j = upper_bound(i,n+1,sum[i-1]+nearS)-sum;
    if(sum[j-1]-sum[i-1] == nearS) {
      printf("%d-%d\n",i,j-1);
    }
  }
  



  return 0;
}