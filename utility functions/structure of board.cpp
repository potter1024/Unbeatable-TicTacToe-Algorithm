struct board
{
    char arr[3][3];
    int score;
    int index;
    board()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                arr[i][j]='-';
    }
};
