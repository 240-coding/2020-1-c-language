// 학생 점수 출력하기
#include <stdio.h>
#include <string.h>
void main(){
	char s[7][10] = {"최지윤", "지예원", "민주현", "원샛별", "박지홍", "진윤정", "진선미"}; // 학생들의 이름
	char score[7][10] = {"90", "85", "90", "75", "95", "100", "80"}; // 각 학생들의 점수
	char sname[10];
	int i;
	printf("학생 이름을 입력하시오: ");
	gets(sname);

	for (i = 0; i < 7; i++){
		if (strcmp(sname, s[i]) == 0) // 입력받은 이름이 배열 안의 이름과 일치할 경우
			printf("%s 학생의 점수 = %s\n", sname, score[i]); // 그 학생의 점수 출력
	}

}