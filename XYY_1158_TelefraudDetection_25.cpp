#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int call[1111][1111] = {0};
int in[1111]={0},out[1111]={0};
vector<int> tp,tp1;
vector<vector<int> > ans;
bool vis[1111] = {0};

void dfs(int s) {
  vis[s] = 1;
  tp1.push_back(s);
  for(int &r:tp) {
    if(!vis[r] && call[s][r]&&call[r][s]) dfs(r);
  }
}

int main() {
  int k,n,m;
  scanf("%d %d %d",&k,&n,&m);
  for(int i=0;i<m;++i) {
    int x,y,d;
    cin>>x>>y>>d;
    call[x][y]+=d;
  }
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=n;j++) {
      if(call[i][j] !=0 && call[i][j] <=5) {
        ++out[i];
        if(call[j][i]!=0)++in[i];
      }
    }
  }
for(int i=1;i<=n;++i) {
  if(out[i] > k && out[i] >= in[i]*5){
    tp.push_back(i);
  }
}
sort(tp.begin(),tp.end());
for(int &r:tp) {
  if(!vis[r]) {
    tp1.clear();
    dfs(r);
    sort(tp1.begin(),tp1.end());
    if(!tp1.empty()) ans.push_back(tp1);
  }
}
if(ans.empty()) {
  cout<<"Node"<<endl;
  return 0;
}
sort(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++) {
  for(int j=0;j<ans[i].size();j++) {
    if(j!=0) cout<<" ";
    cout<<ans[i][j];
  }
  cout<<endl;
}
  return 0;
}