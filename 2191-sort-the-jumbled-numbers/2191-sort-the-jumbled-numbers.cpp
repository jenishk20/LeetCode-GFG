class Solution {
    map<int,int>ma;
private:
    int change(int x)
    {
        string res=to_string(x);
        string fres="";
        for(auto i:res)
        {
            fres+=to_string(ma[i-'0']);
        }
        return stoi(fres);
    }
public:
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<int>ans;
        multimap<int,int>temp;
        
        for(int i=0;i<=9;i++)
            ma[i]=mapping[i];
       
        for(int i=0;i<nums.size();i++)
        {
            int res=change(nums[i]);
            temp.insert(make_pair(res,i));
        }
        // sort(temp.begin(),temp.end(),[](pair<int,int>p1,pair<int,int>p2){
        //    return p1.first<p2.first; 
        // });
        
        for(auto i:temp)
            ans.push_back(nums[i.second]);
        
        return ans;
    }
};