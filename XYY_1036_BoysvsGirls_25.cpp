#include<stdio.h> 
#include<algorithm>
using namespace std;
typedef struct Stu{
	char name[16],gender,id[20];
	int grade;
	
}stu;

bool cmp(stu a,stu b) {
	return a.grade>b.grade; 
}
bool cmp1(stu a,stu b) {
	return a.grade<b.grade; 
}

int main() {
	
	int N;
	scanf("%d",&N);
	stu tmp,male[N],female[N];
	int count_ma=0,count_fe=0;
	for( int i=0; i<N; i++) {
		scanf("%s %c %s %d",tmp.name,&tmp.gender,tmp.id,&tmp.grade);
		male[i]=tmp;
		if(tmp.gender=='M'){
			male[count_ma++]=tmp;
			
		}else{
			female[count_fe++]=tmp;
			
		}
	}
//printf("%d--%d\n",count_ma,count_fe);
	sort(male,male+count_ma,cmp1);
	sort(female,female+count_fe,cmp);
	if( count_fe>0){
		printf("%s %s\n",female[0].name,female[0].id);
	}else{printf("Absent\n"); 
	}
	if(count_ma>0){
		printf("%s %s\n",male[0].name,male[0].id);
	}else{printf("Absent\n"); 
	}
	
	if(count_fe>0&&count_ma>0){
		printf("%d\n",female[0].grade-male[0].grade);
	} else{
		printf("NA");
	}
	

	return 0;
} 
