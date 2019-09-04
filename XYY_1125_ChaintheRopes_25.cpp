#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;

int N;
int main() {
  scanf("%d",&N);
  vector<int> arr(N,0);
  for(int i=0;i<N;i++) {
    scanf("%d",&arr[i]);
  }
  sort(arr.begin(),arr.end());
  int res = arr[0];
  for(int i=1;i<N;i++) {
    res = (res+arr[i])/2;
  }
  printf("%d",res);
  
  return 0;
}