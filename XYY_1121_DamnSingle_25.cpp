#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6;
int N,M;
vector<int> couple(maxn,0);
int gue[maxn];

int main() {
  scanf("%d",&N);
  int tp1,tp2;
  couple.resize(N);
  memset(gue,0,sizeof(gue));
  for(int i=0;i<N;i++) {
    scanf("%d %d",&tp1,&tp2);
    
    couple[tp1] = tp2;
    couple[tp2] = tp1;
    
  }
  
  scanf("%d",&M);
  for(int i = 0;i<M;i++) {
    scanf("%d",&tp1);
    gue[tp1] = 1;
  }
  vector<int> ans;
  for(int i=0;i<1e6;i++){
    if((gue[i]==1 && couple[i] == 0) || (gue[i] == 1 &&gue[couple[i]] == 0))      {
      ans.push_back(i);
    }
  }
  printf()
  for(int i=0;i<ans.size();i++) {
    printf("%05d",ans[i]);
    if(i!=ans.size()-1)printf(" ");
  }

  return  0;
}