#pragma once
int* merge_sort(int data_ori[], int size);
void _merge_sort(int data[], int start, int end, int buff[]);
void merge(int data[], int start, int mid, int end, int buff[]);