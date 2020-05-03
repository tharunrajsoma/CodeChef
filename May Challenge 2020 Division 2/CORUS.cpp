#include <iostream>
#include <map>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int size=0,n=0;
        string str = "";
        cin>>size>>n;
        cin>>str;
        map<char,int> chCount;
        map<char,int>::iterator it;
        int strSize = str.size();
        for(int i=0;i<strSize;i++) {
            it = chCount.find(str[i]);
            if(it!=chCount.end()) {
                chCount[str[i]] = ++it->second;
            } else {
                chCount[str[i]] = 1;
            }
        }
        
        while(n--) {
            int cSize;
            cin>>cSize;
            int min=0;
            for(it = chCount.begin();it!=chCount.end();it++) {
                int temp;
                temp = it->second - cSize;
                if(temp>0) {
                    min+=temp;
                }
            }
            cout<<min<<endl;
        }
        chCount.clear();
    }
    return 0;
}