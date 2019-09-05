#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int E,N;
vector<int> arr(0);
int main() {
  scanf("%d",&N);
  arr.resize(N);
  for(int i=0;i<N;i++) {
    scanf("%d",&arr[i]);
  }
  sort(arr.rbegin(),arr.rend());
  int t=0;
  while(arr[t] > t+1) {
    t++;
  }
  printf("%d",t);
  return 0;
}