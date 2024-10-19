class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n==1 or k==1 : return '0'
        
        sz = (1<<n)-1
        mid = 1 + sz//2
        
        print(sz,mid)
        
        if k == mid : return '1'
        if k < mid : return self.findKthBit(n-1,k)
        
        res = self.findKthBit(n-1,sz-k+1)
        return '1' if res == '0' else '0'
        