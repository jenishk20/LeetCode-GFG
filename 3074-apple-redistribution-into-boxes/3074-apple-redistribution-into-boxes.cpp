class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        
        int n = capacity.size();
        int i=0;
        
        int sum = accumulate(apple.begin(),apple.end(),0);
        int cnt=0;
        while(i<n){
            if(sum>0){
                cnt++;
            }
            sum-=capacity[i++];
        }
        return cnt;
    }
};