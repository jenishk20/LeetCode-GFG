class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>st(n),en(n);
        int i = 0;
        for(auto it : intervals){
            st[i] = it[0];
            en[i] = it[1];
            i++;
        }
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());

        int cnt = 0;
        int ans = 0;
        i=0;
        int j=0;

        while(i<n){
            if(st[i] < en[j]){
                cnt++;
                i++;
            }
            else{
                j++;
                cnt--;
            }
            // cout<<i<?<" "<<j<<" "<<cnt<<endl;
            ans = max(ans,cnt);
        }
        return ans;
    }
};