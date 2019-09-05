#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> graph[1005];

int main() {
  int N,M,a,b;
  scanf("%d%d",&N,&M);
  vector<int> in (N+1,0);
  for(int i=0;i<M;i++) {
    scanf("%d%d",&a,&b);
    graph[a].push_back(b);
    ++in[b];
  }
  scanf("%d",&M);
  bool space = false;
  for(int q = 0;q<M;q++) {
    int A[N];
    
    vector<int> tp = in;
    for(int i=0;i<N;i++) {
      scanf("%d",&A[i]);

    }
  for(int i=0;i<N;i++) {
    if(tp[A[i]]!=0) {
      printf("%s%d",space?" ":"",q);
      space = true;
      break;
    }else{
      for(int j:graph[A[i]]) {
        tp[j]--;
      }
    }
  }
  }
  return 0;
}