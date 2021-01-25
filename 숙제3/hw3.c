// 윤년인지 혹은 특정일의 요일을 구해주는 프로그램
#include <stdio.h>

void PrintMenu(){ // 프로그램의 메뉴를 출력하는 함수
	printf("무엇을 하시겠습니까? 번호를 입력하세요.\n");
	printf("(1) 윤년인가 알아보기\n");
	printf("(2) 특정일의 요일 구하기\n");
	printf("(3) 그만하기\n\n");
	printf("번호 입력 : ");
}

int IsLeapYear(int year){ // 윤년인지 판단하는 함수
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) // 윤년인 경우
		return 1;
	else // 윤년이 아닐 경우
		return 0;
}

int GetNumDaysInYear(int year){ // 그 해 며칠이 있는지 계산하는 함수
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) // 윤년인 경우
		return 366;
	else // 윤년이 아닐 경우
		return 365;
}

int GetTotalNumDays(int year){ // 1년부터 입력받은 연도까지 총 날짜의 합계를 계산하는 함수
	int i;
	int sum = 0;

	for (i = 1; i <= year; i++){
		sum += GetNumDaysInYear(i);
	}

	return sum;
}

int GetDayRankInsideYear(int year, int month, int day){ // 입력받은 날짜가 그 해의 몇 번째 날인지 계산하는 함수
	int i;
	int daySum = 0;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){ // 입력 받은 달의 바로 전 달까지 일수 총합 계산 - 윤년인 경우
		for (i = 1; i < month; i++){
			if (i == 2) // 2월인 경우
				daySum += 29;
			else if (i == 4 || i == 6 || i == 9 || i == 11) // 한 달이 30일인 경우
				daySum += 30;
			else // 한 달이 31일인 경우
				daySum += 31; 
		}
		daySum += day; // 입력 받은 달의 일수를 더함
	}
	else { // 윤년이 아닌 경우
		for (i = 1; i < month; i++){
			if (i == 2)
				daySum += 28;
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				daySum += 30;
			else
				daySum += 31;
		}
		daySum += day;
	}
	
	return daySum;
}

void PrintDayofTheWeek(int days){ // 요일을 계산해 출력하는 함수
	switch ( days % 7 ){
	case (1) :
		printf("월요일입니다.\n\n");
		break;
	case (2) :
		printf("화요일입니다.\n\n");
		break;
	case (3) :
		printf("수요일입니다.\n\n");
		break;
	case (4) :
		printf("목요일입니다.\n\n");
		break;
	case (5) :
		printf("금요일입니다.\n\n");
		break;
	case (6) :
		printf("토요일입니다.\n\n");
		break;
	case (7) :
		printf("일요일입니다.\n");
		break;
	}
}

int main(){
	int num, year, month, day;
	int sum, daySum;
	while (1){
		PrintMenu();
		scanf("%d", &num); // 사용자로부터 숫자를 입력받음

		if (num == 1){ // 윤년인지 구하는 메뉴를 선택했을 경우
			printf("연도를 입력하세요 : ");
			scanf("%d", &year);
			if (IsLeapYear(year))
				printf("윤년입니다.\n\n");
			else
				printf("윤년이 아닙니다.\n\n");
		}
		else if (num == 2){ // 특정일의 요일을 구하는 메뉴를 선택했을 경우
			printf("년 월 일을 입력하세요: ");
			scanf("%d %d %d", &year, &month, &day);
			sum = GetTotalNumDays(year - 1); // 입력 받은 해 바로 전 해까지의 일수를 더함
			daySum = GetDayRankInsideYear(year, month, day); // 입력 받은 날짜가 그 해의 몇 번째 날인지 계산
			PrintDayofTheWeek(sum + daySum); // 바로 전 해까지 일수와 올해 일수를 합하여 요일을 계산 및 출력함
		}
		else if (num == 3){ // 프로그램을 종료하는 메뉴를 선택했을 경우
			printf("안녕!\n");
			break;
		}		
		else // 잘못된 번호를 입력했을 경우
			printf("다시 선택하세요.\n\n");
	
}


}