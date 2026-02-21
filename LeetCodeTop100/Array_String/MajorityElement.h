#pragma once
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 사이즈가 n인 배열이 주어졌을 때, n/2 이상 등장하는 원소를 출력하라.
/// 무조건 배열 안에 정답이 있음을 보장한다.
/// </summary>

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // 맵을 활용하면 쉽게 풀 수 있지만 메모리를 O(1)로 사용하기 위해 방법을 달리함
        // 정렬을 한 후-> 하나씩 카운팅 하다가 숫자가 바뀌면, 카운팅을 초기화 하고 다시 센다.
        // 카운팅 갯수가 n/2이 된다면 즉시 반환한다.
        sort(nums.begin(), nums.end());
        int result = nums[0];
        int cnt = 1;
        int n = nums.size();

        for (int i = 1; i < nums.size(); ++i)
        {
            if (cnt > n / 2)
                return result;

            if (nums[i] == result)
                ++cnt;
            else
            {
                cnt = 1;
                result = nums[i];
            }
        }

        return result;
    }
};