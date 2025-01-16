class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n%2==0 and m%2==0) return 0;

        if(n%2==0){
            int xori = 0;
            for(auto it : nums1){
                xori^=it;
            }
            return xori;
        }

        if(m%2==0){
            int xori = 0;
            for(auto it : nums2){
                xori^=it;
            }
            return xori;
        }

        int xori = 0;
        for(auto it : nums2){
            xori^=it;
        }
        for(auto it : nums1){
            xori^=it;
        }

        return xori;
    }
};