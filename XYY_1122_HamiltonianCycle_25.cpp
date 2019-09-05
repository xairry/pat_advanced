#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
const int maxn = 220;
int G[maxn][maxn];
bool vis[maxn] = {false};
int main() {
  int n,m,cnt,k;
  scanf("%d %d",&n,&m);
  fill(G[0],G[0]+maxn*maxn,0);
  for(int i=0;i<m;i++) {
    int t1,t2;
    scanf("%d%d",&t1,&t2);
    G[t1][t2] = G[t2][t1] = 1;
  }
  scanf("%d",&cnt);
  while(cnt--) {
    scanf("%d",&k);
    vector<int> v(k);
    set<int> s;
    int flag1 = 1,flag2 = 1;
    for(int i=0;i<k;i++) {
      scanf("%d",&v[i]);
      s.insert(v[i]);
    }
    if(s.size() != n || k-1 != n || v[0]!= v[k-1]) flag1= 0;
    for(int i = 0;i<k-1;i++) {
      if(G[v[i]][v[i+1]] == 0) flag2 = 0;
      
    }
    printf("%s",flag1 && flag2 ? "YES\n":"NO\n");
  }
  return 0;
}