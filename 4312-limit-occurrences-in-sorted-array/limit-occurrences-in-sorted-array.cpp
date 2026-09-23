class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(j<k||nums[i]!=nums[j-k]){
                nums[j]=nums[i];
                j++;
            }
        }
        nums.resize(j);
        return nums;
    }
};