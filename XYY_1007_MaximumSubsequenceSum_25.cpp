#include<cstdio>

using namespace std;

const int manx = 1e4+10;
int a[maxn],dp[amxn];
int s[maxn] = {0};
int main() {
	int n;
	scanf("%d".&n);
	bool flag = false;
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i];
		if(a[i]>=0)) flag = true;
	}
	if(flag == false) {
		printf("0 %d %d",a[0],a[n-1]);
		return 0;
	}
	dp[0] = a[0];
	for(int i=1;i<n;i++) {
		if(dp[i-1]+a[i] > a[i]) {
			dp[i] = dp[i-1]+a[i];
			s[i] = s[i-1];
		}
	}



	return 0;
}