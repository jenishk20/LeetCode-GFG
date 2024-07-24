class Solution {
public:
    long long calc(vector<int>&temp){
        
        if(temp.size()==0) return 0ll;
        
        long long cnt = abs(temp[0]);
        
        for(int i=1;i<temp.size();i++){
            cnt += (abs(temp[i])>abs(temp[i-1])?abs(temp[i]-temp[i-1]):0);
        }
        return cnt;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();
        vector<int>diff(n);
        
        int i;
        for(i=0;i<n;i++){
            diff[i] = target[i] - nums[i];
        }
        
        long long ans = 0;
        for(i=0;i<n;){
            
            if(diff[i] == 0){
                i++;
            }
            vector<int>temp,temp1;
            while(i<n and diff[i]>0){
                temp.push_back(diff[i]);
                i++;
            }
          
            while(i<n and diff[i]<0){
                temp1.push_back(diff[i]);
                i++;
            }
            
            for(auto it : temp){
                cout<<it<<" ";
            }
            cout<<endl;
            
            for(auto it : temp1){
                cout<<it<<" ";
            }
            cout<<endl;
            
            cout<<calc(temp)<<" "<<calc(temp1)<<endl;
            
            ans += calc(temp) + calc(temp1);
        }
        return ans;
    }
};