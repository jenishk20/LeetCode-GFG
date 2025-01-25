class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        map<int,int>numToGroup;
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        int n = temp.size();

        map<int,vector<int>>groupMem;
        int group = 0;
        groupMem[group].push_back(temp[0]);
        numToGroup[temp[0]] = group;

        for(int i=1;i<n;i++){
            if(temp[i] - temp[i-1] <= limit){
                groupMem[group].push_back(temp[i]);
                numToGroup[temp[i]] = group;
            }
            else{
                group++;
                groupMem[group].push_back(temp[i]);
                numToGroup[temp[i]] = group;
            }
        }

        for(auto &it : groupMem) reverse(it.second.begin(),it.second.end());

        for(int i=0;i<n;i++){
            int groupNum = numToGroup[nums[i]];
            int firstEle = groupMem[groupNum].back();
            groupMem[groupNum].pop_back();
            nums[i] = firstEle;
        }

        return nums;
        
    }
};