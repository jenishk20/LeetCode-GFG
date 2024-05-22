class Solution {
public:
    bool isPal(string &s,int i,int j)
    {
        if(i==j)
            return true;
        if(i>j)
            return false;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
   void recur(string &s,int idx,vector<vector<string>>&ans,vector<string>&temp)
    {
        if(idx==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(isPal(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                recur(s,i+1,ans,temp);
                temp.pop_back();

            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        
      vector<vector<string>> res;
        vector<string> curr;
        
        recur(s,0,res,curr);
        return res;
    }
};