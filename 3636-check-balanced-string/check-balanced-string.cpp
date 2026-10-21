class Solution {
public:
    bool isBalanced(string num) {
        vector<int> arr;
        int oddsum=0;
        int evensum=0;
        for(int i=0;i<num.length();i++){
            arr.push_back(num[i]-'0');
        }
        for(int i=0;i<arr.size();i++){
            if(i%2!=0){
                oddsum+=arr[i];
            }else{
                evensum+=arr[i];
            }
        }
        if(evensum==oddsum) return true;
        return false;
    }
};