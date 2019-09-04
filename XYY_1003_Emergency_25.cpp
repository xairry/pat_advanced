#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 550;
const int INF = 1e9;
int G[maxn][maxn];
int wei[maxn],num[maxn];
int d[maxn],weight[maxn];
bool vis[maxn] = {false};
int N,M,C1,C2;

void dji(int s) {
  fill(d,d+maxn,INF);
  memset(num,0,sizeof(num));
  memset(wei,0,sizeof(wei));
  d[s] = 0;
  wei[s] = weight[s];
  num[s] = 1;
  
  for(int i=0;i<N;i++) {
    int u = -1,MIN = INF;
    for(int j=0;j<N;j++) {
      if(vis[j] == false && d[j] < MIN) {
        u = j;
        MIN = d[j];
      }
    }
    if(u == -1)return ;
    vis[u] = true;
    for(int v=0;v<N;v++) {
      if(G[u][v] != INF && vis[v] == false) {
        if(d[u]+G[u][v] < d[v]) {
          d[v] = d[u] + G[u][v];
          wei[v] = wei[u] + weight[v];
          num[v] = num[u];
        }else if(d[u] + G[u][v] == d[v]) {
          if(wei[v] < wei[u]+weight[v]) {
            wei[v] = wei[u] + weight[v];
          }
          num[v] += num[u];
        }
        
      }
    }
  }


}

int main() {
  
  scanf("%d %d %d %d",&N,&M,&C1,&C2);
  for(int i=0;i<N;i++) {
    scanf("%d",&weight[i]);
  }
  int a,b,c;
  fill(G[0],G[0]+maxn*maxn,INF);
  for(int i=0;i<M;i++) {
    scanf("%d %d %d",&a,&b,&c);
    G[a][b] = c;
    G[b][a] = c;
  }
  dji(C1);
  printf("%d %d",num[C2],wei[C2]);


	return 0;
}