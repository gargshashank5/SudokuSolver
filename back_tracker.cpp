bool check_conflict(int i,int j);
extern int sudoku[9][9];
int initial_state[9][9]={0};//initial_state[i][j] =0 implies that sudoku[i][j] was empty initially and initial_state[i][j]=1 otherwise
int curcell[2]={0};//curcell[0]=i, curcell[1]=j
int firstempty[2]={0};//coordinates of first empty cell
int lastempty[2]={0};//coordinates of last empty cell 

void get_initial_state()
/*if the cell is empty it marks initial_state as 0 else 1*/
{
     for(int i=0;i<=8;i++)
     {
         for(int j=0;j<=8;j++)
         {
             if(sudoku[i][j]!=0)
             {
                initial_state[i][j]=1;
             }
         }
     }
     
}

void prevcell()
/*gives coordinates of previous cell*/
{
     if(curcell[1]!=0)
          curcell[1]--;
     else
     {
         curcell[0]--;
         curcell[1]=8;
     }
}     

void next_cell()
/*gives coordinates of next cell*/
{
     if(curcell[1]!=8)
          curcell[1]++;
     else
     {
         curcell[0]++;
         curcell[1]=0;
     }
}


void find_first_empty()
/*gives coordinates of first empty cell*/
{
     int p=81;
     curcell[0]=0;
     curcell[1]=0;
     while(p)
     {
             if(sudoku[curcell[0]][curcell[1]]==0)
             {
                  firstempty[0]=curcell[0];
                  firstempty[1]=curcell[1];
                  break;
             }
             p--;
             next_cell();
     }
}

void find_last_empty()
/*gives coordinates of last empty cell*/
{
     curcell[0]=8;
     curcell[1]=8;
     int p=81;
     while(p)
     {
             if(sudoku[curcell[0]][curcell[1]]==0)
             {
                  lastempty[0]=curcell[0];
                  lastempty[1]=curcell[1];
                  break;
             }
             p--;
             prevcell();
     }
     curcell[0]=0;
     curcell[1]=0;
}

int next_empty_cell()
/*gives coordinates of next empty cell*/
{
     while(1)
     {
         next_cell();
         if(initial_state[curcell[0]][curcell[1]]==0) 
         {
              return 0;
         }
         
     }
}
     
int prev_empty_cell()
/*gives coordinates of previous empty cell*/
{
     while(1)
     {
         prevcell();
         if(initial_state[curcell[0]][curcell[1]]==0)
         {
              return 0;
         }
     }
}

int ffnc(int curnum)
/*ffnc=find first non conflictor, finds first value that does not conflicts with any 
cell in sudoku*/
{
    int p=-1;
    for(int k=curnum+1;k<=9;k++)
    {
            sudoku[curcell[0]][curcell[1]]=k;
            if(!check_conflict(curcell[0],curcell[1]))
            {
               p=k;
               break;
            }
    }
    sudoku[curcell[0]][curcell[1]]=curnum;
    return p;
    
}

int run()
/*sets up first and last empty for running backtracking function*/
{
    find_first_empty();
    find_last_empty();
    curcell[0]=firstempty[0];
    curcell[1]=firstempty[1];
    return 0;
}

int back_tracker()
/*filling spaces using back_tracking*/
{
     run();
     curcell[0]=firstempty[0];
     curcell[1]=firstempty[1];
     int a=2;
     while(a)
     {
             if(ffnc(sudoku[curcell[0]][curcell[1]])==-1)
             {
                        {
                            prev_empty_cell();
                            while(ffnc(sudoku[curcell[0]][curcell[1]])==-1)
                            {
                                sudoku[curcell[0]][curcell[1]]=0;                               
                                prev_empty_cell();
                            }
                            sudoku[curcell[0]][curcell[1]]=ffnc(sudoku[curcell[0]][curcell[1]]);
                            next_empty_cell();
                            
                        }
             }
             else
             {
                 sudoku[curcell[0]][curcell[1]]=ffnc(sudoku[curcell[0]][curcell[1]]);
                 next_empty_cell();
                 if(curcell[0]==lastempty[0] && curcell[1]==lastempty[1])
                      return 1;
             }
     }
}
