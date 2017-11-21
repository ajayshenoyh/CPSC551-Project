#include <iostream>

#include<stdio.h>
using namespace std;
void initialize_frame(int *frame, int no_of_frames){
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
    cout<<"Enter number of pages: ";
    cin>>no_of_pages;
    int * page=new int[no_of_pages];
    cout<<"Enter number of frames: ";
    cin>>no_of_frames;
    int * frame=new int[no_of_frames];
    cout<<"Enter reference string:";
    int * time=new int[no_of_frames];
    for(int i = 0; i < no_of_pages; i++)
    {
        cin>>page[i];
    }
    initialize_frame();
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
                    cout<<endl<<"*************Page "<<frame[j]<<" is replaced by "<<page[i]<<"****************";
                    frame[j] = page[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0)
        {
            pos = findLRU(time, no_of_frames);
            counter++;
            pagefault++;
            cout<<endl<<"*************Page "<<frame[pos]<<" is replaced by "<<page[i]<<"****************";
            frame[pos] = page[i];
            time[pos] = counter;
        }

        cout<<endl;

        for(int j = 0; j < no_of_frames; ++j)
        {
            cout<<frame[j]<<"\t";
        }
    }

    cout<<endl<<"Total Page Faults"<<pagefault;



    return 0;
}
