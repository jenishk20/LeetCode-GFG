class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        vector<double>medians;
        int n = nums.size();

        multiset<int>m1,m2;

        for(int i=0;i<n;i++){

            m1.insert(nums[i]);
            m2.insert(*m1.rbegin());
            m1.erase(m1.find(*m1.rbegin()));

            int k1 = m1.size();
            int k2 = m2.size();

            if(k1<k2){
                m1.insert(*m2.begin());
                m2.erase(m2.find(*m2.begin()));
            }

            if(i>=k-1){
                if(k&1){
                    medians.push_back(*m1.rbegin());
                }
                else{
                    double r1 = *m1.rbegin();
                    double r2 = *m2.begin();
                    medians.push_back((r1 + r2)/2.0);
                }

                if(nums[i-k+1]<=*m1.rbegin()){
                    m1.erase(m1.find(nums[i-k+1]));
                }
                else{
                    m2.erase(m2.find(nums[i-k+1]));
                }
            }
        }
        return medians;


    }
};