class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
       multiset<int>se;
        int i;
        int n=heights.size();
        for(i=0;i<n-1;i++)
        {
            int diff=heights[i+1]-heights[i];
            if(diff>0)
                se.insert(heights[i+1]-heights[i]);
            
            if(se.size()>ladders)
            {
                bricks-=(*se.begin());
                se.erase(se.begin());
                
                if(bricks<0)
                    return i;
            }
        }
        
        return n-1;
    }
};