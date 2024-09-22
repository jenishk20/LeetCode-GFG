class Solution {
public:
    
    long long count(long long curr,long long next,int n){
        
        long long cnt = 0;
        while(curr<=n){
            
            cnt += (next-curr);
            curr = curr * 1ll* 10;
            next = next * 1ll * 10;
            
            next = min(next,(long long)n+1);
        }
        
        return cnt;
    }
    int findKthNumber(int n, int k) {
        
        long long curr = 1;
     
        k-=1;
        
        while(k){
            
            long long have = count(curr,curr+1,n);
            if(have<=k){
                curr++;
                k-=have;
            }
            else{
                curr*=10;
                k--;
            }
        }
        
        return curr;
    }
};