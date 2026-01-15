#include <stdio.h>

//--조건문--
/*
조건문을 비교하고 해당 조건식이 참이면 종속문장을 실행, 거짓이면 탈출
조건문 뒤에는 ;(세미콜론)을 붙여서는 안된다.
{(중괄호)를 생략할 때는 종속문장이 단 한 줄일 때 생략할 수 있다.
 if(조건문)
 {
   종속문장;
 }

 switch ~ case:
 switch(비교할 값)
 {
    case 해당 값:
     종속문자;
     break;
 }
 switch~case문에서는 break는 해당 구문을 탈출하는 용도로 사용이 되는데,
 프로그래머가 의도적으로 break를 작성하지 않을 수도 있다.
 switch~case문 에서 만족하지 않는 경우를 작성해 줄 때는 default를 사용한다.
 switch~case문 에서 비교할 값 공간에는 정수, 정수로 변화할 수 있는 값, 정수가 저장된 공간(변수) 만
 들어올 수 있다.
*/

int main() {

    /*    int num = 15;

        if (num > 10) {
            printf("num은 10보다 큽니다.\n");
        }
        else if (num > 5) {
            printf("num이 5보다 큽니다.");
        }
        else
            printf("num은 5보다 작거나 같습니다.\n");*/

            /*   int num1,num2;

               printf("입력: ");
               scanf("%d", &num1);
               if(num1>=14)
               printf("출력: 14보다 같거나 큰 수\n");

               printf("입력: ");
               scanf("%d", &num2);
               if (num2 % 3) {
                   printf("출력: 거짓\n");
               }
               else {
                   printf("출력: 참\n");
               }*/
    int kor, math, eng;
    double avg;



    printf("국어 점수 입력 :");
    scanf("%d", &kor);

    printf("수학 점수 입력 :");
    scanf("%d", &math);

    printf("영어 점수 입력 :");
    scanf("%d", &eng);
    printf("\n");
    avg = (kor + math + eng) / 3.0;

    printf("국어: %d\n", kor);
    printf("수학: %d\n", math);
    printf("영어: %d\n\n", eng);

    printf("평균:%.2f\n", avg);

    switch ((int)avg / 10) {
    case 10:
    case 9:
        printf("등급:A\n");
        break;

    case 8:
        printf("등급:B\n");
        break;

    case 7:
        printf("등급:C\n");
        break;

    case 6:
        printf("등급:D\n");
        break;

    default:
        printf("등급:F\n");

    }
    /* if (avg >= 90.0) {
        printf("등급:A");
    }
    else if (avg >= 80.0) {
        printf("등급:B");
    }
    else if (avg >= 70.0) {
        printf("등급:C");
    }
    else if (avg >= 60.0) {
        printf("등급:D");
    }
    else {
        printf("등급:F");
    }*/

    /*    int num;
        scanf("%d", &num);
        switch (num) {
        case 0:
            printf("num의값은 0입니다.\n");
            break;

        case 1:
            printf("num의값은 1입니다.\n");
            break;

        case 2:
            printf("num의값은 0입니다.\n");
            break;

        case 3:
            printf("num의값은 0입니다.\n");
            break;

        case 4:
            printf("num의값은 0입니다.\n");
            break;

        default:
            printf("만족하는 값 없음\n");

        }*/

    int num;
    printf("입력:");
    scanf("%d", &num);

    switch (num >= 14) { //num/14로 하는 것이 아니라 참 거짓 형태로 만들어 두가지 경우로 만든다.
    case 1:
        printf("출력:14보다 같거나 큰 값\n");
        break;

    default:
        printf("출력:14보다 작은 값\n");
    }

    int num2;
    printf("입력:");
    scanf("%d", &num2);

    switch (num2 % 3) {
    case 0:
        printf("출력:참\n");
        break;
    default:
        printf("출력:거짓\n");
    }


    return 0;
}