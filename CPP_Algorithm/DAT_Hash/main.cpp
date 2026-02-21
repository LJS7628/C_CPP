#include <iostream>
using namespace std;

/// <summary>
/// Direct Address Table과 Hash의 원리는 유사하다.  DAT는 키 값을 인덱스로 활용하여 사용한다.
/// Hash 또한 특정한 값을 해쉬 함수에 넣어서 나온 결과 값을 인덱스로 사용하는 구조이다.
/// DAT,Hash의 탐색 속도는 매우 빠르지만, 메모리를 많이 사용해야 하는 단점이 존재하며, 
/// Hash의 경우 다른 값을 넣어도 같은 결과 값을 도출하는 해쉬 충돌이 발생할 수도 있다.
/// </summary>

void DAT() 
{
    // 넉넉한 크기의 배열을 선언
    int bucket[256] = {};
    char str[7] = "ADBFAD";

    for (size_t i = 0; i < 6; i++)
    {
        // 아스키코드 자체를 인덱스로 사용
        // 알파벳 갯수를 카운트
        bucket[str[i]]++;
    }

    for (size_t x = 0; x < 256; x++)
    {
        // 알파벳이 존재한다면
        if (bucket[x] != 0)
        {
            // 사용된 알파벳의 종류가 출력된다.
            // 사용된 알파벳의 종류 및 갯수도 함께 출력한다.
            cout << (char)x << " : " << bucket[x] << "\n";
        }
    }
}


int main()
{
    int bucket[256] = {};

    char str[7] = "ADBFAD";
    for (int i = 0; i < 6; i++)
    {
        int idx = str[i];
        bucket[idx]++; // str[i](아스키코드)값 자체를 index로 활용
    }

    int aCount = bucket['A'];

    return 0;
}

