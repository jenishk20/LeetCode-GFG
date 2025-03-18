class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.size();
        stringstream ss(path);
        string temp;
        vector<string>se;

        while(getline(ss,temp,'/')){
            if(temp == ".."){
                if(!se.empty()) se.pop_back();
            }
            else if(temp != "." and !temp.empty()){
                se.push_back(temp);
            }
        }

        string ans = "";

        for(auto str : se){
            ans += "/" + str;
            
        }
        if(ans.empty()) return "/";
        return ans;
    }
};