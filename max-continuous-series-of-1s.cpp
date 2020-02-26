/*

You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.
*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    int wr=0, wl=0;
    int start,end;
    int numzeroes = 0;
    int maxlen = -1;
    vector<int> result;
    while(wr<A.size())
    {
    	//Increase the size of window till the maximum number of zeroes are utilised.
        if(numzeroes <= B)
        {
            if(A[wr] == 0)
            {
                numzeroes++;        
            }
            wr++;
        }
        // Decrease the size of the window till we get in the range Given in the question.
        if(numzeroes > B)
        {
            if(A[wl] == 0)
            {
                numzeroes--;
            }
            wl++;
        }
        // Kepp track of the Window.
        if(wr - wl + 1 > maxlen)
        {
            maxlen = wr - wl + 1;
            start = wl;
            end = wr;
        }
    }
    // Vector func to place the digit back of the vector. (IMPORTANT i DIDNT know of the same.)
    for (auto i = start; i<end; ++i)
        result.emplace_back(i);
    
    return result;
}
