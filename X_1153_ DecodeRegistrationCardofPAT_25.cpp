#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct node {
	string t;
	int val;
};
inline bool cmp (const node &a,const node &b) {
	return a.val!=b.val?a.val>b.val:a.t<b.t;
}
int main() {
	int n,k,num;
	string s;
	cin>>n>>k;
	vector<node> ori(n);
	for(int i=0;i<n;++i) {
		cin>>ori[i].t>>ori[i].val;
	}
	printf("haha");
	for(int i=0;i<k;i++) {
		cin>>num>>s;
		printf("Case %d: %d %s\n",i+1,num,s.c_str());
		vector<node> ans;
		int cnt = 0,sum = 0;
		if (num == 1) {
			for(int j=0;j<n;j++) {
				if(ori[j].t[0] == s[0]) ans.push_back(ori[j]);
			}
		}else if ( num == 2) {
			for(int j=0;j<n;j++) {
				if(ori[j].t.substr(1,3) == s) {
					cnt++;
					sum+=ori[j].val;
				}
			}
			if(cnt!=0)printf("%d %d\n",cnt,sum);
		}else if (num == 3) {
			unordered_map<string,int> m;
			for(int j=0;j<n;j++) {
				if(ori[j].t.substr(4,6) == s) m[ori[j].t.substr(1,3)]++;
			}
			for(auto it:m)ans.push_back({it.first,it.second});
		}
		sort(ans.begin(),ans.end(),cmp);
		for(int j=0;j<ans.size();j++){
			printf("%s %d\n",ans[j].t.c_str(),ans[j].val);
		}
		if(((num==1||num==3) && ans.size()==0)||(num==2 &&cnt == 0))printf("NA\n");
	}
	
	
	return 0;
}
