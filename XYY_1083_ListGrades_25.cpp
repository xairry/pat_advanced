#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


int N;
int grade1,grade2;

struct Node{
  char name[12];
  char id[12];
  int grade;
};

inline bool cmp(const Node &a,const Node &b) {
  return a.grade>b.grade;
}

int main() {
  vector<Node> ans;
  vector<Node> arr;
  scanf("%d",&N);
  arr.resize(N);
  for(int i = 0;i<N;i++) {
    scanf("%s%s%d",arr[i].name,arr[i].id,&arr[i].grade);
  }
  scanf("%d%d",&grade1,&grade2);
  if(grade1 > grade2)swap(grade1,grade2);
  for(int i=0;i<N;i++) {
    if(arr[i].grade >=grade1 && arr[i].grade <=grade2)
    ans.push_back(arr[i]);
  }
  sort(ans.begin(),ans.end(),cmp);
  int ss = ans.size();
  if(ss == 0){
    printf("NONE\n");
    return 0;
  }
  for(int i=0;i<ss;i++) {
    printf("%s %s\n",ans[i].name,ans[i].id);
  }
  return 0;
}