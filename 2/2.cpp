#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_set>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0, count = 0;
    for (int num : nums) {
        if (num == 1) {
            count++;
            maxCount = max(maxCount, count);
        }
        else {
            count = 0;
        }
    }
    return maxCount;
}

int findNumbers(vector<int>& nums) {
    int count = 0;
    for (int num : nums) {
        if (to_string(num).length() % 2 == 0) {
            count++;
        }
    }
    return count;
}

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result(nums.size());
    int left = 0, right = nums.size() - 1, pos = nums.size() - 1;
    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[pos--] = nums[left] * nums[left];
            left++;
        }
        else {
            result[pos--] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}

void duplicateZeros(vector<int>& arr) {
    int n = arr.size(), zeros = count(arr.begin(), arr.end(), 0);
    for (int i = n - 1; i >= 0; --i) {
        if (i + zeros < n) arr[i + zeros] = arr[i];
        if (arr[i] == 0 && --zeros + i < n) arr[i + zeros] = 0;
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int k = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

bool checkIfExist(vector<int>& arr) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

bool validMountainArray(vector<int>& arr) {
    int n = arr.size(), i = 0;
    while (i + 1 < n && arr[i] < arr[i + 1]) i++;
    if (i == 0 || i == n - 1) return false;
    while (i + 1 < n && arr[i] > arr[i + 1]) i++;
    return i == n - 1;
}

vector<int> replaceElements(vector<int>& arr) {
    int n = arr.size(), maxRight = -1;
    for (int i = n - 1; i >= 0; --i) {
        int temp = arr[i];
        arr[i] = maxRight;
        maxRight = max(maxRight, temp);
    }
    return arr;
}

vector<int> sortArrayByParity(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        if (nums[left] % 2 > nums[right] % 2) {
            swap(nums[left], nums[right]);
        }
        if (nums[left] % 2 == 0) left++;
        if (nums[right] % 2 == 1) right--;
    }
    return nums;
}


int main()
{
    return 0;
}