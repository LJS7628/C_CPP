#include <iostream>

/// <summary>
/// 쿽정렬은 피벗이라는 기준값을 선택하여 작으면 왼쪽, 크면 오른쪽으로 분할하며
/// 다 정렬될 때까지 위 과정을 반복 수행한다.  nlog(n)으로 빠른 속도를 자랑하지만
/// 데이터의 값에 따라 최악의 경우 n^2으로 수행될 수 있다.
/// </summary>

int vect[10] = { 4,3,9,8,5,7,1,2 };
int n = 8;

void quicksort(int start, int end)
{
    if (start >= end)
        return;

    int pivot = start;    // 첫 번째 원소를 피벗으로
    int a = start + 1;    // 왼쪽에서 시작
    int b = end;          // 오른쪽에서 시작

    while (true)
    {
        // a: pivot보다 큰 원소를 찾을 때까지 오른쪽으로 이동
        while (a <= end && vect[a] <= vect[pivot])
            a++;

        // b: pivot보다 작은 원소를 찾을 때까지 왼쪽으로 이동
        while (b >= start && vect[b] > vect[pivot])
            b--;

        // a와 b가 엇갈렸으면 종료
        if (a > b)
            break;

        // 찾은 원소들을 교환
        std::swap(vect[a], vect[b]);
    }

    // pivot을 올바른 위치(b)로 이동
    std::swap(vect[pivot], vect[b]);

    // 재귀 호출로 좌우 부분 정렬
    quicksort(start, b - 1);    // 왼쪽 부분
    quicksort(b + 1, end);      // 오른쪽 부분
}

int main()
{
    quicksort(0, n - 1);

    // 결과 출력
    for (int i = 0; i < n; i++) {
        std::cout << vect[i] << " ";
    }

    return 0;
}
