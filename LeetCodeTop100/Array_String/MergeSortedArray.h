#pragma once
#include <vector>
using namespace std;

/// <summary>
/// 오름차순으로 정렬된 배열 2개가 주어졌을 때, 첫번째 배열에 두 배열을 합쳐서 저장하라.
/// </summary>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // 두개의 포인터를 활용하여, 값을 비교하고 배열 뒤에서 부터 채운다.
        // 앞에서 채울 경우 데이터가 훼손되기 때문에 뒤에서 채워야 한다.

        int p1 = m;
        int p2 = n;
        int pos = m + n - 1;

        while (p1 != 0 || p2 != 0)
        {
            if (p1 == 0)
                nums1[pos--] = nums2[--p2];
            else if (p2 == 0)
                nums1[pos--] = nums1[--p1];
            else if (nums1[p1 - 1] >= nums2[p2 - 1])
                nums1[pos--] = nums1[--p1];
            else if (nums1[p1 - 1] < nums2[p2 - 1])
                nums1[pos--] = nums2[--p2];
        }

    }
};