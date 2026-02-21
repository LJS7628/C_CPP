#pragma once
#include <vector>
using namespace std;

/// <summary>
///  배열과 값이 주어졌을 때, 배열에 해당 값을 지우고 배열의 사이즈를 반환하라.
/// ex)  val : 3 || [3,2,2,3] -> [2,2] 
/// 결과 2
/// </summary>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // 현재 타겟값과 같다면 뒤에 있는 값과 바꾼 다음 제거한다.
        int idx = 0;

        while (idx < nums.size())
        {
            if (nums[idx] == val)
            {
                swap(nums[idx], nums[nums.size() - 1]);
                nums.pop_back();
            }
            else
                ++idx;
        }

        return nums.size();
    }
};