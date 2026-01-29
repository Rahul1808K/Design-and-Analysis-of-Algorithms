#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the number of activities: ";
    cin>>n;

    int start[n], finish[n];
    cout<<"Enter the start times of the activities: ";
    for(int i=0; i<n; i++){
        cin>>start[i];
    }
    cout<<"Enter the finish times of the activities: ";
    for(int i=0; i<n; i++){
        cin>>finish[i];
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(finish[j] > finish[j+1]){
                swap(finish[j], finish[j+1]);
                swap(start[j], start[j+1]);
            }
        }
    }

    int count = 1;
    int lastFinish = finish[0];
    for(int i=1; i<n; i++){
        if(start[i] >= lastFinish){
            count++;
            lastFinish = finish[i];
        }
    }
    cout<<"Maximum number of non-conflicting activities = "<<count<<endl;
    cout<<"Selected activities are: "<<endl;
    cout<<"Activity 1 (Start: "<<start[0]<<", Finish: "<<finish[0]<<")"<<endl;
    lastFinish = finish[0];
    for(int i=1; i<n; i++){
        if(start[i] >= lastFinish){
            cout<<"Activity "<<i+1<<" (Start: "<<start[i]<<", Finish: "<<finish[i]<<")"<<endl;
            lastFinish = finish[i];
        }
    }

    return 0;
}