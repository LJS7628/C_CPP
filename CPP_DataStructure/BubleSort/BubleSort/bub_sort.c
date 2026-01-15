#include <stdlib.h>
#include "util.h"

int* bub_sort(int data_ori[], int size) {
	int* data = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		data[i] = data_ori[i];
	}

	for (int i = 1; i < size; i++) {

		for (int j = 0; j < size - i; j++) {

			if (data[j] > data[j + 1]) {
				swap(data, j, j + 1);
			}
		}
	}

	return data;
}
