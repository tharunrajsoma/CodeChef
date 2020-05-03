#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,min=50,max=1;
        cin>>n;
        vector <int> inp;
        for(int i=0;i<n;i++) {
            int val;
            cin>>val;
            inp.push_back(val);
        }
        int count=1;
        for(int i=0;i<n-1;i++) {
            if(inp[i+1]-inp[i]<=2) {
                count++;
            } else {
                if(count<min && count!=0) {
                    min=count;
                }
                if(count>max) {
                    max=count;
                }
                count=1;
            }
        }
        if(count<min && count!=0) {
            min=count;
        }
        if(count>max) {
            max=count;
        }
        cout<<min<<" "<<max<<endl;
        inp.clear();
    }
    return 0;
}
