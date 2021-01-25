#define N 7 // 학급 학생 수
#include <stdio.h>
#include <string.h>

// 학급 성적 정보
char s[N][10] = {"은지영", "조남희", "이예진", "신예빈", "김정선", "박민정", "최다영"};
int midterm[N] = {90, 85, 80, 75, 95, 100, 80}; // 중간시험
int final[N] = {80, 90, 95, 100, 80, 75, 90}; // 기말시험

// 학급 중간/기말시험 평균 계산하여 출력하는 함수
void computeClassAvg(){
	double midAvg = 0, finAvg = 0;
	int i;
	for (i = 0; i < N; i++){ // 중간고사, 기말고사 점수를 각각 더함
		midAvg += midterm[i];
		finAvg += final[i];
	}

	// 점수 더한 값을 학생수로 나눠서 평균 구하기
	midAvg /= N; 
	finAvg /= N;

	// 평균 점수 출력
	printf("학급 중간시험 평균 = %.2f\n", midAvg);
	printf("학급 기말시험 평균 = %.2f\n\n", finAvg);
}

// 주어진 학생의 중간/기말시험 점수와 평균 출력하는 함수
void computeStudentAvg(char sname[]){
	int i;
	double average; // 평균 점수

	for (i = 0; i < N; i++){
		if (strcmp(sname, s[i]) == 0){
			average = (midterm[i] + final[i]) / 2.0; // 평균 점수 계산
			printf("중간 = %d, 기말 = %d, 평균 = %.2f\n\n", midterm[i], final[i], average); // 각 점수 출력
			break;
		}
	}
}

// 주어진 학생이 학급에 있는가 확인하여
// 그 결과를 호출한 곳으로 반환해주는 함수
int findStudent(char sname[]){
	int i, flag = 0;
	
	for (i = 0; i < N; i++){
		if (strcmp(sname, s[i]) == 0){ // 주어진 학생이 학급에 있는 경우
			flag = 1;
			break;
		}
	}

	return flag;
}

main(){
	char sname[10]; // 입력 학생 이름 저장하는 곳

	computeClassAvg(); // 중간, 기말시험 평균 계산하여 출력

	while (1){ // 무한루프
		printf("학생 이름을 입력하시오: "); // 학생 이름 입력받음
		gets(sname);

		if (findStudent(sname)) // 학생이 학급에 있을 경우
			computeStudentAvg(sname); // 점수 출력
		else if (findStudent(sname) == 0 && strcmp(sname, "끝") != 0) // 학급에 없고, 이름이 "끝"이 아닐 경우
			printf("%s 학생은 학급에 없습니다.\n\n", sname);

		if (strcmp(sname, "끝") == 0){ // 학생 이름이 "끝"일 경우 프로그램 종료
			printf("다음에 만나요!\n");
			break; 
		}
	}
}

	
