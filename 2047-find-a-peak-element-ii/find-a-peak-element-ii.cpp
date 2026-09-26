class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            //Find max element in the mid column...TOP AND BOTTOM NEIGHBOURS TAKEN CARE OF
            int row=0;
            for(int i=0;i<m;i++){
                if(mat[i][mid]>mat[row][mid]){
                    row=i;
                }
            }
            int left=-1;
            int right=-1;
            //Checking left and right neighbours
            if(mid-1>=0){
                left=mat[row][mid-1];
            }if(mid+1<n){
                right=mat[row][mid+1];
            }if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }if(left>mat[row][mid]){//MOVE LEFT...ELIMINATE RIGHT
                high=mid-1;
            }else{//MOVE RIGHT....ELIMINATE LEFT
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};