#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;

    int weights[n], values[n];
    cout<<"Enter the weights of the items: ";
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }
    cout<<"Enter the values of the items: ";
    for(int i=0; i<n; i++){
        cin>>values[i];
    }

    float ratio[n];
    for(int i=0; i<n; i++){
        ratio[i] = (float)values[i]/weights[i];
    }

    int cap;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>cap;
    float totalValue = 0.0;
    
    while(cap > 0){
        int idx = -1;
        float maxRatio = -1.0;
        for(int i=0; i<n; i++){
            if(ratio[i] > maxRatio){
                maxRatio = ratio[i];
                idx = i;
            }
        }

        if(idx == -1) break;

        if(weights[idx] <= cap){
            totalValue += values[idx];
            cap -= weights[idx];
        } else {
            totalValue += ratio[idx] * cap;
            cap = 0;
        }
        ratio[idx] = -1.0;
    }
    cout<<"maximum value in Knapsack = "<<totalValue<<endl;
    return 0;
}