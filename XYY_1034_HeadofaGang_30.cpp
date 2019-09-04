#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
const int maxn = 2020;

bool vis[maxn];
map<string,int> string2int;
map<int,string> int2string;
map<string,int> Gang;
int G[maxn][maxn] = {0},weight[maxn] = {0};

int N,K,numperson = 0;

void dfs(int now,int &head,int &nmember,int &totalvalue) {
    nmember++;
    vis[now] = true;
    if(weight[now] >weight[head]) {
        head = now;
    }
    for(int i=0;i<numperson;i++) {
        if(G[now][i] >0) {
            totalvalue += G[now][i];
            G[now][i] = G[i][now] = 0;
            if(vis[i] == false) {
                dfs(i,head,nmember,totalvalue);
            }
        }
    }
}
void dfstrave() {
    for(int i=0;i<numperson;i++) {
        if(vis[i]==false) {
            int head = i,nmember=0,totalvalue=0;
            dfs(i,head,nmember,totalvalue);
            if(nmember > 2 && totalvalue > K) {
                Gang[int2string[head]] = nmember;
            }
        }
    }
}

int change(string str) {
    if(string2int.find(str)!=string2int.end()) {
        return string2int[str];
    }else {
        string2int[str] = numperson;
        int2string[numperson] = str;
        return numperson++;
    }
}
int main() {
   
  return 0;
}