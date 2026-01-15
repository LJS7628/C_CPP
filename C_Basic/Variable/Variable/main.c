#include <stdio.h>

//-----변수-----
//값이 변하는 수
//변수를 선언하는 방법: 자료형 변수이름;
//변수를 선언하면 공간을 할당받고 그 공간에 접근하기 위해서 변수 이름을 사용
//변수를 생성하면 기존 공간에있던 값이 있는데 그 값을 쓰레기 값 이라고 부르고
//쓰레기 값을 초기화 해줄 때는 선언과 동시에 값을 할당 해주면 된다.

//------변수 이름 선언규칙------
//변수의 이름은 숫자로 시작할 수 없다.
//변수의 이름 사이에는 공백을 포함할 수 없다.
//변수의 이름은 영문자(대소문자), 숫사 , 언더스코어(_)로만 구성된다.
//변수의 이름은 미리 정의된 키워드와 같은 이름으로 쓸 수 없다.

//------자료형------
//문자형
//char: 1byte, -128~127
//----------------------------------------------------------------
//정수형
//short: 2byte, -32768 ~32767
//int : 4byte -2,147,483,648 ~ 2,147,483,647
//long :  4byte  -2,147,483,648 ~ 2,147,483,647
//long long :8byte, -9,223,372,036,854,775,808 ~ 9,223,372,036,853
//-----------------------------------------------------------------
//실수형
//float : 4byte, (3.4x10^-38)~(3.4X10^38)
//double : 8byte 
//long double: 8byte이상
//-----------------------------------------------------------------
//------입력------
// scanf()함수를 사용해서 입력을 받는다.
// scanf("입력받을 서식 지정", 입력받은 값을 저장할 변수의 주소);
// scanf()함수에서 기본적으로 입력을 마친다는 뜻으로 사용되는 문자는
// 공백(스페이스 바) 과 개행(엔터)이다.
// scanf()함수 "(큰 따옴표)안에는 문자열은 작성할 수 없고,
//문자를 작성하는 경우에는 해당 문자로 값을 구분지을 때 사용한다. 
// ex) scanf("%d.%d.%d", &a, &b, &c);  => 입력시 10.20.30 처럼 중간에 점을 찍어야함
int main() {
    /*  int num;

      num = 10;

      printf("%d\n", num);
      printf("%d\n", &num);
      num = 20;

      printf("%d\n", num);
      printf("%d\n", &num);

      printf("\n==============================================\n\n");

      int number=10;
      char ch='A';
      double number2=20.0;

      printf("num의 값: %d\n", number);
      printf("ch의 값: %c\n", ch);
      printf("number의 값: %f\n", number2);

      printf("\n==============================================\n\n");

      int age;
      double hei, wei;
      age = 30;
      hei = 183.2;
      wei = 70.53;

      printf("이름: %s\n", "홍길동");
      printf("나이: %d\n", age);
      printf("주소: %s\n", "서울 특별시 종로구 묘동 단성사");
      printf("키: %.1f \t 몸무게: %.2f\n", hei, wei);

      printf("\n==============================================\n\n");

      printf("%%c를 이용한 출력: \'%c\'\n", 'C');
      printf("%%s를 이용한 출력: \"%s\"\n", "Hello");
      printf("%%d를 이용한 출력: %d\n", 4315);
      printf("%%f를 이용한 출력: %.3f\n", 73.235);

      printf("\n==============================================\n\n");*/
      /* int i;
       char ch;
       double d;

       printf("int i 입력: ");
       scanf("%d", &i);
       printf("int i의 값은 : %d\n\n", i);

       printf("char ch 입력: ");
       scanf("%c", &ch);
       printf("char ch의 값은 : %c\n\n", ch);

       printf("double d 입력: ");
       scanf("%lf", &d);
       printf("double d의 값은 : %.2f\n\n", d);*/
       /*   int a;
          char ch;
          double b;

          scanf("%d %c %lf", &a, &ch, &b);
          printf("%d %c %.2f", a, ch, b);*/

    char a;
    char b;
    scanf("%c %c", &a, &b);
    printf("%c %c\n", b, a);

    int year;
    int month;
    int day;

    scanf("%d-%d-%d", &year, &month, &day);
    printf("%d년 %02d월 %d일\n", year, month, day);

    int num1, num2, num3, num4, num5, num6, num7, num8;
    printf("k: 75, g: 71, i:73,  t:84 b: 66, a: 65, n: 78 k: 75\n");
    scanf("%d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8);
    printf("%c%c%c%c%c%c%c%c\n", num1, num2, num3, num4, num5, num6, num7, num8);

    /*  int x[8];
      printf("k: 75, g: 71, i:73,  t:84 b: 66, a: 65, n: 78 k: 75\n");
      for (int i = 0; i < 8; i++) {
          scanf("%d", &x[i]);
      }

      for (int i = 0; i < 8; i++) {
          printf("%c", x[i]);
      }*/




    return 0;

}