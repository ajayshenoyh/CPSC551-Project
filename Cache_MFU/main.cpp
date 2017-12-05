#include<iostream>
#include<windows.h>
using namespace std;
int full=0;
int find_replacement(int no_of_frames, int *counter,int select)
{
    int i,rep;
    rep=0;
    for(i=0; i<no_of_frames; i++)
    if(select==0){
        if(counter[rep]<counter[i])
        rep=i;
    }
    else if(select==1){
        if(counter[rep]>counter[i])
        rep=i;
    }

    return rep;
}
int page_fault(int ele, int *frame, int *counter, int no_of_frames,int select)
{
    if(full!=no_of_frames)
    {
        counter[full]++;
        frame[full++]=ele;
    }
    else
    {
    int temp,rep;
    rep=find_replacement(no_of_frames,counter,select);
    temp=frame[rep];
    frame[rep]=ele;
    counter[rep]=1;
    //cout<<"*************Page "<<temp<<" is replaced by "<<ele<<"****************"<<endl;
    }

}
int Search(int ele, int *frame,int *counter)
{
    bool flag=false;
    int ret=-1;
    if(full!=0)
    {
        for(int i=0; i<full; i++)
            if(ele==frame[i])
            {
                flag=1;
                ret=i;
                counter[i]++;
                break;
            }
    }
    return ret;
}
int main()
{

    int no_of_pages,no_of_frames,refr[100],pagefault=0,select;
    char demo;
    int demo_refr[22]={7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
    cout<<"Demo Mode(y/n)"<<endl;
    cin>>demo;
    if(demo=='y'||demo=='Y'){
        no_of_pages=22;
        no_of_frames=3;
        for(int i=0;i<no_of_pages;i++)
            refr[i]=demo_refr[i];
    }
    else {
    cout<<"Enter number of pages: ";
    cin>>no_of_pages;
    cout<<"Enter number of frames: ";
    cin>>no_of_frames;
    cout<<"Enter reference string: ";
    for(int i = 0; i < no_of_pages; ++i){
        cin>>refr[i];
    }
    }
    int * frame=new int[no_of_frames];
int * counter= new int[no_of_frames];

int display[no_of_frames][no_of_pages];
    for(int i=0;i<no_of_frames;i++)
    {
        frame[i]=-1;
        counter[i]=0;
    }

    //cout<<"Which algorithm?"<<endl<<"MFU:0"<<endl<<"LFU:1"<<endl;
    select=0;
int ret;

    cout<<"The elements in the page"<<endl;
    for(int i=0; i<no_of_pages; i++)
    {
        ret=Search(refr[i],frame,counter);
        if(ret==-1)
        {
            page_fault(refr[i],frame,counter,no_of_frames,select);
            pagefault++;
            for(int j=0; j<no_of_frames; j++)
            display[j][i]=frame[j];
        }
        else
        {
            //for(int j=i;j<no_of_pages;j++)
            for(int k=0;k<no_of_frames;k++)
                display[k][i]=display[k][i-1];
        }

    }
    cout<<"Contents are:\n";
    cout<<"======================================================================================================================================================"<<endl;
    cout<<"\t"<<"Page:"<<"\t";
    for(int i=0;i<no_of_pages;i++)
        cout<<i<<"\t";
        cout<<endl;
        cout<<"\t\t";
    for(int i=0;i<no_of_pages;i++)
        cout<<refr[i]<<"\t";
    cout<<endl;
    cout<<"======================================================================================================================================================"<<endl;
    for(int i=0;i<no_of_frames;i++){
            cout<<"Frame:"<<i+1<<"||";
        for(int j=0;j<no_of_pages;j++){
            cout<<"\t"<<display[i][j];
        }

        cout<<endl;
    }
    cout<<"The number of page faults are "<<pagefault<<endl;
    return 0;
}
