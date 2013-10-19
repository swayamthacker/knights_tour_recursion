#include <iostream>
#include<stdio.h>

using namespace std;
const int size = 8;
int chess[size][size];
int cango(int,int);
void printarray();



int havenotbeen(int row,int col)
{
    if(row>=0 && row<size && col>=0 && col<size && chess[row][col]==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



void printarray()
{
    int n,m;

    //cout<<"Printing final output"
    //cin>>m;

    for(m=0;m<size;m++)
    {

    for(n=0;n<size;n++)

        cout<<chess[m][n]<<" ";
        cout<<endl;

}
cout<<endl;
}

int solvepuzzle(int row,int col,int count)
{
    int z;
    int found = 0;
    int currentrow,currentcolumn;

    if(count==64)
    {
        printarray();
        found = 1;
        return found;
    }

    int xcoordinate[8] = {2,1,-1,-2,-2,-1,1,2};
    int ycoordinate[8] = {1,2,2,1,-1,-2,-2,-1};

    for(z = 0; z< size;z++)
    {
    currentrow = row + xcoordinate[z];
    currentcolumn = col + ycoordinate[z];

    if(havenotbeen(currentrow,currentcolumn))
    {
        found = 1;
        chess[currentrow][currentcolumn]=count;
        found = solvepuzzle(currentrow,currentcolumn,count+1);


        if(found==1)
        break;
   else
        chess[currentrow][currentcolumn] = -1;
    }
    }
    return found;

}



int main()
{
    for (int x = 0; x < 8; x++)
     {
        for (int y = 0; y < 8; y++)
        {
            chess[x][y] = -1;
        }
     }
    chess[0][0] = 0;
    solvepuzzle(0,0,1);

    return 0;
}

