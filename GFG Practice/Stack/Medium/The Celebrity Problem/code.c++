int celebrity(vector<vector<int> >& arr, int n) 
{
    stack<int>stk;
    for(int i=n-1;i>=0;i--)
    {
        stk.push(i);
    }
    while(stk.size()>=2)
    {
        int x=stk.top();
        stk.pop();
        int y=stk.top();
        stk.pop();
        
        if(arr[x][y]==1)
        {
            stk.push(y);
        }
        else if(arr[y][x]==1)
        {
            stk.push(x);
        }
    }
    if(stk.size()==1)
    {
        int col=stk.top();
        for(int i=0;i<n;i++)
        {
            if(i==col)
            {
                continue;
            }
            if(arr[i][col]==0)
            {
                return -1;
            }
        }
        return col;
    }
    else 
    {
        return -1;
    }
}
