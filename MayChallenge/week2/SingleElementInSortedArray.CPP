class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i+=2){
            if(i==nums.size()-1 || nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};
/*
class Solution {
public:
int singleNonDuplicate(vector<int>& nums) {
  if (nums.size() == 1) {
    return nums[0];
  }
  int low = 0;
  int high = nums.size() - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (mid % 2 == 0) {
      // if x appears in left half, then 2k+1 elements
      // if in right half, then 2k elements in left side
      if (nums[mid] == nums[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    } else {
      if (nums[mid] == nums[mid + 1]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
  }

  return nums[low];
}
};
*/
/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/