#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
char tmp[11];
bool isPrime(int x){
	if(x<2){
		return false;
	}
	for(int i=2;i*i<=x;i++){
		if(x%i == 0){
			return false;
		}
		
			
	}
	return true;
}  
int main(){
	int L,K;
	string N;
	cin>>L>>K;
	cin>>N;
	int n=0;
	bool flag=false;
	
	int i=0;
	for(i;i+K<=L;++i){
		for(int j=i;j<i+K;++j){
			tmp[j-i]=N[j];
		}
		tmp[K]='\0';
		sscanf(tmp,"%d",&n);
		if(isPrime(n)){
			flag=true;
			printf("%s\n",tmp);
			break;
		}
	}
	if(!flag){
		printf("404\n");
	}
	return 0;
}
