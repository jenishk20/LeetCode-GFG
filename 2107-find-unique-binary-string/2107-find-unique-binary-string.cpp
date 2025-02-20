class Solution {
public:
    string ans = "";
    void recur(string curr,vector<string>&nums,int i,int sz){
        if(i == sz){
            if(find(nums.begin(),nums.end(),curr) == nums.end()){
                ans = curr;
            }
            return;
        }
        for(int j=0;j<=1;j++){
            curr += (j+'0');
            recur(curr,nums,i+1,sz);
            curr.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        string curr = "";
        int sz = nums.size();
        recur(curr,nums,0,sz);
        return ans;
    }
};