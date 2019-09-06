char check(board b)
{
    for(int i=0;i<3;i++)
    {
        int count=0;
        for(ll j=0;j<3;j++)
        {
            if(b.arr[i][j]=='X')
                count++;
        }
        if(count==3)
            return 'X';
        count=0;
        for(ll j=0;j<3;j++)
        {
            if(b.arr[i][j]=='O')
                count++;
        }
        if(count==3)
            return 'O';
        count=0;
        for(ll j=0;j<3;j++)
        {
            if(b.arr[j][i]=='O')
                count++;
        }
        if(count==3)
            return 'O';
        count=0;
        for(ll j=0;j<3;j++)
        {
            if(b.arr[j][i]=='X')
                count++;
        }
        if(count==3)
            return 'X';
    }
    if(b.arr[0][0]=='X' && b.arr[1][1]=='X' && b.arr[2][2]=='X')
        return 'X';
    if(b.arr[0][0]=='O' && b.arr[1][1]=='O' && b.arr[2][2]=='O')
        return 'O';
    if(b.arr[0][2]=='X' && b.arr[1][1]=='X' && b.arr[2][0]=='X')
        return 'X';
    if(b.arr[0][2]=='O' && b.arr[1][1]=='O' && b.arr[2][0]=='O')
        return 'O';
    int count=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(b.arr[i][j]=='-')
                count++;
        }
    }
    if(count==0)
        return 'D';
    else
        return '-';
}
