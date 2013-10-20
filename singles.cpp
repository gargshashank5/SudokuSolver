int empty_cells();
bool check_conflict(int i,int j);
extern int sudoku[9][9];



int naked_single()
/*This function tries to fill 1 to 9 at every empty cell in each row. If only one of the numbers is possible
then it updates the cell.If not, the cell remains 0. If some cells were filled after first iteration
the procedure is iterated again, else the function terminates.*/
{   
    int empty_cells_in_prev_iter=0;
    while(empty_cells_in_prev_iter != empty_cells())
    {   
        empty_cells_in_prev_iter = empty_cells(); 
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int possible_guesses=0;
                int cell_value=0;
                if(sudoku[i][j]==0)
                {
                    for(int guess=1;guess<=9;guess++)
                    {
                        sudoku[i][j]=guess;
                        if(!check_conflict(i,j))
                        {
                            possible_guesses++;
                            cell_value=guess;
                        }
                    }
                    if(possible_guesses!=1)
                    {
                        sudoku[i][j]=0;
                    }
                    else
                    {
                       sudoku[i][j]=cell_value;
                    }
                }
            }
        }       
    }
    return 0;
}


void column_hidden_single()
/*Finds the values from 1-9 which can only be filled in one cell in given column,
the function iterates for all the columns*/
{
     int p=0;
     while(p!=empty_cells())
     {
         p=empty_cells(); 
         for(int i=0;i<9;i++)
         {
             for(int k=1;k<=9;k++)
             {
                 int index_j=0;
                 int num_poss_place=0;
                 for(int j=0;j<9;j++)
                 {        
                     if(sudoku[i][j]==0)
                     {
                        sudoku[i][j]=k;
                        if(!check_conflict(i,j))
                        {
                            num_poss_place++;
                            index_j=j;
                        }
                        sudoku[i][j]=0;
                     }
             }
                 if(num_poss_place==1)
                 {
                       sudoku[i][index_j]=k;
                 }
         
             }
         }
     }
}

void row_hidden_single()
/*Finds the values from 1-9 which can only be filled in one cell in given row,
the function iterates for all the row*/
{
     int p=0;
     while(p!=empty_cells())
     {
         p=empty_cells(); 
         for(int j=0;j<9;j++)
         {
             for(int k=1;k<=9;k++)
             {
                 int index_i=0;
                 int num_poss_place=0;
                 for(int i=0;i<9;i++)
                 {        
                     if(sudoku[i][j]==0)
                     {
                        sudoku[i][j]=k;
                        if(!check_conflict(i,j))
                        {
                            num_poss_place++;
                            index_i=i;
                        }
                        sudoku[i][j]=0;
                     }
             }
                 if(num_poss_place==1)
                 {
                       sudoku[index_i][j]=k;
                 }
         
             }
         }
     }
}

void box_hidden_single()
/*Finds the values from 1-9 which can only be filled in one cell in given 3x3 box,
the function iterates for all the 3x3 box*/
{
    int p=0;
     while(p!=empty_cells())
     {
        p=empty_cells(); 
        for(int boxi=0;boxi<3;boxi++)
        {
            for(int boxj=0;boxj<3;boxj++)
            {
                    for(int k=1;k<=9;k++)
                    {
                            int indj=0;
                            int indi=0;
                            int num_poss_place=0;
                            //int a=boxi*3;
                            for(int a=boxi*3;a<boxi*3+3;a++)
                            {
                                    for(int b=boxj*3;b<boxj*3+3;b++)
                                    {
                                            if(sudoku[a][b]==0)
                                            {
                                                   sudoku[a][b]=k;
                                                   if(!check_conflict(a,b))
                                                   {
                                                       num_poss_place++;
                                                       indi=a;
                                                       indj=b;
                                                   }
                                                   sudoku[a][b]=0;
                                            }
                                    }
                            }
                            if(num_poss_place==1)
                            {
                                 sudoku[indi][indj]=k;
                            }
                    }
            }        
        }
     }
}
    

void hidden_single()
/*running all three components of the hidden_single technique*/
{
    column_hidden_single();
    row_hidden_single();
    box_hidden_single();
}

void singles()
/*running both naked single and hidden single techniques till they fill some cells 
on each itereation*/
{
    int i=1;
    while(i!=empty_cells())
    {
            i=empty_cells();
            naked_single();
            hidden_single();
    }
}
