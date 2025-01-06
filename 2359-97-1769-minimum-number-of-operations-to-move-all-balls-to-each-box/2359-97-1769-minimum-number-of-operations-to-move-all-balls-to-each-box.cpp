class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int i;
        int totOne = 0;

        vector<int>pfxOneSum(n,0),sfxOneSum(n,0);

        for(i=0;i<n;i++){
            if(boxes[i] == '1') totOne++;
        }

        for(i=1;i<n;i++){
            if(boxes[i-1] == '1') pfxOneSum[i] = pfxOneSum[i-1] + i-1;
            else pfxOneSum[i] = pfxOneSum[i-1];
        }

        for(i=n-2;i>=0;i--){
            if(boxes[i+1] == '1') sfxOneSum[i] = sfxOneSum[i+1] + i+1;
            else sfxOneSum[i] = sfxOneSum[i+1]; 
        }

        vector<int>ans;
        int currOne = 0;
       
        for(i=0;i<n;i++){
           
            int sfxOne = totOne - currOne - (boxes[i] == '1');
            int sum = 0;
            
            sum += (currOne)*i - pfxOneSum[i];
            
            if(sfxOneSum[i] != 0){
                sum += sfxOneSum[i] - sfxOne*i;
            }

            ans.push_back(sum);
            if(boxes[i] == '1') currOne++;
        }
        return ans;
    }
};