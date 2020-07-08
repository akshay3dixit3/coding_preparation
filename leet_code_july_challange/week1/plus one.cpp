class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        
        for(int i = digits.size() -1 ; i>=0; i--)
        {
            int tmp;
            if(i == digits.size() -1)
            {
                tmp =  digits[i] + carry + 1;
            }
            else
            {
                tmp = digits[i] + carry;
            }
            // cout<<"tmp"<<tmp<<endl;
            carry = tmp/10;
            cout<<carry<<endl;
            digits[i] = tmp%10;
        }
        cout<<carry;
        if(carry == 1)
        {
            cout<<"here";
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};