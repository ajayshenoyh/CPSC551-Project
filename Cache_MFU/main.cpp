#include<iostream>
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
    cout<<"*************Page "<<temp<<" is replaced by "<<ele<<"****************"<<endl;
    }

}
bool Search(int ele, int *frame,int *counter)
{
    bool flag=false;
    if(full!=0)
    {
        for(int i=0; i<full; i++)
            if(ele==frame[i])
            {
                flag=1;
                counter[i]++;
                break;
            }
    }
    return flag;
}
int main()
{
    int no_of_pages,no_of_frames,refr[100],pagefault=0,select;
    cout<<"Enter number of pages: ";
    cin>>no_of_pages;
    cout<<"Enter number of frames: ";
    cin>>no_of_frames;
    int * frame=new int[no_of_frames];
int * counter= new int[no_of_frames];
    for(int i=0;i<no_of_frames;i++)
    {
        frame[i]=-1;
        counter[i]=0;
    }
    cout<<"Enter reference string: ";
    for(int i = 0; i < no_of_pages; ++i){
        cin>>refr[i];
    }
    cout<<"Which algorithm?"<<endl<<"MFU:0"<<endl<<"LFU:1"<<endl;
    cin>>select;
    cout<<"The elements in the page"<<endl;
    for(int i=0; i<no_of_pages; i++)
    {
        if(!Search(refr[i],frame,counter))
        {
            page_fault(refr[i],frame,counter,no_of_frames,select);
            pagefault++;
            for(int i=0; i<no_of_frames; i++)
            cout<<frame[i]<<"\t";
            cout<<endl;
        }
    }
    for(int i=0; i<no_of_frames; i++)
        cout<<frame[i]<<"\t";
        cout<<endl;
    cout<<"The number of page faults are "<<pagefault<<endl;
    return 0;
}
