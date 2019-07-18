#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#include<vector>
const int maxn = 1e4+10;

using namespace std;
int arr[maxn];
int getFri(int a) {
  int ans = 0;
  while(a>0) {
    ans+=a%10;
    a/=10;
  }
  return ans;
}
int main() {
 int n;
 scanf("%d",&n);
 memset(arr,0,sizeof(arr));
 for(int i=0;i<n;i++) {
   int tmp;
   scanf("%d",&tmp);
   arr[getFri(tmp)]++;
 }
  int cnt=0;
  vector<int> res;
  for(int i=0;i<maxn;i++) {
    if(arr[i]>0) {
      cnt++;
      res.push_back(i);
    }
  }
  sort(res.begin(),res.end());
printf("%d\n%d",cnt,res[0]);

for(int i=1;i<res.size();i++) {
  printf(" %d",res[i]);
}

  return 0;
}