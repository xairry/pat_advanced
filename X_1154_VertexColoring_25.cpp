 #include<stdio.h>
 #include<vector>
 #include<set>
 using namespace std;
 struct Node{
 	int t1,t2;
 };
 
 int main() {
 	int v,e;
 	scanf("%d %d",&v,&e);
 	vector<Node> vc(e);
 	for(int i=0;i<e;i++) {
 		scanf("%d %d",&vc[i].t1,&vc[i].t2);
	}
 	int k;
	scanf("%d",&k);
 	while(k--) {
 		int a[10009] = {0};
 		bool flag= true;
 		set<int> se;
		for(int i=0;i<v;i++) {
			scanf("%d",&a[i]);
			se.insert(a[i]);
		}
		for(int i=0;i<e;i++) {
			if(a[vc[i].t1]==a[vc[i].t2]) {
				flag = false;
				break;
			}		
		}	
		if(flag)printf("%d-coloring\n",se.size());
		else printf("No\n");
	}
 	return 0;
 }
