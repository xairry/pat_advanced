#include<iostream> 
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
const int MAX=1000000;
bool isPalindromic (int a[],int len){
	for(int i=0;i<=len/2;i++){
		if(a[i]!=a[len-1-i]){
			return false;
		}
	}
	return true;
}

int main() {
	int num,base;
	cin>>num>>base;
	int cnt=0,ans[40];
	do{
		ans[cnt++]=num%base;
		num/=base;
	
	}while(num!=0);
	if(isPalindromic(ans,cnt)){
		printf("Yes\n");
	} else{
		printf("No\n");
	}
	for(int i=cnt-1;i>=0;i--){
		if(i!=cnt-1){
			printf(" ");
		}printf("%d",ans[i]);
		
	}
	
	return 0;
} 
