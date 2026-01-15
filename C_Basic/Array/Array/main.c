#include <stdio.h>
#include <windows.h>

//--기타 함수--
/*system(): system("") , "(큰 따옴표) 안에 작성되는 명령어르 실행시켜주는 함수
*cls = > 콘솔 창을 한번 지워준다.
Sleep(멈춰줄 시간): 콘솔창을 잠깐 재워주는 함수, 일시적으로 화면을 멈춘다. *시간 단위는 1/1000초이다.
Sleep함수를 사용하기 위해서는 windows.h 헤더파일을 선언을 해줘야 한다.
*/

//--배열--
/*
일정한 간격을 두고 붙여놓은 것
특정 자료형을 가진 변수를 여러개 선언할 떄 사용
배열 선언 방법: 자료형 배열이름[배열크기];
 배열의 각 요소를 index(인덱스)라고 부른다.
 인덱스는 (선언한 공간의 크기 -1) 까지 갖고 있다. 즉, 0부터 시작한다.
 배열의 각 인덱스를 초기화 해줄수 있는데 초기화를 진행할 떄는
 int arr[10] = { 1,2,3,4,5,6,7,8,9,0 } 형식으로 진행이 된다.
 배열을 선언하면서 모든 인덱슬를 0으로 초기화 하고 싶을 때는
 int arr[10] = {0,}과 같이 초기화를 진행한다.
*/
int main() {

    /*   printf("ABCD\n");

       Sleep(10000);
       system("cls");

       printf("EFGH\n");*/
       //내 답안
    /* int money=10000;
       int temp;
       while (1) {
           int key;
           printf("카드 잔액: %d\n",money);
           printf("1. 카드 잔액 충전\n");
           printf("2. 카드 잔액 사용\n");
           printf("3. 종료\n");
           printf("입력:");
           scanf("%d", &key);

           switch (key) {
           case 1:
               system("cls");
               printf("충전 금액 입력:");
               scanf("%d", &temp);
               money += temp;
               printf("\n사용 가능한 금액: %d", money);
               Sleep(1500);
               system("cls");
               break;
           case 2:
               system("cls");
               printf("사용 가능한 잔액: %d", money);
               printf("\n사용하실 금액 입력:");
               scanf("%d", &temp);
               while (temp > money) {
                   printf("\n한도 초과\n");
                   Sleep(1500);
                   system("cls");
                   printf("사용 가능한 잔액: %d\n", money);
                   printf("사용하실 금액 입력:");
                   scanf("%d", temp);
               }
               money -= temp;
               printf("남은 잔액:%d", money);
               Sleep(1500);
               system("cls");
               break;


           case 3:
               system("cls");
               printf("프로그램을 종료합니다.");
               Sleep(1500);
               break;

           default :
               system("cls");
               printf("잘못된 값을 입력하셨습니다. 다시 입력해주세요.\n");
               Sleep(1500);
               system("cls");
           }
           if (key == 3) break;
       }*/

       //선생님 답안

    /*   int sel, card = 10000,money;
       int flag = 1;
       while (flag) {
           system("cls");
           printf("카드 잔액: %d\n", card);
           printf("1. 카드 잔액 충전\n");
           printf("2. 카드 잔액 사용\n");
           printf("3. 종료\n");
           printf("입력: ");
           scanf("%d", &sel);

           switch (sel) {
           case 1:
               system("cls");
               printf("카드 잔액: %d\n", card);
               printf("충전 금액 입력: ");
               scanf("%d", &money);
               card += money;
               printf("%d원 충전되어 %d원 사용가능합니다.\n", money, card);
               break;
           case 2:
               while (1) {
                   system("cls");
                   printf("카드 잔액: %d\n", card);
                   printf("사용 금액 입력: ");
                   scanf("%d", &money);
                   if (money > card) {
                       printf("잔액이 부족합니다.\n");

                   }
                   else {
                       card -= money;
                       printf("%d원 사용하고 %d원 남았습니다.\n", money, card);
                       break;
                   }
                   Sleep(1500);
               }

               break;
           case 3:
               flag = 0;
               break;
           }
           Sleep(1500);
       }*/

       /*int a, b, c, d, e, f, g, h, i, j;
       printf("입력:");
       scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
       printf("출력:%d %d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i,j);*/

       /*int a[10];
       printf("입력: ");
       for (int i = 0; i < 10; i++) {
           scanf("%d", &a[i]);
       }
       printf("출력: ");
       for (int i = 0; i < 10; i++) {
           printf("%d ", a[i]);
       }*/

       /*int arr[10];

       printf("입력:");
       for (int i = 0; i < 10; i++) {
           scanf("%d", &arr[i]);
       }

       printf("출력:\n");
       for (int i = 0; i < 10; i++) {
           printf("arr[%d] %d\n",i, arr[i]);
       }*/

    int arr2[8];
    int sel;
    int count = 0;
    printf("10진수 입력:");
    scanf("%d", &sel);

    for (int i = 0; i < 8; i++) {
        arr2[i] = sel % 2;
        sel /= 2;
    }

    printf("2진수 출력:");
    for (int i = 7; i >= 4; i--) {
        if (arr2[i] == 1) {
            count++;
        }
    }
    for (int i = 7; i >= 4; i--) {
        if (count == 0) break;
        printf("%d", arr2[i]);
    }
    printf(" ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", arr2[i]);
    }

    /*
    int arr[32] ={0,};
    int num;
    int index = 0;

    printf("입력: ");
    scanf("%d",&num);
    while(num !=0){
     arr[index++] = num % 2;
     num /= 2;
    }

    for(int i = 4*(((index-1)/4)+1)-1; i>=0;i--){
      printf("%d", arr[i]);
      if(i % 4 == 0) printf(" ");
    }
    */
    return 0;
}