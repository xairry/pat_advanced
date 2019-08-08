#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;
int m,n,slice,t;
struct Node {
  int x,y,z;

}node;
int X[] = {0,0,0,0,1,-1};
int Y[] = {0,0,1,-1,0,0};
int Z[] = {1,-1,0,0,0,0};
int pixel[1290][130][61];
bool inq[1290][130][61] = {false};

bool judge(int x,int y,int z) {
  if(x >= n || x<0 ||y>=m ||y<0 || z>=slice || z<0)return false;
  if(pixel[x][y][z]==0 || inq[x][y][z]==true) return false;
  return true;
}

int bfs(int x,int y,int z) {
  int tot = 0;
  queue<Node> q;
  node.x = x,node.y=y,node.z=z;
  q.push(node);
  inq[x][y][z] = true;
  while(!q.empty()) {
    Node top = q.front();
    q.pop();
    tot++;
    for(int i=0;i<6;i++) {
      int nx = top.x+X[i];
      int ny = top.y+Y[i];
      int nz = top.z+Z[i];
      if(judge(nx,ny,nz)) {
        node.x = nx,node.y = ny,node.z = nz;
        q.push(node);
        inq[nx][ny][nz] = true;
      }
    }
  }
  if(tot>=t)return tot;
  else return 0;
}
int main() {
  scanf("%d%d%d%d",&n,&m,&slice,&t);
  for(int z=0;z<slice;z++) {
    for(int x = 0;x<n;x++) {
      for(int y=0;y<m;y++) {
        scanf("%d",&pixel[x][y][z]);
      }
    }
  }
  int ans = 0;
  for(int z=0;z<slice;z++) {
    for(int x = 0;x<n;x++) {
      for(int y=0;y<m;y++) {
        if(pixel[x][y][z]==1 && inq[x][y][z]==false) {
          ans+=bfs(x,y,z);
        }
      }
    }
  }  
  printf("%d\n",ans);

  return 0;
}