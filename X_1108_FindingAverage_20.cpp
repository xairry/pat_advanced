#include <ctype.h>
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main() {
	int n=0,cnt=0;
	double tmp,sum=0.0;
	char a[50],b[50];
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &tmp);
        sprintf(b, "%.2lf",tmp);
		
		bool flag=false;
		for(int j=0;j<strlen(a);j++) {
			if(a[j] != b[j]){
				flag = true;
			}
		}
		if(flag || tmp< -1000 || tmp>1000){
			printf("ERROR: %s is not a legal number\n",a);
		}else{
			sum+=tmp;
			cnt++;
		}
	}if(cnt==0) {
		printf("The average of 0 numbers is Undefined\n");
	}else if(cnt==1){
		printf("The average of %d number is %.2f\n",cnt,sum/cnt);	
	}else{
		printf("The average of %d numbers is %.2f\n",cnt,sum/cnt);	
	}
	
}
