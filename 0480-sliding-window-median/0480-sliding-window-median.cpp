class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>ans;
        int n = nums.size();
        multiset<int>m1,m2;

        for(int i=0;i<n;i++){
            m1.insert(nums[i]);
            m2.insert(*m1.rbegin());
            m1.erase(m1.find(*m1.rbegin()));

            if(m1.size() < m2.size()){
                m1.insert(*m2.begin());
                m2.erase(m2.find(*m2.begin()));
            }

            if(i>=k-1){
                if(k&1){
                    double res = *m1.rbegin();
                    ans.push_back(res);
                }
                else{
                    double res = (double)((double)*m1.rbegin() + *m2.begin())/2.0;
                    ans.push_back(res);
                }

                if(nums[i-k+1]<= *m1.rbegin()){
                    m1.erase(m1.find(nums[i-k+1]));
                }
                else{
                    m2.erase(m2.find(nums[i-k+1]));
                }
            }
        }
        return ans;
    }
};