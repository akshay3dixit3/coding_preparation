void Solution::setZeroes(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    vector<bool>row(n,false),col(m,false);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==0)
                row[i]=col[j]=true;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(row[i])
        {
            for(int j=0;j<m;j++)
                A[i][j]=0;
        }
    }
    for(int j=0;j<m;j++)
    {
        if(col[j])
        {
            for(int i=0;i<n;i++)
                A[i][j]=0;
        }
    }
}
