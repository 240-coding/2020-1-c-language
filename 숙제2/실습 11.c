#include <stdio.h>
int main(){
	int month, day;
	int sum; // 일수 총합
	int i; // for문 제어 변수

	printf("** 요일을 계산해 드립니다 **\n\n");

	printf("날짜 입력 (월, 일) : ");
	scanf("%d, %d", &month, &day);

	while (1){ // 무한 루프
		sum = 0; // sum 값 초기화
		for (i = 1; i < month; i++){ // 입력 받은 달 바로 전 달까지 일수 총합 계산
			if (i == 2) // 2월인 경우
				sum += 29;
			else if (i == 4 || i == 6 || i == 9 || i == 11) // 한 달이 30일인 경우
				sum += 30;
			else // 한 달이 31일인 경우		
				sum += 31;		
		}
		
		sum = sum + day; // 입력 받은 달 바로 전 달까지 일수의 총합에 이번 달 일수를 더함

		switch ( sum % 7 ){ // 요일 계산 및 출력
		case (6) :
			printf("%d월 %d일은 월요일 입니다.\n\n", month, day);
			break;		
		case (0) :
			printf("%d월 %d일은 화요일 입니다.\n\n", month, day);
			break;
		case (1) :
			printf("%d월 %d일은 수요일 입니다.\n\n", month, day);
			break;
		case (2) :
			printf("%d월 %d일은 목요일 입니다.\n\n", month, day);
			break;
		case (3) :
			printf("%d월 %d일은 금요일 입니다.\n\n", month, day);
			break;
		case (4) :
			printf("%d월 %d일은 토요일 입니다.\n\n", month, day);
			break;
		case (5) :
			printf("%d월 %d일은 일요일 입니다.\n\n", month, day);
			break;
		}

		printf("날짜 입력 (월, 일) : ");
		scanf("%d, %d", &month, &day);

		if (month == 0 && day == 0){ // 입력받은 값이 각각 0, 0이면 루프 탈출
			printf("안녕!\n\n");
			break;
		}
	}


	return 0;
}