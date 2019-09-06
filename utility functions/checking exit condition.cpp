bool over(board b)
{
    if(check(b)=='X')
    {
        print(b);
        cout<<"You Lost\n";
        return 1;
    }
    if(check(b)=='O')
    {
        print(b);
        cout<<"You Win\n";
        return 1;
    }
    if(check(b)=='D')
    {
        print(b);
        cout<<"Tie\n";
        return 1;
    }
    return 0;
}
