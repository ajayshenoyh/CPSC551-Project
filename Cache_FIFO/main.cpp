#include <iostream>

#include<stdio.h>
using namespace std;
int main()
{
    int rear_count=0,j,front,no_of_pages,no_of_frames;
        cout<<"Enter number of pages: ";
    cin>>no_of_pages;
    int * page=new int[no_of_pages];
    cout<<"Enter number of frames: ";
    cin>>no_of_frames;
    int * frame=new int[no_of_frames];
    cout<<"Enter values of Reference String :";
    for(int i=0; i<no_of_pages; i++)
        cin>>page[i];
    for(int i=0; i<no_of_frames; i++)
        frame[i]=-1;
    cout<<"The frame content are:";
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
        cout<<endl;
        for(int j=0; j<no_of_frames; j++)
        {
            cout<<frame[j]<<"\t";
        }

    }
    cout<<endl<<"Total Page Faults"<<rear_count;
    return 0;

}
