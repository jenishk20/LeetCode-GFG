# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        q = deque()
        pq = []
        
        q.append(root)
        
        while q:
            sumi = 0
            sz = len(q)
            for _ in range(len(q)):
                curr = q.popleft()
                sumi += curr.val
                
                if(curr.left): 
                    q.append(curr.left)
                if(curr.right) : 
                    q.append(curr.right)
            
            heapq.heappush(pq,sumi)
            if len(pq) > k:
                heapq.heappop(pq)
                
        return pq[0] if len(pq) == k else -1
            
            