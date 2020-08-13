class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        map<char,int> mp;  //map to store frequency of characters
        
        for(auto i:s)
            mp[i]++;
        
        vector<pair<int,char>> v;
        for(auto i=mp.begin();i!=mp.end();i++)    
          v.push_back(make_pair(i->second, i->first));  //v[0] ->frequency , v[1]->character
        
        sort(v.rbegin(),v.rend());   //sort according to frequency decreasing order
        for (int i = 0; i < v.size(); i++)
	    { 
            int k=v[i].first;   //store frequency of each characters
            while(k--)
		        ans+=v[i].second;  //run the loop and add to string each char .
	    }
        
        return ans;
    }
};