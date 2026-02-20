#include <stdio.h>
#include <array>

using namespace std;

int main() 
{
	int a[3] = { 10,20,30 };
	for (int b : a) 
	{
		printf("a[3] : %d\n", b);
	}


	array<int, 3> list = {30,20,10};

	for (int b : list) 
	{
		printf("list[3] : %d\n", b);
	}
	return 0;
}