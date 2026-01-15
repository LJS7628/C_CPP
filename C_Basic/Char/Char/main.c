#include <stdio.h>

//--NULL--
// NULL이란 공간이 비여 있다는 뜻이다.
// 문자형 배열을 초기화 할 때  '0'으로 초기화하면  NULL로 초기화 된다. 
int main() {


    /*    char ch[10] = {0,};
        int index = 0;
        printf("입력: ");
        scanf("%s", ch);

        while (ch[index] != NULL)
            index++;

        printf("출력: %d", index);

        printf("\n-----------------------\n");

        char str1[15] = {0,};
        char str2[15] = {0,};
        int index1 = 0;
        int flag = 0;

        getchar();
        printf("입력: ");
        scanf("%[^\n]s", str1);
        getchar();
        printf("입력: ");
        scanf("%[^\n]s", str2);

        while (str1[index1] != NULL || str2[index1] != NULL)
        {
            if (str1[index1] != str2[index1]) {
                flag = 1;
                break;
            }
            index1++;
        }
        printf("출력: %d", flag);*/

        /*   char str1[15] = {0,};
           char str2[15] = {0,};
           int index = 0;
           printf("입력: ");
           scanf("%s", str1);

           while (str1[index]!=NULL) {
               str2[index] = str1[index];
               index++;
           }

           printf("출력: %s", str2);
           printf("\n-------------------\n");

           char str3[15] = {0,};
           char str4[15] = {0,};
           int index1 = 0;
           int index2 = 0;
           printf("입력: ");
           scanf("%s", str3);
           printf("입력: ");
           scanf("%s", str4);

           while (str3[index1] !=NULL) index1++;

           while (str4[index2] != NULL) {
               str3[index1++] = str4[index2++];
           }

           printf("출력: %s", str3);*/


    return 0;

}