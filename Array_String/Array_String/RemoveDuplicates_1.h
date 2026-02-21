#pragma once
#include <vector>
using namespace std;

/// <summary>
/// 오름차순으로 정렬된 배열이 주어 졌을 때, in-place  방식으로 추가 메모리 없이
/// 중복된 수를 찾아내서 제거하고 배열 사이즈를 반환하라. 
/// ex) [1,1,1,1,2,2,2,3,3] => [1,2,3]
/// </summary>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // 예외 처리 : 배열이 비어있는 경우
        if (nums.empty()) {
            return 0;
        }

        int i = 0;
        
        for (int j = 1; j < nums.size(); ++j) {
            // 현재 i 위치의 값과 j 위치의 값이 다르면 새로운 값 발견
            if (nums[i] != nums[j]) {
                // i를 다음 위치로 이동시키고
                i++;
                // 그 위치에 j의 값을 덮어씀
                nums[i] = nums[j];
            }
            // 값이 같으면 j만 이동하고 i는 멈춰 있음 (중복 스킵)
        }

        return i + 1;
    }
};