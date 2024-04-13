class Solution {
public:
    int maxarea(int arr[], int n)
    {
        // Your code here
        
        vector<int>nsr;
        vector<int>nsl;
        int i;
        
        stack<pair<int,int>>se;
        for(i=0;i<n;i++)
        {
            if(se.empty())
            {
                nsl.push_back(-1);
            }
            else if(se.top().first<arr[i])
            {
                nsl.push_back(se.top().second);
            }
            else
            {
                while(!se.empty() && se.top().first>=arr[i])
                {
                    se.pop();
                }
                if(se.empty())
                {
                    nsl.push_back(-1);
                }
                else
                {
                    nsl.push_back(se.top().second);
                }
            }
            se.push({arr[i],i});
           // cout<<"HELLO";
        }
        
        while(!se.empty())
        se.pop();
        
        for(i=n-1;i>=0;i--)
        {
            if(se.empty())
            {
                nsr.push_back(n);
                
            }
            else if(se.top().first<arr[i])
            {
                nsr.push_back(se.top().second);
            }
            else
            {
                while(!se.empty() && se.top().first>=arr[i])
                {
                    se.pop();
                }
                if(se.empty())
                {
                    nsr.push_back(n);
                }
                else
                {
                    nsr.push_back(se.top().second);
                }
            }
            se.push({arr[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        // for(auto &it:nsl)
        // cout<<it<<" ";
        // cout<<endl;
        //  for(auto &it:nsr)
        // cout<<it<<" ";
        // cout<<endl;
        
        int ans=0;
        for(i=0;i<n;i++)
        {
            ans=max(ans,(nsr[i]-nsl[i]-1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
        int r=matrix.size();
        if(r==0)
            return 0;
        int c=matrix[0].size();
       
        
         int  arr[1001];
        memset(arr,0,sizeof(arr));
        
         int i,j;
        int ans=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                
                if(matrix[i][j]=='0'){
                arr[j]=0;
                continue;
                }
                arr[j]+=(matrix[i][j]-'0');
                
               // cout<<M[i][j]<<" ";
            }
            // for(int k=0;k<m;k++)
            // {
            //     cout<<arr[k]<<" ";
            // }
            // cout<<maxarea(arr,m+1);
            // cout<<endl;
            ans=max(ans,maxarea(arr,c));
        }
        
        return ans;
       
        
    }
};