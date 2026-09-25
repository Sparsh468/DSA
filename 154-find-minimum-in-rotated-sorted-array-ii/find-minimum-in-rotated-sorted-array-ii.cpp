class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            if(low==high){
                ans=min(ans,nums[low]);
                break;
            }
            int mid=(low+high)/2;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                ans = min(ans, nums[low]);
                low++,high--;
            }else if(nums[low]<=nums[mid] && nums[mid]<=nums[high]){
                ans=min(ans,nums[low]);
                break;
            }else if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }else{
                ans=min(nums[mid],ans);
                high=mid-1;
            }
        }
        return ans;
    }
};