#include <stdio.h>
#include <string.h>

//--함수--
/*
문자열 관련함수를 사용하기 위해서는 string.h 헤더파일을 선언해줘야 한다.
 strlen(문자열): 넘겨준 문자열의 길이를 반환해주는 함수
                 (반환해주는 길이는 NULL문자를 제외한 길이이다.)
 strcmp(문자열1, 문자열2): 넘겨준 두개의 문자열을 비교하고 같으면 거짓, 다르면 참을 반환해주는 함수
                            (문자열이 다를 경우 무낮열1이 사전편차순으로 빠르면 -1 느리면 1를 반환)
 strcpy(문자열을 저장할 공간, 문자열): 문자열을 저장할 공간에 넘겨받은 문자열을 복사해주는 함수
 strcat(문자열을 붙일 공간, 문자열): 문자열을 붙일 공간 뒤에 넘겨받은 문자열을 덧붙여주는 함수
*/
int main() {

    int num = 0;
    int* ptr;
    ptr = &num;
    printf("입력: ");
    scanf("%d", ptr);
    printf("출력: %d\n", num);

    /*  char str[100] = { 0, };
      scanf("%s", str);
      printf("문자열의 길이: %d\n", strlen(str));*/

      /*   char str1[100] = { 0, };
         char str2[100] = { 0, };


         printf("입력: ");
         scanf("%s", str1);
         printf("입력: ");
         scanf("%s", str2);

         printf("출력: %d\n", strcmp(str1, str2));*/

         /*    char str1[100] = { 0, };
             char str2[100] = { 0, };

             printf("입력: ");
             scanf("%s", str1);

             strcpy(str2,str1);
             printf("출력: %s\n",str2);

             */

    char str1[100] = { 0, };
    char str2[100] = { 0, };

    printf("입력: ");
    scanf("%s", str1);
    printf("입력: ");
    scanf("%s", str2);

    strcat(str1, str2);
    printf("출력 %s\n", str1);

    return 0;
}