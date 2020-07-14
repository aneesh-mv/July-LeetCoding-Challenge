/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        vector<int> tmp;
        int len;
        for (int n: nums) {
            len = res.size();
            for (int i = 0; i < len; i++) {
                tmp = res[i];
                tmp.push_back(n);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
