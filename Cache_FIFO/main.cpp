#include <iostream>

#include<stdio.h>
using namespace std;
int main()
{
    int rear_count=0,front,no_of_pages,no_of_frames;
    char demo;
    cout<<"Demo Mode(y/n)"<<endl;
    cin>>demo;
    int demo_refr[22]={7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
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
    cout<<"Enter values of Reference String :";
    for(int i=0; i<no_of_pages; i++)
        cin>>page[i];
    }
    int display[no_of_frames][no_of_pages];
    for(int i=0; i<no_of_frames; i++)
        frame[i]=-1;
    for(int i=0; i<no_of_pages; i++)
    {
        front=0;
        for(int j=0; j<no_of_frames; j++)
        {
            if(page[i]==frame[j])
            {
                front++;
                rear_count--;
            }
        }
        rear_count++;
        if(rear_count<=no_of_frames && front==0)
        {
            frame[i]=page[i];
        }
        else if(front==0)
        {
            frame[(rear_count-1)%no_of_frames]=page[i];
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

    cout<<endl<<"Total Page Faults: "<<rear_count;
    return 0;

}
