class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> Rightmax(n);
        Rightmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            Rightmax[i]=max(nums[i],Rightmax[i+1]);
        }
        vector<int> ans;
        int Leftmax=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==n-1||nums[i]>Leftmax||nums[i]>Rightmax[i+1]){
                ans.push_back(nums[i]);
            }
            Leftmax=max(nums[i],Leftmax);
        }
        return ans;
   }
};