#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxc = 200;
const int maxn = 10010;

int hashTable[maxc];
int A[maxn],dp[maxn];
int main() 
{
  int n,m,x;
  scanf("%d%d",&n,&m);
  memset(hashTable,-1,sizeof(hashTable));
  for(int i=0;i<m;i++) {
    scanf("%d",&x);
    hashTable[x] = i;
  }
  int L,num = 0;
  scanf("%d",&L);
  for(int i=0;i<L;i++) {
    scanf("%d",&x);
    if(hashTable[x] >= 0 ) {
      A[num++] = hashTable[x];
    }
  }
  int ans = -1;
  for(int i=0;i<num;i++){
    dp[i] = 1;
    for(int j = 0;j<i;j++) {
      if(A[j] <= A[i] && dp[j] +1 > dp[i]) {
        dp[i] = dp[j] + 1;

      }
    }
    ans = max(dp[i],ans);

  }
 
  printf("%d\n",ans);
   return 0;
}