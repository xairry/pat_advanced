#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
const int maxn=210,inf=1e9;
int n,k,maxH=-1,ans_avgH=inf,cnt=0;
int g[maxn][maxn],d[maxn], ha[maxn];
bool vis[maxn] = {false};
map<int,string> itc;
map<string,int> cti;
vector<int> pre[maxn];
vector<int> tmpPath,path;
void Dijks(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	for(int i=0;i<n;i++) {
		int u=-1,min=inf;
		for(int j=0;j<n;j++) {
			if(vis[j]==false && d[j]<min) {
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0;v<n;v++) {
			if(vis[v]==false && g[u][v]!=inf) {
				if(d[u] + g[u][v] < d[v]){
					d[v] = d[u] +g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u] + g[u][v] == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v == 0) {
		//printf("haha");
		tmpPath.push_back(v);
		cnt++;
		int sumH=0;double avgH=0.0;
		for(int i=tmpPath.size()-2;i>=0;i--) {
			int id=tmpPath[i];
			sumH += ha[id];
			
		}
		avgH = 1.0*sumH/(tmpPath.size()-1);
		if(sumH > maxH){
			maxH = sumH;
			ans_avgH = avgH;
			path = tmpPath;
		
		}else if(sumH == maxH && avgH>ans_avgH){
			
				ans_avgH = avgH;
				path = tmpPath;
			
			
		}
		tmpPath.pop_back();
		return;
		
		
	}
	tmpPath.push_back(v);
	for(int i=0;i<pre[v].size();i++) {
		DFS(pre[v][i]);
	}
	tmpPath.pop_back();

	
}

int main () {
	string start,city,city1,city2;
	int cost,happy;
	cin>>n>>k>>start;
	itc[0] = start;
	cti[start] = 0;
	for(int i=1;i<=n-1;i++) {
		cin>>city>>happy;
		itc[i] = city;
		cti[city] = i;
		ha[i] = happy;
	}
	fill(g[0],g[0]+maxn*maxn,inf);
	for(int i=0;i<k;i++)  {
		cin>>city1>>city2>>cost;
		g[cti[city1]][cti[city2]]=cost;
		g[cti[city2]][cti[city1]]=cost;
	}
	Dijks(0);
	
	DFS(cti["ROM"]);
	
	printf("%d %d %d %d\n",cnt,d[cti["ROM"]],maxH,ans_avgH);
		for(int i=path.size()-1;i>=0;i--) {
		cout<<itc[path[i]];
		if(i>0) cout<< "->";
	}
	
	
	return 0;
}
