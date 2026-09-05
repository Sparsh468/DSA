class Solution {
public:
    long long solve(vector<int> &nums,int k,int m,int limit){
        if(k==0) return 0;
        unordered_map<int,int>freq;
        int left=0;
        int good=0;
        long long ans=0;
        for(int right=0;right<nums.size();right++){
            freq[nums[right]]++;
            if(freq[nums[right]]==m) good++;
            while(freq.size()>=limit&&good>=k){
                freq[nums[left]]--;
                if(freq[nums[left]]==m-1) good--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            ans+=left;
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int k, int m) {
        return solve(nums,k,m,k)-solve(nums,k,m,k+1);
    }
};