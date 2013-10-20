#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
int empty_cells();
extern int sudoku[9][9];
void read_file()
/*
reads the incomplete sudoku from the sudoku.txt
*/
{
    int a,b;
    a=b=0;
    string line;
    char ch=48;
    ifstream file ("sudoku.txt");
    if (file.is_open())
    {
           int lines=9;
           int num;
           while (file.good() && lines)
           {     
		 b=0;
                 for(int i=0;i<=8;i++)
                 {
                         file.get(ch);
                         num=ch-48;
                         sudoku[a][b]=num;
                         b++;
                         //file.get(ch);
                 }
		 file.get(ch);//skip carriage return character
		 file.get(ch);//skip newline character
                 a++;
                 lines--;
           }
           file.close();
    }
    else cout << "Unable to open file";
}
void print_sudoku()
/*prints the sudoku*/
{
     int a,b;
     a=0;
     for(int i=0;i<13;i++)
     {b=0;
             for(int j=0;j<13;j++)
             {
                     if(i%4==0 && j%4==0)
                     {cout<<"+ ";}
                     else if(i%4==0 && j%4!=0)
                     {cout<<"- ";}
                     else if(i%4!=0 && j%4==0)
                     {cout<<"| ";}
                     else
                     {
                         sudoku[a][b]==0?(cout<<" "):(cout<<sudoku[a][b]);
                         cout<<" ";
                         b++;
		     }  
             }
             cout<<"\n";
             if(i%4!=0)
             {a++;}        
     }
}
