class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size();
        
        int i,j,k;
        
        if(minutes>=n) return accumulate(customers.begin(),customers.end(),0);
        
        i=0,j=0;
        int currSumOfNotIncluded = 0;
        int windowStart = 0;
        int maxi = 0;
        
        while(j<n){
            
            if(grumpy[j]){
                currSumOfNotIncluded += customers[j];
            }
            
            if(j-i+1 == minutes){
              
                if(currSumOfNotIncluded > maxi){
                    maxi = currSumOfNotIncluded;
                    windowStart = i;
                }
                
                cout<<i<<" "<<j<<" "<<currSumOfNotIncluded<<" "<<windowStart<<endl;
                currSumOfNotIncluded -= (grumpy[i]?customers[i]:0);
                i++;
            }
            
            j++;
        }
        
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            if(i>=windowStart && i<=windowStart + minutes-1){
                sum+=customers[i];
            }
            else{
                sum+= (grumpy[i]?0:customers[i]);
            }
        }
        
        return sum;
    }
};