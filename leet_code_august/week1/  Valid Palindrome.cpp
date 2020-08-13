class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "")
            return true;
        
       int left = 0, right = s.length()-1;
        while(left<right)
        {
            if(left<right && !isalnum(s[left])) left++;
            else if(right > left && !isalnum(s[right])) right--;
            else if(tolower(s[left])!=tolower(s[right])) return false;
            else {left++; right--;}
        }
        return true;    
    }
};