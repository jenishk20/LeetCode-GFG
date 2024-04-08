class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=sandwiches.size();
        deque<int>dq;
        stack<int>st;
        reverse(sandwiches.begin(),sandwiches.end());
        int i;
        for(i=0;i<n;i++)
        {
            dq.push_back(students[i]);
        }
        
        for(i=0;i<n;i++)
        {
            st.push(sandwiches[i]);
        }
        // while(!dq.empty())
        // {
        //     cout<<dq.front();
        //     dq.pop_front();
        // }
        int req=100000;
        while(req--)
        {
            if(dq.empty() || st.empty())
            {
                return 0;
                
            }
            
            int req=dq.front();
            int have=st.top();
           // cout<<req<<" "<<have<<endl;
            if(req!=have)
            {
                dq.pop_front();
                dq.push_back(req);
            }
            else
            {
                st.pop();
                dq.pop_front();
            }
            
            
        }
        
        return dq.size();
    }
};