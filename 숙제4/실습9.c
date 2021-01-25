// 학생 이름 정렬하기
#include <stdio.h>
#include <string.h>
void main(){
	char s[7][10] = {"한승미", "김주영", "원홍빈", "도지희", "이하선", "선지은", "조하정"};
	char temp[10];
	int i, j;

	for (i = 0; i < 6; i++){ // 사전순으로 한 단어씩 정렬하기 위해 6번 반복함
		for (j = 0; j < 6 - i; j++){ // 사전순으로 가장 마지막에 오는 단어를 6 - i번째로 보냄(swap)
			if (strcmp(s[j], s[j+1]) == 1){
				strcpy(temp, s[j]);
				strcpy(s[j], s[j+1]);
				strcpy(s[j+1], temp);
			}
		}
	}

	for (i = 0; i < 7; i++) // 정렬된 이름 모두 출력
		printf("%s\n", s[i]);
}