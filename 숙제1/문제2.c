#include <stdio.h>
int main(){
	int i, j, n;
	
	printf("이등변 삼각형의 높이 : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++){ // 높이
		for (j = 0; j < n-i-1; j++) // 공백 줄 출력
			printf(" ");
		for (j = 0; j < 2*(i+1)-1; j++) // 줄바꿈없이 별표 줄 이어 출력
			printf("*");
		printf("\n"); // 한 줄 출력 후 줄바꿈
	}

	return 0;
}