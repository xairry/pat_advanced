#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int n;
vector<int> arr(0);
int main() {
  scanf("%d",&n);
  arr.resize(n);
  for(int i=0;i<n;i++) {
    scanf("%d",&arr[i]);
  }
  sort(arr.begin(),arr.end());
  printf("%d ",n&1);
  int s1 = 0,s2 = 0;
  for(int i=0;i<n;i++) {
    if(i<n/2) {
      s2+=arr[i];
    }
    
    if(i>n/2) {
      s1+=arr[i];
    }
    
  }
  if(arr[n/2] > 0) {
      s1+=arr[n/2];
    }else{
      s2+=arr[n/2];
    }
  printf("%d",abs(s1-s2));
  return 0;
}