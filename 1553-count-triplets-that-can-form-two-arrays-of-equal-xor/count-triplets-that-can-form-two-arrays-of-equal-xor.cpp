class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,int>cnt;
        unordered_map<int,int>sum;
        int ans=0;
        int xr=0;
        cnt[0]=1;sum[0]=-1;
        for(int i=0;i<arr.size();i++){
            xr^=arr[i];
            if(cnt.count(xr)){
                ans+=cnt[xr]*(i-1)-sum[xr];
            }
            cnt[xr]++;
            sum[xr]+=i;
        }
        return ans;
    }
};