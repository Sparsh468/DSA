class Solution {
public:
    int findmax(vector<int> &v){
        int maxi=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }
    long long calculatetotalhours(vector<int> &v,int hourly){
        int n=v.size();
        long long totalH=0;
        for(int i=0;i<n;i++){
            totalH+=(v[i]+(long long)hourly-1)/hourly;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int low=1,high=findmax(v);
        while(low<=high){
            int mid=(low+high)/2;
            long long totalH=calculatetotalhours(v,mid);
            if(totalH<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};