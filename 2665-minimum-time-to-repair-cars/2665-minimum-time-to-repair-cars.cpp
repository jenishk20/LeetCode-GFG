class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long low = 0;
        long long high = 1e17;
        long long ans = 0;

        while(low<=high){
            long long mid = (low + high)/2;
            long long canRepair = 0;

            for(int i=0;i<n;i++){
                long long tmp = sqrt(mid/ranks[i]);
                canRepair += tmp;
            }

            if(canRepair >= cars){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

};