class Solution {
public:
    int answer = 0;
    void countArrangementUtil(int n, int pos, vector<bool> visited)
    {
        if(pos > n)
        {
            answer++;
            
        }
        
        for(int i=1; i<=n; i++)
        {
             if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                 {
                     visited[i] = true;
                     countArrangementUtil(n, pos+1, visited);
                     visited[i] = false;
                 }
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> visited(n+1, false);
        countArrangementUtil(n,1,visited);
        return answer;   
    }
};