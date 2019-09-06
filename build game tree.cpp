void build(board b,char turn,int index,int depth)
{
    if(check(b)=='X')
    {
        store[mapping[index]].score=10;
        win++;
        return;
    }
    if(check(b)=='O')
    {
        store[mapping[index]].score=-10;
        lose++;
        return;
    }
    if(check(b)=='D')
    {
        store[mapping[index]].score=0;
        draw++;
        return;
    }
    int ma=-10000,mi=10000;
    if(turn=='C')
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(b.arr[i][j]=='-')
                {
                    board next=b;
                    next.arr[i][j]='X';
                    next.index=len;
                    store.pb(next);
                    mapping[len]=store.size()-1;
                    len++;
                    game[index].pb(len-1);
                    int x=len-1;
                    build(next,'P',len-1,depth+1);
                    ma=max(ma,store[mapping[x]].score);
                }
            }
        }
        store[mapping[index]].score=ma-depth;
    }
    if(turn=='P')
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(b.arr[i][j]=='-')
                {
                    board next=b;
                    next.arr[i][j]='O';
                    next.index=len;
                    store.pb(next);
                    mapping[len]=store.size()-1;
                    len++;
                    game[index].pb(len-1);
                    int x=len-1;
                    build(next,'C',len-1,depth+1);
                    mi=min(mi,store[mapping[x]].score);
                }
            }
        }
        store[mapping[index]].score=mi+depth;
    }
}
