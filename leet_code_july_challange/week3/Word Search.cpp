class Solution {
public:
    int m,n;
    bool find(vector<vector<char>>& board, string word,int i,int j,int pos)
    {
        if(pos==word.size()) //is equal to word size so yes word is found.
        {
            return 1;
        }
        if(i<0||j<0||i>=m||j>=n) //is safe or not
            return 0 ;
        
        if(board[i][j]=='1') //already checked.
            return 0 ;
        
        if(board[i][j]==word[pos])
        {
             char k=board[i][j];
             board[i][j]='1';
             if(find(board,word,i+1,j,pos+1)){ return 1;}
             if(find(board,word,i,j+1,pos+1)){ return 1;}
             if(find(board,word,i-1,j,pos+1)){ return 1;}
             if(find(board,word,i,j-1,pos+1)){ return 1;}
             board[i][j]=k;
        }
        return 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {   if(word.size()==1) return 1;
                    if(find(board,word,i,j,0)) return 1;
                }
                
            }
        return 0;
    }
};