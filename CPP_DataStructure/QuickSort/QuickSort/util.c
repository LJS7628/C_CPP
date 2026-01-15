#include <stdio.h>

void print_list(int data[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d:", data[i]);
	}
	printf("\n");
}
void swap(int data[], int x, int y) {
	int tmp = data[x];
	data[x] = data[y];
	data[y] = tmp;
}