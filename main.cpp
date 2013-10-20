#include<string.h>
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

void read_file();    
void print_sudoku();
int empty_cells();
void singles();
void get_initial_state();
int run();
int back_tracker();
int naked_single();

int sudoku[9][9]={0};//Initializing sudoku as an empty array

int main()
{
    read_file();
    print_sudoku();//reading and printing empty sudoku
    singles();//using naked_single and Hidden_single to fill as many cells as possible
    if(empty_cells())
    {
       get_initial_state();
       back_tracker();//using back_tracker() only if some cells are vacant
    }
    naked_single();
    print_sudoku();
    return 0;
}
