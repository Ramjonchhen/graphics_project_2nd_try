#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

// windows
int win1,win2;

// global variables
int values[9];
int no_of_elements;
    int xBlockStarting[9];
    int yBlockStarting[9];
    int xBlockEnd[9];
    int yBlockEnd[9];
    int yBase=600;
    int color[9]={0,1,2,3,4,5,6,9,10};
    char value[2];
    int widthOfBlocks=40;
    int heightOfOneBlock=20;
    int spacingBetweenBlocks=10;

    // displaying the array status
    int array_status_x;
    int array_status_y=80;
    // for displaying nubmers
    char array_text[2];
    // for displaying the count startus
    char count_status[9];
    // displaying the count variable
    int count_iteration=0;

void display_blocks(int values[])
{
    cleardevice();
    setcurrentwindow(win1);
    xBlockStarting[0]=100;

     for(int i=0; i<no_of_elements; i++)
    {
        yBlockEnd[i]=yBase;
            int k=i;
        yBlockStarting[i]=yBase-(heightOfOneBlock*values[i]);
        xBlockEnd[i]=xBlockStarting[i]+widthOfBlocks;
        rectangle(xBlockStarting[i],yBlockStarting[i],xBlockEnd[i],yBlockEnd[i]);
        setfillstyle(1,color[i]);
            floodfill(xBlockStarting[i]+10,yBlockEnd[i]-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            sprintf(value,"%d",values[i]);
            outtextxy(xBlockStarting[i]+15,yBlockEnd[i]-20,value);
        xBlockStarting[k+1]=xBlockEnd[i]+spacingBetweenBlocks;
    }

}

void swap_blocks(int x,int y)
{
    setcurrentwindow(win1);
    int move_block[9];
    cleardevice();
    for (int inc=0; inc<9; inc++)
    {
        int temp=inc;
        if (temp==x || temp==y)
        {
            move_block[inc]=1;
        }

        else{
            move_block[inc]=0;
        }
    }
    // loop for animating that swapping two blocks is moving
  for(int k=0; k<=15; k++)
  {
      cleardevice();
      for(int i=0; i<no_of_elements; i++)
    {
        yBlockEnd[i]=yBase-move_block[i]*3*k;
            int j=i;
        yBlockStarting[i]=yBlockEnd[i]-(heightOfOneBlock*values[i]);
        xBlockEnd[i]=xBlockStarting[i]+widthOfBlocks;
        rectangle(xBlockStarting[i],yBlockStarting[i],xBlockEnd[i],yBlockEnd[i]);
        setfillstyle(1,color[i]);
            floodfill(xBlockStarting[i]+10,yBlockEnd[i]-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            sprintf(value,"%d",values[i]);
            outtextxy(xBlockStarting[i]+15,yBlockEnd[i]-20-move_block[i]*i,value);
        xBlockStarting[j+1]=xBlockEnd[i]+spacingBetweenBlocks;
    }

    // displaying the balance variable
   line(xBlockStarting[x],yBase+5,xBlockStarting[x],yBase+20);
            line(xBlockEnd[x],yBase+5,xBlockEnd[x],yBase+20);
            line( ((xBlockStarting[x]+xBlockEnd[x])/2),yBase+20,((xBlockStarting[x]+xBlockEnd[x])/2),yBase+35 );
            line(xBlockEnd[x],yBase+20,xBlockStarting[x],yBase+20);

            // drawing the 2nd Block traxu
            line(xBlockStarting[x+1],yBase+5,xBlockStarting[x+1],yBase+20);
            line(xBlockEnd[x+1],yBase+5,xBlockEnd[x+1],yBase+20);
            line( ((xBlockStarting[x+1]+xBlockEnd[x+1])/2),yBase+20,((xBlockStarting[x+1]+xBlockEnd[x+1])/2),yBase+35 );
            line(xBlockEnd[x+1],yBase+20,xBlockStarting[x+1],yBase+20);

            line(((xBlockStarting[x+1]+xBlockEnd[x+1])/2),yBase+35,((xBlockStarting[x]+xBlockEnd[x])/2),yBase+35);

    delay(150);
  }
}

void show_array_status(int x)
{
    setcurrentwindow(win2);


    if(array_status_y<getmaxheight())
    {
       array_status_x=100;
    }

    else
    {
        array_status_x+=300;
        array_status_y=80;
    }

    array_status_y;
    sprintf(count_status,"Count %d:",x);
    outtextxy(array_status_x,array_status_y,count_status);
    array_status_x=array_status_x+90;
    for(int i=0; i<no_of_elements; i++)
    {
        rectangle(array_status_x,array_status_y,array_status_x+20,array_status_y+22);
        sprintf(array_text,"%d",values[i]);
            outtextxy(array_status_x+5,array_status_y+5,array_text);
        array_status_x+=20;

    }
    array_status_y=array_status_y+40;
}

int main()
{
    int win1;
    win1=initwindow(1000,1000,"graphics");
    win2=initwindow(1000,1000,"Array Status");
    setcurrentwindow(win1);
    cout<<"Enter the no of elements in the array: ";
    cin>>no_of_elements;
    for(int i=0; i<no_of_elements; i++)
    {
        cin>>values[i];
    }
    display_blocks(values);

    show_array_status(count_iteration);

    delay(600);
    // performing the bubble sort
    int temp;
    for(int i=0; i<no_of_elements; i++)
    {
        for(int j=0; j<no_of_elements-1-i; j++)
        {
            count_iteration++;

           if(values[j]>values[j+1])
           {
               show_array_status(count_iteration);
               // swapping the values of the array

               swap_blocks(j,j+1);
               temp=values[j];
               values[j]=values[j+1];
               values[j+1]=temp;
               // swapping the values of the color to maintain the color consistency
               int temp_color;
               temp_color=color[j];
               color[j]=color[j+1];
               color[j+1]=temp_color;
               display_blocks(values);
           }
           // if nothing to swap displaying the message
        else{
               display_blocks(values);
     // drawing the 1st block traju
            // drawing the line from the starting of 1st block to some narrow
            line(xBlockStarting[j],yBase+5,xBlockStarting[j],yBase+20);
            line(xBlockEnd[j],yBase+5,xBlockEnd[j],yBase+20);
            line( ((xBlockStarting[j]+xBlockEnd[j])/2),yBase+20,((xBlockStarting[j]+xBlockEnd[j])/2),yBase+35 );
            line(xBlockEnd[j],yBase+20,xBlockStarting[j],yBase+20);

            // drawing the 2nd Block traju
            line(xBlockStarting[j+1],yBase+5,xBlockStarting[j+1],yBase+20);
            line(xBlockEnd[j+1],yBase+5,xBlockEnd[j+1],yBase+20);
            line( ((xBlockStarting[j+1]+xBlockEnd[j+1])/2),yBase+20,((xBlockStarting[j+1]+xBlockEnd[j+1])/2),yBase+35 );
            line(xBlockEnd[j+1],yBase+20,xBlockStarting[j+1],yBase+20);

            line(((xBlockStarting[j+1]+xBlockEnd[j+1])/2),yBase+35,((xBlockStarting[j]+xBlockEnd[j])/2),yBase+35);
            outtextxy((xBlockStarting[j+1]+xBlockEnd[j+1])/2,yBase+40,"Can't swap");
            delay(2000);
            show_array_status(count_iteration);

        }
        }

        // adding the grey color to the sorted blocks
        color[no_of_elements-i-1]=8;
           display_blocks(values);
           show_array_status(count_iteration);
           show_array_status(count_iteration);
    }



getch();
    return 0;
}
