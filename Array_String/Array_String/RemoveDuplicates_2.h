#pragma once
#include <vector>
using namespace std;

/// <summary>
/// 오름차순으로 정렬된 배열이 주어 졌을 때, in-place  방식으로 추가 메모리 없이
/// 중복된 수를 찾아내서 제거하고 배열 사이즈를 반환하라. 중복된 수는 원소당 2개까지만 인정된다.
/// ex) [1,1,1,1,2,2,2,3,3] => [1,1,2,2,3,3]
/// </summary>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //예외처리 : 사이즈가 너무 작은 경우 즉시 반환
        if (nums.size() <= 2) return nums.size();

        int k = 2; // 처음 두 요소는 무조건 포함되므로 2부터 시작

        for (int i = 2; i < nums.size(); i++) {
            // 현재 검사하는 요소(nums[i])가 
            // 결과 배열의 뒤에서 두 번째 요소(nums[k-2])와 다르다면 추가 가능
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i]; // 물리적 삭제 대신 덮어쓰기
                k++;
            }
        }
        return k; // 유효한 요소의 개수 반환
    }
};