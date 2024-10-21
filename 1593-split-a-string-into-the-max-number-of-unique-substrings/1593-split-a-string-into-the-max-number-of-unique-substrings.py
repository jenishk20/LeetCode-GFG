class Solution:
    def recur(self,start,s,se):
        if start == len(s):
            return 0
        max_splits = 0
        
        for i in range(start+1,len(s)+1):
            substring = s[start:i]
            if substring in se: continue
            
            se.add(substring)
            max_splits = max(max_splits,1+self.recur(i,s,se))
            se.remove(substring)
                
        return max_splits
    
    def maxUniqueSplit(self, s: str) -> int:
        se = set()
        return self.recur(0,s,se)
        