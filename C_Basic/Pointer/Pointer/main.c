#include <stdio.h>

//--2차원 배열--
/*
  1차원 배열을 또 다시 배열로 선언 함으로써 여러 개의 배열을 다시 배열로 만드는 방식
  2차원 배열 선언 방법: 자료형 배열명[행 크기][열 크기];
  2차원 배열은 만들어진 공간에 접근할 때 x,y좌표를 생각하고 접근하면 조금 더 쉽게 접근할 수 있다.
  2차원 배열을 초기화 할 떄는 {}(중괄호)와 개행을 적절히 사용한다.
     int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
  2차원 배열을 사용하고 접근할 때는 보통은 이중 for문을 사용해서 접근한다.
*/

//--포인터--
/*
 포인터 변수는 주소를 저장할 수 있는 변수
 포인터 변수 선언 방법: 저장할 공간의 자료형 *(에스타리크스)변수이름;
 포인터 변수안에 저장된 주소로 접근해서 주소안의 값을 확인할 때는
 *포인터변수명으로 확인할 수 있다. 이를 역참조 라고 한다.
 포인터 변수는 일반 변수의 주소를 저장할 수 있고,
 이중 포인터 변수는 포인터 변수의 주소를 저장할 수 있고,
 삼중 포인터 변수는 이중 포인터 변수의 주소를 저장할 수 있고,
 ...

*/




int main() {

    /*   int arr[3][3] = {
           {1,2,3},
           {4,5,6},
           {7,8,9}
       };

       for (int i = 0; i < 3; i++) {
           for (int j = 0; j < 3; j++) {
               printf("%d ", arr[i][j]);
           }
           printf("\n");
       }*/


       //행 크기 10 열 크기 10인 배열을 선언을 하고 해당 배열에 1~100까지의 값을 순차적으로
       //할당하세요.

    /*   int arr[10][10];
       int cnt=1;
       for (int i = 0; i < 10; i++) {
           for (int j = 0; j < 10; j++) {
               arr[i][j] = cnt++;
           }
       }

       for (int i = 0; i < 10; i++) {
           for (int j = 0; j < 10; j++) {
               printf("%3d ", arr[i][j]);
           }
           printf("\n");
       }

       printf("\n------------------------------------\n");

       printf("출력: ");
       for (int i = 0; i < 10; i++) {
           printf("%d ",arr[i][i]);
       }
       printf("\n\n");
       int arr2[4][4];

       cnt = 1;

       for (int i = 0; i < 4; i++) {
           for (int j = 0; j < 4; j++) {
               arr2[i][j] = cnt++;
           }
       }

       for (int i = 0; i < 4; i++) {
           for (int j = 0; j < 4; j++) {
               printf("%2d ", arr2[i][j]);
           }
           printf("\n");
       }

       printf("\n------------------------------\n");

       for (int i = 0; i < 4; i++) {
           for (int j = 0; j < 4; j++) {
               printf("%2d ", arr2[j][i]);
           }
           printf("\n");
       }
       */

    int num = 10;
    int* ptr;
    int** dptr;
    int*** tptr;

    ptr = &num;
    dptr = &ptr;
    tptr = &dptr;
    *ptr = 20;
    printf("num의 주소: %p\n", &num);
    printf("ptr의 값: %p\n", ptr);
    printf("\n");

    printf("num의 값: %d\n", num);
    printf("ptr를 이용한 num의 값: %d\n", *ptr);
    printf("dptr를 이용한 num의 값: %d\n", **dptr);
    printf("tptr를 이용한 num의 값: %d\n", ***tptr);
    printf("\n");

    printf("ptr의 주소: %p\n", &ptr);
    printf("dptr의 값: %p\n", dptr);
    printf("\n");

    printf("dptr의 주소: %p\n", &dptr);
    printf("tptr의 값: %p\n", tptr);
    printf("\n");


    return 0;
}