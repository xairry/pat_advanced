#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1020,inf=1e9;
int n,m,k,ds;
int g[maxn][maxn],d[maxn];
bool vis[maxn]={false};


void Dijk(int s) {
	memset(vis,false,sizeof(vis));
	fill(d,d+maxn,inf);
	d[s] = 0;
	for(int i=0;i<n+m;i++) {
		int u=-1,min=inf;
		for(int j=1;j<=n+m;j++) {
			if(vis[j]==false && d[j]<min) {
				u = j;
				min = d[j];
			}
		}
		if(u==-1) return ;
		vis[u]=true;
		for(int v=1;v<=n+m;v++) {
			if( vis[v]==false && g[u][v]!=inf){
				if(d[u]+g[u][v] < d[v]){
					d[v] = d[u]+g[u][v];
				}
			}
		}
	}
}

int transID(char a[]) {
	int i=0,len = strlen(a), ID=0;
	while(i<len) {
		if(a[i]!='G') {
			ID = ID*10+(a[i]-'0');
		}
		i++;
	}
	if(a[0] == 'G')return n+ID;
	else return ID;
}


int main() {
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	fill(g[0],g[0]+maxn*maxn,inf);
	char p1[5],p2[5];
	int u,v,tp;
	for(int i=0;i<k;i++) {
		scanf("%s %s %d",p1,p2,&tp);
		u = transID(p1);
		v = transID(p2);
		g[u][v]=g[v][u]=tp;
	//	printf("%d_%d\n",u,v);
	}
	double ansDis=-1,ansAvg=inf;
	int ansID=-1;
	for(int i=n+1;i<=n+m;i++) {
		double minDis = inf,avg=0;
		Dijk(i);
		for(int j=1;j <= n;j++) {
			if(d[j] > ds){
				minDis=-1;
				break;
			}
			if(d[j] <minDis) minDis=d[j];
			avg += 1.0*d[j]/n;
		}
		if(minDis ==-1) continue;
		if(minDis > ansDis) {
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}
	}
	if(ansID == -1)printf("No Solution\n");
	else {
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
	return 0;
	
}
