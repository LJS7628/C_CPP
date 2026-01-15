/*
 스택(Stack)
 - 데이터를 차곡차곡 쌓는 형태로 이루어진 자료구조
 - 데이터들 중 맨 위에 데이터를 쌓을 수 있음
 - 데이터들 중 맨 위에서 데이터를 뺄 수 있음
        위의 특징 때문에, 데이터는 삽입의 역순 출력
        데이터를 넣었다가 뺐다 해도, 순서가 유지

    "데이터들 중 맨위" 가 어딘지 저장할 변수가 필요
        top

    top 의 위에 데이터를 집어 넣음
    top 에서 데이터를 추출

    데이터를 넣는 함수
        push
    데이터를 빼는 함수
        pop

 Stack 의 ADT(Abstract Data Type : 추상자료형)
            - 기능/속성 나열

    top     : 스택에서 현재 가장 위의 위치를 저장하는 속성

    push    : 스택에 값을 하나 삽입하는 기능
              스택의 가장 위(top이 가르키는 위치)에 값을 삽입
              가장 위를 의미하는 top을 +1 이동
              반환 : 성공시 0, 실패시 -1(0이 아닌 값)

    pop     : 스택에서 값을 하나 가져오는 기능
              스택의 가장 위(top이 가르키는 위치-1)에서 값을 하나 반환
              가장 위를 의미하는 top을 이동
              반환 : 성공시 가장 위에 있던 값 실패시 -1(음수)

    isFull  : 현재 스택이 가득 차있는지 여부를 알려주는 기능
      반환  : 가득 차 있는 경우  : true  (1)
              아닌 경우          : false (0)

    isEmpty : 현재 스택이 텅 비어있는지 여부를 알려주는 기능
      반환  : 가득 차 있는 경우  : true  (1)
              아닌 경우          : false (0)
*/

#include <stdio.h>
#define MAX 10

char stack[MAX];
int top;

int push(char data);
char pop();
inline int is_full();
inline int is_empty();
int main() {
    top = 0;
    push('A');
    push('C');
    push('B');
    push('D');

    for (int i = 0; i < top; i++)
    {
        printf("%c : ", stack[i]);
    }
    printf("\n");
    //A : B : C : D:

    int size = top;
    for (int i = 0; i < size; i++) {
        printf("%c : ", pop());
    }
    printf("\n");
    //D : C : B : A : 
    int d = 'A';
    while (1) {
        int tmp = push(d++);
        if (tmp) break;
    }

    size = top;
    while (1) {
        char tmp = pop();
        if (tmp == -1) break;
        else printf("%c : ", tmp);
    }
}

int push(char data) {
    //꽉차있을때 push 실패  
    //*함수 사용시 ()쓰기 안쓰면 함수의 주소값을 의미
    if (is_full()) return -1;
    stack[top] = data;
    //스택의 가장 위에 데이터 삽입
    top++;
    //top의 위치+1
    return 0;
    // 성공시 0 반환
}

char pop() {
    if (is_empty()) return -1;
    top--;
    //top의 위치 -1
    return stack[top];
    //스택에 가장 위에 있는 데이터 반환
}

inline int is_full() {
    //스택이 가득 차 있는 경우 1 반환
    //아닌 경우  0 반환

    return(top == MAX);
    /*if (top == MAX)
        return 1;
    else
        return 0;*/
}

inline int is_empty() {
    //스택이 텅 비어있는 경우 1
    //아닌 경우 0 반환
    return (top == 0);
}