#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=111;
int n;
int ori[N],tempOri[N],changed[N];
bool isSame(int a[],int b[]) {
	for(int i=1;i<=n;i++) {
		if(a[i]!=b[i])return false;
	}
	return true;
}

bool insertSort() {
	bool flag=false;
	for(int i=2;i<=n;i++) {
		if(i!=2 && isSame(tempOri,changed)) {
			flag=true;
		}
		sort(tempOri,tempOri+i+1);
		if(flag==true){
			return true;
		}
	}
	return false;
}

void downJust(int down,int high) {
	int i=down,j=2*i;
	while(j<=high){
		if(j+1<=high && tempOri[j+1]>tempOri[j]){
			j++;
		}
		if(tempOri[i] < tempOri[j]){
			swap(tempOri[i] , tempOri[j]);
			i=j;
		j=i*2;
		}
		
		else{
		break;
	}
	}
	
}
bool showArray(int A[]) {
	for(int i=1;i<=n;i++) {
		printf("%d",A[i]);
		if(i<n)printf(" ");
	}
	printf("\n");
}

void heapSort() {
	bool flag=false;
	for(int i=n/2;i>=1;i--) {
		downJust(1,n);
	}
	
	for(int i=n;i>1;i--){
		if(i!=n && isSame(tempOri,changed)){
			flag=true;
		}
		
		swap(tempOri[i],tempOri[1]);
		downJust(1,i-1);
		printf("%d",flag);
		if(flag==true) {
			showArray(tempOri);
			return;
		}
	}
}



int main () {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&ori[i]);
		tempOri[i]=ori[i];
		
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&changed[i]);
	}
	if(insertSort()) {
		printf("Insertion Sort\n");
		showArray(tempOri);
	}else{
		printf("Heap Sort\n");
		for(int i=1;i<=n;i++) {
			tempOri[i] = ori[i];
		}
		heapSort();
	}
	
	
	
	
	
	
	return 0;
}
