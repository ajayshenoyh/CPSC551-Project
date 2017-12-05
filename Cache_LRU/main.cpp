#include <iostream>

#include<stdio.h>
using namespace std;
void initialize_frame(int *frame, int no_of_frames)
{
    for(int i = 0; i < no_of_frames; i++)
    {
        frame[i] = -1;
    }
}
int time_LRU(int *time, int n)
{
    int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i)
    {
        if(time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int no_of_frames, no_of_pages, counter = 0, flag1, flag2, pos, pagefault = 0;
    int demo_refr[22]={7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
    char demo;
    cout<<"Demo Mode(y/n)"<<endl;
    cin>>demo;

    int * page;
    int * frame;
    if(demo=='y'||demo=='Y'){
        no_of_pages=22;
        no_of_frames=3;
        page=new int[no_of_pages];
        frame=new int[no_of_frames];
        for(int i=0;i<no_of_pages;i++)
            page[i]=demo_refr[i];
    }
    else {
    cout<<"Enter number of pages: ";
    cin>>no_of_pages;
    page=new int[no_of_pages];
    cout<<"Enter number of frames: ";
    cin>>no_of_frames;
    frame=new int[no_of_frames];
    cout<<"Enter reference string:";
    for(int i = 0; i < no_of_pages; i++)
    {
        cin>>page[i];
    }
    }
    int * time=new int[no_of_frames];
    int display[no_of_frames][no_of_pages];
    initialize_frame(frame,no_of_frames);
    for(int i = 0; i < no_of_pages; i++)
    {
        flag1 = flag2 = 0;
        for(int j = 0; j < no_of_frames; j++)
        {
            if(frame[j] == page[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0)
        {
            for(int j = 0; j < no_of_frames; ++j)
            {
                if(frame[j] == -1)
                {
                    counter++;
                    pagefault++;
                    //cout<<endl<<"*************Page "<<frame[j]<<" is replaced by "<<page[i]<<"****************";
                    frame[j] = page[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0)
        {
            pos = time_LRU(time, no_of_frames);
            counter++;
            pagefault++;
            //cout<<endl<<"*************Page "<<frame[pos]<<" is replaced by "<<page[i]<<"****************";
            frame[pos] = page[i];
            time[pos] = counter;
        }

        for(int j=0; j<no_of_frames; j++)
        {
            display[j][i]=frame[j];
        }
    }
    cout<<"Contents are:\n";
    cout<<"==========================================================================================================================================================================================="<<endl;
    cout<<"\t"<<"Page:"<<"\t";
    for(int i=0;i<no_of_pages;i++)
        cout<<i<<"\t";
        cout<<endl;
        cout<<"\t\t";
    for(int i=0;i<no_of_pages;i++)
        cout<<page[i]<<"\t";
    cout<<endl;
    cout<<"==========================================================================================================================================================================================="<<endl;
    for(int i=0;i<no_of_frames;i++){
            cout<<"Frame:"<<i+1<<"||";
        for(int j=0;j<no_of_pages;j++){
            cout<<"\t"<<display[i][j];
        }

        cout<<endl;
    }
    cout<<endl<<"Total Page Faults"<<pagefault;



    return 0;
}
