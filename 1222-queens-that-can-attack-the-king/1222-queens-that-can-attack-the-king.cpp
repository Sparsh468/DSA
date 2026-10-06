class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        int board[8][8]={0};
        for(auto q:queens){
            board[q[0]][q[1]]=1;
        }
        int dr[]={-1,-1,-1,0,0,1,1,1};//if the queen changes row
        int dc[]={-1,0,1,-1,1,-1,0,1};//if the queen changes column
        for(int d=0;d<8;d++){
            int r=king[0]+dr[d];
            int c=king[1]+dc[d];
            while(r>=0 && r<8 && c>=0 && c<8){
                if(board[r][c]==1){
                    ans.push_back({r,c});
                    break;
                }
                r+=dr[d];
                c+=dc[d];
            }
        }
        return ans;
    }
};