#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int acc_left(vector<int> &nums, int pos) {
    int acc_l = 0;
    for (int i = 0; i < pos; i++) {
      acc_l += nums[i];
    }
    return acc_l;
  }
  int acc_right(vector<int> &nums, int pos) {
    int acc_r = 0;
    for (int i = pos + 1; i < nums.size(); i++) {
      acc_r += nums[i];
    }
    return acc_r;
  }
  int pivotIndex(vector<int> &nums) {
    int pivot = -1;
    for (int i = 0; i < nums.size(); i++) {
      int acc_l = acc_left(nums, i);
      int acc_r = acc_right(nums, i);
      if (acc_l == acc_r) {
        pivot = i;
        break;
      }
    }
    return pivot;
  }
};

int main() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(7);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(5);
  nums.push_back(6);
  Solution solution = Solution();
  int pivot = solution.pivotIndex(nums);
  cout << pivot << endl;
}
