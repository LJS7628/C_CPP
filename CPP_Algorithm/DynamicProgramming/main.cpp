#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// DP란 동적 계획법으로 알고리즘보단 방법론에 가깝다. 
/// 큰 문제를 작은 문제로 쪼갤 수 있으며 그 패턴이 반복되는 경우 사용할 수 있다. 
/// 작은 문제의 최적해가 큰 문제의 최적해에 해당해야 하는 조건이 필요하다.
/// 기존의 재귀적 방법보다 이미 계산한 결과값을 저장하여 사용하기 때문에 속도와 메모리 측면에서 좋다.
/// </summary>


//재귀로 구하는 피보나치 수열
int factorial(int n)
{
    if (n <= 1)
        return 1;

    //int result = n * factorial(n - 1);
  //return result;

    return n * factorial(n - 1);
}

//DP를 활용한 피보나치 수열
int factorial_dp(int n)
{
    if (n < 0)
        return -1;

    std::vector<int> dp(n + 1);
    dp[0] = 1;

    for (size_t i = 1; i < n + 1; i++)
        dp[i] = dp[i - 1] * i;

    return dp[n];
}

// 동전 교환 문제
void solveCoinExchange()
{
    // 동전 집합과 목표 금액
    vector<int> coins = { 3, 4, 5 };
    int amount = 15;

    // DP 테이블 초기화: (동전 개수+1) x (금액+1)
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1; // 아무 동전도 사용하지 않고 0원을 만드는 경우 1가지

    // DP 채우기
    for (int i = 1; i <= coins.size(); i++) // 각 동전별
    {
        int coin = coins[i - 1];
        for (int j = 0; j <= amount; j++)
        {
            if (j < coin)
                dp[i][j] = dp[i - 1][j]; // 해당 동전을 못 쓰는 경우
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - coin]; // 점화식
        }
    }

    // 결과 출력
    cout << "DP 테이블 (행: 동전개수, 열: 금액)" << endl;
    for (int i = 0; i <= coins.size(); i++)
    {
        for (int j = 0; j <= amount; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << "\n" << amount << "원을 만드는 경우의 수: " << dp[coins.size()][amount] << endl;
}

// 배낭 문제
void solveKnapsack() 
{
    // 게임 설정
    int capacity = 5;

    vector<string> items = { "마법반지", "신검", "용방패", "왕의왕관" };
    vector<int> weights = { 2, 3, 4, 5 };
    vector<int> values = { 3, 4, 5, 6 };
    int n = items.size();

    // DP 테이블 초기화
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    cout << " RPG 게임 - 던전 아이템 수집하기" << endl;
    cout << " 인벤토리 용량: " << capacity << "칸\n" << endl;

    // 아이템 정보 출력
    cout << " 발견한 아이템들:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "  " << (i + 1) << ". " << items[i]
            << " (용량: " << weights[i] << "칸, 가치: " << values[i] << ")" << endl;
    }
    cout << endl;

    // DP 계산
    for (int i = 1; i <= n; i++)
    {
        cout << " " << i << "단계: " << items[i - 1] << " 검토 중..." << endl;

        for (int w = 0; w <= capacity; w++)
        {
            if (weights[i - 1] > w)
            {
                // 현재 아이템이 용량을 초과하는 경우
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                // 선택하지 않는 경우와 선택하는 경우 중 최대값
                int not_take = dp[i - 1][w];
                int take = dp[i - 1][w - weights[i - 1]] + values[i - 1];
                dp[i][w] = max(not_take, take);

                // 최대 용량에서의 계산 과정 출력
                if (w == capacity)
                {
                    cout << "  용량 " << w << "칸: max(" << not_take
                        << ", " << take << ") = " << dp[i][w] << endl;
                }
            }
        }
        cout << endl;
    }

    // 최종 DP 테이블 출력
    cout << " 최종 DP 테이블:" << endl;
    cout << "        ";
    for (int w = 0; w <= capacity; w++)
    {
        cout << "c" << w << " ";
    }
    cout << endl;

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            cout << "없음:   ";
        }
        else
        {
            cout << i << "개:   ";
        }
        for (int w = 0; w <= capacity; w++)
        {
            cout << dp[i][w] << "  ";
        }
        cout << endl;
    }

    cout << "\n 최대 가치: " << dp[n][capacity] << endl;

    // 선택된 아이템 역추적
    cout << "\n 선택된 아이템들:" << endl;
    vector<bool> selected(n, false);
    int w = capacity;

    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selected[i - 1] = true;
            cout << "   " << items[i - 1]
                << " (용량: " << weights[i - 1] << "칸, 가치: " << values[i - 1] << ")" << endl;
            w -= weights[i - 1];
        }
        else
        {
            cout << "   " << items[i - 1] << " (선택하지 않음)" << endl;
        }
    }

    // 최종 요약
    int total_weight = 0, total_value = 0;
    for (int i = 0; i < n; i++)
    {
        if (selected[i])
        {
            total_weight += weights[i];
            total_value += values[i];
        }
    }

    cout << "\n 최종 요약:" << endl;
    cout << "  총 사용 용량: " << total_weight << "/" << capacity << "칸" << endl;
    cout << "  총 가치: " << total_value << endl;
    cout << "  남은 용량: " << (capacity - total_weight) << "칸" << endl;
}

int main()
{


    return 0;
}
