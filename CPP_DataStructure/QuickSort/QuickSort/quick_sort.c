#include <stdlib.h>
#include "util.h"
#include "quick_sort.h"
int* quick_sort(int data_ori[], int size) {
	int* data = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		data[i] = data_ori[i];
	}
	_quick_sort(data, 0, size - 1);
	return data;
}
void _quick_sort(int* data, int start, int end) {
	//데이터가 1개 이하이면 반복하지 않음
	if (end - start <= 0) return;
	int pivot;
	pivot = partition(data, start, end);
	//pivot 을 기준으로 앞 부분과 뒷 부분으로 분할하여 재귀
	_quick_sort(data, start, pivot - 1);
	_quick_sort(data, pivot + 1, end);
}
int partition(int* data, int start, int end) {
	int sel;
	int left, right;
	//1. 현재 범위 중 가장 앞의 값을 선택
	//2. 선택된 값을 제외하고 가장 앞의값의 위치(선택값 뒤)l
	//   범위중 가장 뒤의 값의 위치를 r 로
	sel = data[start];
	left = start + 1;
	right = end;
	while (1) {
		//3. 왼쪽 커서는 선택된 값 보다 큰 값을 만날때까지 진행
		// 범위를 벗어나도 멈춰야 한다.
		while (left <= end && data[left] <= sel) left++;

		//4. 오른쪽 커서는 선택된 값 보다 작은 값을 만날때까지 진행
		while (right > start && data[right] > sel) right--;



		//6. 만약, 두 커서가 서로 교차했거나(범위를 벗어나면)
		//	오른쪽 커서가 가르키는 위치와 선택된 값을 교체
		if (left > right) {
			swap(data, start, right);
			break;
		}
		else {
			//5. 오른쪽 커서의 값과 왼쪽 커서의 값을 서로 교체
			swap(data, left, right);
		}

	}
	return right;
}