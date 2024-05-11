class Solution {
public:
    double recur(int idx,int selectedIdx,double ratio,vector<int>&quality,
    vector<int>&wage,int k){
        
        if(idx>=quality.size()){

            if(k>0)
            return 1000000000.0;
            else return 0.0;
        }

        double expectedWage = quality[idx] * ratio;
        double op1,op2;

        cout<<idx<<" "<<expectedWage<<" "<<wage[idx]<<endl;

        if(expectedWage>=wage[idx] && k){
            op1 = expectedWage + recur(idx+1,selectedIdx,ratio,quality,wage,k-1);
            op2 = recur(idx+1,selectedIdx,ratio,quality,wage,k);
            cout<<"Printing Ops "<<op1<<" "<<op2<<endl;
        }
        else{
            op2 = recur(idx+1,selectedIdx,ratio,quality,wage,k);
        }
        
        return min(op1,op2);
    } 
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
        
//         int n = quality.size();

//         int i;
//         double ans = DBL_MAX;
//         for(i=0;i<n;i++){
//             double ratio = wage[i]/quality[i];
//             double a1 = recur(0,i,ratio,quality,wage,k-1);
//             cout<<"Inside loop "<<a1<<endl;
//             ans = min(ans,a1); 
//         }

//         return ans;
        
        vector<vector<double>> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.push_back({(double)(w[i]) / q[i], (double)q[i]});
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker: workers) {
            qsum += worker[1], pq.push(worker[1]);
            if (pq.size() > K) qsum -= pq.top(), pq.pop();
            if (pq.size() == K) res = min(res, qsum * worker[0]);
        }
        return res;
    }
};