class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i<k||nums[i]!=nums[i-k]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};