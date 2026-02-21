#include <iostream>
#include <queue>

/// <summary>
/// 이진 탐색이란 정렬된 데이터에서 특정 값을 찾기 위해 절반씩 나눠서 찾는 방법이다. 
/// 재귀를 통해 구할 수도 있으며, 다른 방법으로는 투 포인터를 통해 반복문으로 처리할 수 있다. 
/// </summary>


int vect[10] = { 1, 2, 3, 4, 5, 6, 7, 9 };
int target = 7;

void runrecursive(int start, int end)
{
	int mid = (start + end) / 2;

	if (vect[mid] == target)
	{
		std::cout << "found" << std::endl;
		return;
	}
	else if (vect[mid] < target)
	{
		runrecursive(mid + 1, end);
	}
	else
	{
		runrecursive(start, mid - 1);
	}
}

void run()
{
	while (true)
	{
		int start = 0;
		int end = 7;
		int mid = 0;
		bool flag = false;
		while (start <= end)
		{
			mid = (start + end) / 2;

			if (vect[mid] == target)
			{
				flag = true;
				std::cout << "found" << std::endl;
				break;
			}
			else if (vect[mid] < target)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		if (flag)
		{
			break;
		}

		if (start > end)
		{
			std::cout << "not found" << std::endl;
		}
	}
}

int main()
{
	run();
	//runrecursive(0, 7);

	return 0;
}
