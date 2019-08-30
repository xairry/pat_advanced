#include<cstdio>
#include<algorithm>


using namespace std;
const int N = 111;
int ori[N],tempOri[N],changed[N];
int n;
bool issame(int a[],int b[]) {
	for(int i=1;i<=n;i++) {
		if(a[i]!=b[i]) return false;
	}
	return true;
}

bool showarray(int a[]) {
	for(int i=1;i<=n;i++) {
		printf("%d",a[i]);
		if(i<n)printf(" ");
	}
	printf("\n");
}

bool insertsort() {
	bool flag = false;
	for(int i=2;i<=n;i++) {
		if(i!=2 && issame(tempOri,changed)) {
			flag = true;
		}
		sort(tempOri,tempOri+i+1);
		if(flag == true) {
			return true;
		}
	}
	return false;
}
void downjust(int low,int high) {
	int i = low,j = i*2;
	while(j<=high) {
		if(j+1 <= high && tempOri[j+1] > tempOri[j]) {
			j = j+1;
		}
		if(tempOri[j] > tempOri[i]) {
			swap(tempOri[j],tempOri[i]);
			i = j;
			j = i*2;
		}else{
			break;
		}
	}
}

void heapsort() {
	bool flag = false;
	for(int i=n/2;i>=1;i--) {
		downjust(i,n);
	}
	for(int i=n;i>1;i--) {
		if(i != n && issame(tempOri,changed)) {
			flag = true;
		}
		swap(tempOri[i],tempOri[1]);
		downjust(1,i-1);
		if(flag == true) {
			showarray(tempOri);
			return;
		}
	}
}

int main() {
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) {
		scanf("%d",&ori[i]);
		tempOri[i] = ori[i];
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&changed[i]);
	}
    if(insertsort()) {
        printf("Insertion Sort\n");
        showarray(tempOri);
    } else {
        printf("Heap Sort\n");
        for(int i=1;i<=n;i++) {
            tempOri[i] = ori[i];
        }
        heapsort();
    }
	return 0;
}