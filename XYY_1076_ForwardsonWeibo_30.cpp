#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1010;

struct Node {
  int id;
  int layer;
};

vector<Node> adj[maxn];
bool inq[maxn] = {false};

int BFS(int s,int L) {
  int numForward = 0;
  queue<Node> q;
  Node start;
  start.id = s;
  start.layer = 0;
  q.push(start);
  inq[s] = true;
  while(!q.empty()) {
    Node top = q.front();
    q.pop();
    int u = top.id;
    for(int i=0;i<adj[u].size();i++) {
      Node next = adj[u][i];

      next.layer = top.layer+1;
      if(inq[next.id] == false && next.layer<=L) {
        q.push(next);
        inq[next.id] = true;
        numForward++;
      }
    }

  }
  return numForward;
}

int main() {
  Node user;
  int n,L,numFollow,idFollow;
  scanf("%d%d",&n,&L);
  for(int i=1;i<=n;i++) {
    user.id = i;
    scanf("%d",&numFollow);
    for(int j=0;j<numFollow;j++) {
      scanf("%d",&idFollow);
      adj[idFollow].push_back(user);
    }
  }
  int numquery,s;
  scanf("%d",&numquery);
  for(int i=0;i<numquery;i++) {
    memset(inq,false,sizeof(inq));
    scanf("%d",&s);
    int numForward = BFS(s,L);
    printf("%d\n",numForward);
  }

  return 0;
}