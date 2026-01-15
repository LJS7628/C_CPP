/*
재귀 함수(recursion)

	자기 자신을 호출하는 함수
	A -> A - > A -> A .......
	재귀 함수는 일종의 반복문 처럼 동작하게 됨

	직접재귀 : 자기 자신을 바로(직접) 호출하는 함수
				A -> A - > A -> A .......
	간접재귀 : 자기 자신을 호출하는 함수를 호출하는 함수
				A - > B - > C -> A -> B .......

재귀를 사용하는 이유
	사람(프로그래머)이 편하기 위해 사용
	컴퓨터에게는 오히려 불편한 코드

ex) f(x) = 5 + 4 + 3 + 2 + 1
		 = 5 + f(5-1)
	1씩 줄여가면서 1까지 더한 것

	위를 일반화 하면
	f(n) = n + f(n-1)

	int f(int n) {
		if(n == 1) {
			return 1;
		}
		else{
			return n + f(n-1);
		}
	}

	재귀문 작성시엔 항상 "탈출조건" 이 필요함
	탈출조건이 없을 경우 반복을 멈추지 않음


꼬리 재귀
	재귀 함수가 return 에서 재귀하는 것을 의미

	재귀함수는 코드(알고리즘) 작성을 쉽게 해주지만
	몇가지 문제점이 존재

		1. 재귀 마다, "함수 호출" 작업을 하며
		   이는 컴퓨터 입장에서 반복문과 달리
		   일이 늘어난다는것을 의미 (즉, 성능 하락)
		2. 재귀 마다, 고유의 스택 공간을 새로 할당
		   제한된 공간인 스택이 모두 차서,
		   프로그램이 중간에 꺼져버릴 소지가 큼

	이를 해결하기 위한 문법이 "꼬리 재귀"
		함수 호출 과정이 생략되더라도 결과가 같음
	컴파일러가 알아서, 함수 호출 과정 없이 수행해줌
		컴파일러 "최적화"

	재귀함수를 쓰면 안되고 꼬리 재귀도 안되는데
	반복횟수가 5000번 이상이라면 재귀의 형태를 유지한
	스택을 사용한다. (스택과 재귀함수의 동작 원리가 비슷하다.)

피보나치 수열(fibonachi 수열)
	1 1 2 3 5 8 13 ...
	fibo(n) = fibo(n-1) + fibo(n-2)
	1번째와 2번째 피보나치 수는 무조건 1
*/

#include <stdio.h>


/* //꼬리 재귀
void test(int n){
	printf("%d:",n);
	return test(n-1);
}
*/
int factorial(int n);
int factorial2(int n);
int fibo(int n);
int fibo2(int n);
int fib[100] = { 0,1,1 };
int main() {

	printf("10! = %d\n", factorial(10));
	printf("10! = %d\n", factorial2(10));
	printf("0! = %d\n", factorial(0));
	printf("0! = %d\n", factorial2(0));
	printf("10번째 피보나치 수 : %d\n", fibo(10));
	printf("10번째 피보나치 수 : %d\n", fibo2(10));

}

int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int factorial2(int n) {
	int res = 1;
	while (n) {
		res *= n;
		n--;
	}
	return res;
}

int fibo(int n) {
	//if (n == 1 || n == 2) return 1;
	if (fib[n] != 0) return fib[n];
	fib[n] = fibo(n - 1) + f(n - 2);  // 의미없는 반복을 피할 수 있는 코드
	return fib[n];
}

int fibo2(int n) {
	int fib = 1;
	int n_1 = 1;
	int n_2 = 1;
	for (int i = 3; i <= n; i++) {
		fib = n_1 + n_2;
		n_2 = n_1;
		n_1 = fib;
		//n 이 3일때 n-1 = 2
		//n 이 4일때 n-2 = 2
	}
	return fib;
}