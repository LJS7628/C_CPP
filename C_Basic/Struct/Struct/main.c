#include <stdio.h>


//--구조체--
/*
 여러개의 맴버들을 모아서 하나의 새로운 자료형을 만드는 방식
*/
// 기본 구조체 정의하는 방법:
/*struct 구조체이름 {

    맴버;
};*/
// 별칭을 이용한 구조체 정의
/*
 별칭을 이용해서 정의를 할 때 구조체 이름, 별칭 모두 사용 가능하다.
*/
/*typedef struct ST {
  int kor, math, eng, sum;
  double avg;
  char grade;
  char name[20];
} Student;*/
// 익명 구조체 정의
// 익명 구조체를 사용하면 구조체 이름으로 선언 x, 별칭만 사용가능
typedef struct {
    int kor, math, eng, sum;
    double avg;
    char grade;
    char name[20];

}Student;



struct ST {
    int kor, math, eng, sum;
    double avg;
    char grade;
    char name[20];

};
void Sum(int*, int, int, int);
void Avg(double*, int);
void Grade(char*, double);
int main() {
    struct ST st[3];

    int i = 0;
    while (i < 3) {
        printf("학생 이름 입력: ");
        scanf("%s", &st[i].name);
        printf("%s의 국어, 수학, 영어 입력: ", st[i].name);
        scanf("%d %d %d", &st[i].kor, &st[i].math, &st[i].eng);

        Sum(&st[i].sum, st[i].kor, st[i].math, st[i].eng);
        Avg(&st[i].avg, st[i].sum);
        Grade(&st[i].grade, st[i].avg);
        i++;
    }
    printf("\n-----------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%s의 성적:\n", st[i].name);
        printf("총합: %d\n", st[i].sum);
        printf("평균: %.2f\n", st[i].avg);
        printf("등급: %c\n", st[i].grade);
        printf("\n-----------------------------\n");
    }

    return 0;
}

void Sum(int* sum, int a, int b, int c) {
    *sum = a + b + c;
}

void Avg(double* avg, int sum) {
    *avg = sum / 3.0;

}

void Grade(char* grade, double avg) {
    switch ((int)avg / 10) {
    case 10:
    case 9:
        *grade = 'A';
        break;
    case 8:
        *grade = 'B';
        break;
    case 7:
        *grade = 'C';
        break;
    case 6:
        *grade = 'D';
        break;
    default:
        *grade = 'F';
    }
}