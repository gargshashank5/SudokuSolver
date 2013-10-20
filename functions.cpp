extern int sudoku[9][9];
bool check_conflict(int i,int j)
/*returns true if the current value of sudoku[i][j] results in a conflict.*/
{
   bool conflict=false;
   int k=sudoku[i][j];
   for(int a=0;a<=8;a++)
    {
        if(sudoku[i][a]==k && a!=j) 
            {conflict=true;
            }
        if(sudoku[a][j]==k && a!=i) 
            {conflict=true;
            }
    }
    int boxi=i/3;   
    int boxj=j/3;
    for(int a=boxi*3;a<=boxi*3+2;a++)
    {
        for(int b=boxj*3;b<=boxj*3+2;b++)
        {
            if(sudoku[a][b]==k && a!=i && b!=j)
                {conflict=true;
                
                }
        }
    }
    return conflict;
}
int empty_cells()
/*returns number of empty cells in sudoku*/
{   int num_zero=0;
    for(int i=0;i<=8;i++)
      {        
               for(int j=0;j<=8;j++) 
               {
                       if(sudoku[i][j]==0)
                       num_zero++;
               }

      }
    return num_zero;
}
