class Solution {
public:
    int firstoccurrence(vector<int> &nums,int n,int x){
        int low=0,high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==x){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return first;
    }
    int lastoccurrence(vector<int> &nums,int n,int x){
        int low=0,high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==x){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=firstoccurrence(nums,n,target);
        if(first==-1) return {-1,-1};
        int last=lastoccurrence(nums,n,target);
        return {first,last};
    }
};