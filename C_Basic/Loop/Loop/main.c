#include <stdio.h>

/*---반복문----
 조건식을 비교하면 참일경우 종속문장을 실행시키고 변화식을 거쳐 조건식을 또 다시 비교하는 구문
 for(), while(), do~while() 3가지가 존재
 for()문의 기본 원형:
 for(초기식;조건식;변화식)
 {
    종속문장;
 }
 for()문에서 종속문장이 한 줄 일때는 {(중괄호)룰 생략할 수 있다.
 for()문에서 무한루프를 돌리고 싶을때는 초기식,조건식,변화식을 생략하면 된다.
 for()문에서 초기식,조건식,변화식은 선택적으로 작성할 수 있다.

 *기타*
 // break: 해당 구문을 만나게 되면 반복문을 탈출
 // continue: 해당 구문을 만나게 되면 continue보다 아래 있는 종속문장은 실행하지 않고 진행된다.
*/
int main() {

    /*  for (int i = 0; i < 10; i++) {
          if (i == 5) {
              continue;
          }
          printf("Hello World! \t i: %d\n", i);
      }*/

      /*   for (int i = 65; i < 91; i++) {
             printf("%c  ", i);
         }

         printf("\n");

         char ch;
         printf("입력: ");
         scanf("%c", &ch);
         printf("출력: ");
         for (int i = 97; i <=ch; i++) {
            printf("%c ", i);
         }

         printf("\n");

         int i;
         for (;;) {
             printf("입력: ");
             scanf("%d", &i);
             if (i == 9) {
                 printf("출력: 9\n");
                 printf("9가 입력되어 프로그램을 종료합니다.");
                 break;
             }
             printf("출력: %d\n",i);
         }*/
         /*
             //1번 문제
             for (int i = 0; i < 5; i++) {
                 printf("*****\n");
             }

             printf("------------------------\n");

             //2번 문제
             for (int i = 0; i < 5; i++) {
                 for (int j = 0; i - j > 0; j++) {
                     printf(" ");
                 }
                 printf("**\n");
             }

             printf("------------------------\n");

             //3번 문제
             for (int i = 0;i<5;i++) {
                 for (int j = 0;j<4-i;j++) {
                     printf(" ");
                 }
                 for (int k = 0; k < i * 2 + 1; k++) {
                     printf("*");
                 }
                printf("\n");
             }

             printf("------------------------\n");

             //4번 문제
             for (int i = 0; i < 5; i++) {
                 for (int j = 0; j < i; j++) {
                     printf(" ");
                 }
                 for (int k = 0; k < 9-i*2; k++) {
                     printf("*");
                 }
                 printf("\n");
             }
         */
         //3)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            printf("*");
            if (i >= 0 && i <= 4) {
                for (int k = 1; k < i; k++) {
                    printf(" ");
                }
                if (i >= 1) {
                    for (int x = 0; x < 1; x++) {
                        if (i == 4) { break; }
                        printf("*");
                    }
                    for (int y = 7; y > i * 2; y--) {
                        printf(" ");
                    }
                    for (int z = 0; z < 1; z++) {
                        printf("*");
                    }
                    for (int k = 1; k < i; k++) {
                        printf(" ");
                    }
                }
            }

            if (i >= 5 && i <= 7) {
                for (int k = 7; k > i; k--) {
                    printf(" ");
                }
                if (i >= 5) {
                    for (int x = 0; x < 1; x++) {
                        printf("*");
                    }
                    for (int y = 9; y < i * 2; y++) {
                        printf(" ");
                    }
                    for (int z = 0; z < 1; z++) {
                        printf("*");
                    }
                    for (int k = 7; k > i; k--) {
                        printf(" ");
                    }
                }
            }

            if (i > 0 && i < 8) { break; }
        }
        printf("*\n");
    }

    printf("\n---------------------------\n");
    // 4번 문제

    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 16; j++) {
            printf("*");
            if (i >= 0 && i <= 7) {
                for (int k = 1; k < i; k++) {
                    printf(" ");
                }
                if (i >= 1) {
                    for (int x = 0; x < 1; x++) {
                        printf("*");
                    }
                    for (int y = 7; y > i; y--) {
                        printf(" ");
                    }
                    for (int z = 0; z < 1; z++) {
                        printf("*");
                    }
                    for (int a = 7; a > i; a--) {
                        printf(" ");
                    }
                    for (int b = 0; b < 1; b++) {
                        printf("*");
                    }
                    for (int c = 1; c < i; c++) {
                        printf(" ");
                    }
                }
            }

            if (i >= 9 && i <= 15) {
                for (int k = 7; k > i; k--) {
                    printf(" ");
                }
                if (i >= 9) {
                    for (int x = 0; x < 1; x++) {
                        printf("*");
                    }
                    for (int y = 9; y < i; y++) {
                        printf(" ");
                    }
                    for (int z = 0; z < 1; z++) {
                        printf("*");
                    }
                    for (int k = 9; k < i; k++) {
                        printf(" ");
                    }
                    for (int a = 0; a < 1; a++) {
                        printf("*");
                    }
                    for (int b = 15; b > i; b--) {
                        printf(" ");
                    }
                }
            }

            if (i > 0 && i < 17) { break; }
        }
        printf("*\n");

    }




    return 0;

}