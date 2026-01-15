#include <stdio.h>
#include "util.h"
#include <stdlib.h>
#include "quick_sort.h"

int main() {
	int data[] = { 7,5,2,6,9,10,0,1,15,20 };
	int size = sizeof(data) / sizeof(int);

	int* sorted;
	sorted = quick_sort(data, size);
	print_list(data, size);
	print_list(sorted, size);
}
