class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int cnt=0;
        int longest=1;
        int lastelement=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastelement){
                cnt++;
                lastelement=nums[i];
            }else if(nums[i]!=lastelement){
                cnt=1;
                lastelement=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};