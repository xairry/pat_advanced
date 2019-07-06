 #include<iostream>
#include <stdio.h>
#include <cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cctype>
#include<queue>
using namespace std;
//const int MAXV = 1000; //最大顶点数 
//const int INF = 0Xffffffff;



int main() {
	char nums[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	//printf("%s",nums[1]);
	int cnt=0;
	
	string N;
	cin>>N;
	for(int i=0;i<N.length();i++) {
		cnt+=N[i]-'0';
	}
	string ans;
	do{
		ans+=(cnt%10+'0');
		cnt/=10;
	}while(cnt!=0);
	cout<<nums[ans[ans.length()-1]-'0'];
	for(int i=ans.length()-2;i>=0;i--)	{
		
		cout<<" "<<nums[ans[i]-'0'];
		
	}
	
	return 0;
}
	



