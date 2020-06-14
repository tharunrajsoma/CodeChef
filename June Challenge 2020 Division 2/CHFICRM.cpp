/*************** QUESTION ****************
Chef owns an icecream shop in Chefland named scoORZ. There are only three types of coins in Chefland: Rs. 5, Rs. 10 and Rs. 15. An icecream costs Rs. 5.

There are N people (numbered 1 through N) standing in a queue to buy icecream from scoORZ. Each person wants to buy exactly one icecream. For each valid i, the i-th person has one coin with value ai. It is only possible for someone to buy an icecream when Chef can give them back their change exactly ― for example, if someone pays with a Rs. 10 coin, Chef needs to have a Rs. 5 coin that he gives to this person as change.

Initially, Chef has no money. He wants to know if he can sell icecream to everyone in the queue, in the given order. Since he is busy eating his own icecream, can you tell him if he can serve all these people?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers a1,a2,…,aN.
Output
For each test case, print a single line containing the string "YES" if all people can be served or "NO" otherwise (without quotes).

Constraints
1≤T≤100
1≤N≤103
ai∈{5,10,15} for each valid i
Subtasks
Subtask #1 (40 points): ai∈{5,10} for each valid i
Subtask #2 (60 points): original constraints

Example Input
3
2
5 10
2
10 5
2
5 15
Example Output
YES
NO
NO
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
string canServePeople(vector<int> inpQueue, int n) {
	string returnValue = "NO";
	unordered_map<int, int> coinsCountMap;
	if(n<1) {
		return "NO";
	}

	if(inpQueue[0]!=5) {
		return "NO";
	}
	coinsCountMap[5]++;

	for(int i=1;i<n;i++) {
		if(inpQueue[i]-5 == 0) {
			coinsCountMap[5]++;
		} else if(inpQueue[i]-5 == 5) {
			if(--coinsCountMap[5] < 0) {
				return "NO";
			}
			coinsCountMap[10]++;
		} else {
			if(coinsCountMap[10]>0) {
				coinsCountMap[10]--;
			} else if(coinsCountMap[5] > 1) {
				coinsCountMap[5] = coinsCountMap[5]-2;
			} else {
				return "NO";
			}
			coinsCountMap[15]++;
		}

	}

	return "YES";
}
int main() {
	int t=0;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector <int> v(n,0);
		for(int i=0;i<n;i++) {
			cin>>v[i];
		}
		cout<<canServePeople(v, n)<<endl;
	}
	return 0;
}