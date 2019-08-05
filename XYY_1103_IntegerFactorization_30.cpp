#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int n,k,p,maxFacsum = -1;
vector<int> fac,ans,temp;

int power(int x) {
    int ans = 1;
    for(int i=0;i<p;i++) {
        ans*=x;
    }
    return ans;
}

void init() {
    int i=0,temp = 0;
    while(temp <= n) {
        fac.push_back(temp);
        temp = power(++i);
    }
}

void dfs(int index,int nowk, int sum,int facsum) {
    if(sum == n && nowk == k) {
        if(facsum > maxFacsum){
            ans = temp;
            maxFacsum = facsum;
        }
        return;
    }
    if(sum >n || nowk >k)return;
    if(index -1 >=0) {
        temp.push_back(index);
        dfs(index,nowk+1,sum+fac[index],facsum+index);
        temp.pop_back();
        dfs(index-1,nowk,sum,facsum);
    }
}

int main() {
    scanf("%d%d%d",&n,&k,&p);
    init();
    dfs(fac.size()-1,0,0,0);
    if(maxFacsum == -1)printf("Impossible\n");
    else{
        printf("%d = %d^%d",n,ans[0],p);
        for(int i=1;i<ans.size();i++) {
            printf(" + %d^%d",ans[i],p);
        }
    }
    return 0;
}