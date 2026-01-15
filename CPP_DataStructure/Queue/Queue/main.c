/*
 큐(Queue)
	줄, 대기열
	데이터를 순서대로 줄세우는 구조

	맨 앞에 데이터 삽입/맨 뒤에서 데이터 인출
	데이터가 삽입의 정순
	데이터를 넣었다가, 빼면 맨 뒤로 삽입

	FIFO(Frist In Frist Out)
		선입선출

ADT
	속성
	front
		데이터들 중 가장 앞에 있는 데이터의 위치
	rear
		데이터들 중 가장 뒤에 있는 데이터의 위치
	기능
	enQ
		stack에서 push와 같이, 값을 하나 삽입
		queue의 가장 뒤에 값을 삽입
		rear를 가장 뒤의 데이터를 가르키도록 변경
		반환:
				성공시 0
				실패시 -1(0이 아닌 값)
	deQ
		stack에서 pop와 같이, 값을 하나 인출
		queue의 가장 앞에서 인출
		front가 가장 앞의 데이터를 가르키도록 변경
		반환:
				성공시 0
				실패시 -1(음수)
	is_empty
		queue가 텅 비어있는 확인
		비어있다면			1
		비어있지 않다면		0
	is_full
		queue에 데이터가 들어갈 공간이 남아있는지
		남아있지 않다면		1
		남아있다면			0
*/

/*
#include <stdio.h>
#define MAX 10
int front;
int rear;
char queue[MAX];

int enQ(char data);
char deQ();
int is_empty();
int is_full();

int main() {

	front = rear = 0;
	enQ('A');
	enQ('B');
	enQ('C');
	enQ('D');

	for (int i = front; i < rear; i++) {
		printf("%c:", queue[i]);
	}
	printf("\n");
	//A:B:C:D:

	for (int i = 0; i < 4; i++) {
		printf("%c:", deQ());
	}
	printf("\n");
	//A:B:C:D:

	char data = '1';
	while (1) {
		if (enQ(data++)) {
			break;
		}
	}

	while (1) {
		char tmp = deQ();
		if (tmp < 0) {
			break;
		}
		printf("%c:", tmp);
	}

}

char deQ() {
	if (is_empty()) return -1;
	//인출한 데이터 임시저장
	char tmp = queue[front];
	//front가 가르키는 위치 변경
	front++;
	//성공시 데이터 반환
	return tmp;

}

int enQ(char data) {
	if (is_full()) return -1;
	//데이터 삽입(rear가 가르키는 위치)
	queue[rear] = data;
	//rear가 가르키는 위치 변경
	rear++;
	//성공시 0 반환
	return 0;
}

int is_empty() {
	return rear == front;
}

int is_full() {
	return rear >= MAX;
}
*/

/*
	환형큐
		큐는 enQ/deQ 반복시, front 보다 앞에 있는
		공간은 더이상 사용 불가능해지는 단점이 있음
		front와 rear가 같은 방향으로 이동하므로

		이를 해결하기 위해, 큐의 끝 지점과 시작지점을
		논리적으로 마치 연결된 것처럼 취급

		큐가 10개짜리 배열이라면,
			9 다음은 10이 아닌 0으로 사용

	*is_empty 와 is_full 의 차이점을 알기 위해서 한칸을 비워 둔다.
	 그리고 한 싸이클이 돌았는지 확인할 수 도 있다.

		구현
			1. +1 동작변경	(add 함수 구현)
				a + 1 => (a + 1)% MAX
			2. full 조건 변경
				큐에서 가득 찬것과
				텅 빈것을 구분하기 위해
				front 앞의 공간을 버리도록 함

				rear가 해당 공간을 가르키고 있다면
					 full
				따라서, full일 때, rear의 다음공간은
					front

				add(rear) == front 라면 full

*/
/*
#include <stdio.h>
#define MAX 10
int front;
int rear;
char queue[MAX];

int enQ(char data);
char deQ();
int is_empty();
int is_full();

#define add(x)  ((x+1)%MAX)
//매크로 함수
int main() {

	front = rear = 0;
	enQ('A');
	enQ('B');
	enQ('C');
	enQ('D');

	for (int i = front; i < rear; i++) {
		printf("%c:", queue[i]);
	}
	printf("\n");
	//A:B:C:D:

	for (int i = 0; i < 4; i++) {
		printf("%c:", deQ());
	}
	printf("\n");
	//A:B:C:D:

	char data = '1';
	while (1) {
		if (enQ(data++)) {
			break;
		}
	}

	while (1) {
		char tmp = deQ();
		if (tmp < 0) {
			break;
		}
		printf("%c:", tmp);
	}

}

char deQ() {
	if (is_empty()) return -1;
	//인출한 데이터 임시저장
	char tmp = queue[front];
	//front가 가르키는 위치 변경
	front = add(front);
	//성공시 데이터 반환
	return tmp;

}

int enQ(char data) {
	if (is_full()) return -1;
	//데이터 삽입(rear가 가르키는 위치)
	queue[rear] = data;
	//rear가 가르키는 위치 변경
	rear = add(rear);
	//성공시 0 반환
	return 0;
}

int is_empty() {
	return rear == front;
}

int is_full() {
	return add(rear) == front;
}
*/

#include <stdio.h>

#define OVERFLOW

unsigned char front;
unsigned char rear;


#ifdef OVERFLOW
#define add(x) (x+1)
#define MAX 256
#else
#define add(x)  ((x+1)%MAX)
#define MAX 10
#endif

char queue[MAX];
int enQ(char data);
char deQ();
int is_empty();
int is_full();

int main() {

	front = rear = 0;
	enQ('A');
	enQ('B');
	enQ('C');
	enQ('D');

	for (int i = front; i < rear; i++) {
		printf("%c:", queue[i]);
	}
	printf("\n");
	//A:B:C:D:

	for (int i = 0; i < 4; i++) {
		printf("%c:", deQ());
	}
	printf("\n");
	//A:B:C:D:

	char data = '1';
	while (1) {
		if (enQ(data++)) {
			break;
		}
	}

	while (1) {
		char tmp = deQ();
		if (tmp < 0) {
			break;
		}
		printf("%c:", tmp);
	}

}

char deQ() {
	if (is_empty()) return -1;
	//인출한 데이터 임시저장
	char tmp = queue[front];
	//front가 가르키는 위치 변경
	front = add(front);
	//성공시 데이터 반환
	return tmp;

}

int enQ(char data) {
	if (is_full()) return -1;
	//데이터 삽입(rear가 가르키는 위치)
	queue[rear] = data;
	//rear가 가르키는 위치 변경
	rear = add(rear);
	//성공시 0 반환
	return 0;
}

int is_empty() {
	return rear == front;
}

int is_full() {
#ifdef OVERFLOW
	unsigned char tmp = add(rear);
	return tmp == front;
#else
	return add(rear) == front;
#endif
}