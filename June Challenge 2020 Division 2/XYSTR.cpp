/************ QUESTION ***********
There are N students standing in a row and numbered 1 through N from left to right. You are given a string S with length N, where for each valid i, the i-th character of S is 'x' if the i-th student is a girl or 'y' if this student is a boy. Students standing next to each other in the row are friends.

The students are asked to form pairs for a dance competition. Each pair must consist of a boy and a girl. Two students can only form a pair if they are friends. Each student can only be part of at most one pair. What is the maximum number of pairs that can be formed?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S.
Output
For each test case, print a single line containing one integer ― the maximum number of pairs.

Constraints
1≤T≤100
1≤N≤105
|S|=N
S contains only characters 'x' and 'y'
the sum of N over all test cases does not exceed 3⋅105
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
xy
xyxxy
yy
Example Output
1
2
0
*/
#include <iostream>
using namespace std;
int getMaxPairs(string str) {
	int maxPairs =0;
	int len = str.length();
	if(len==1) {
		return 0;
	}
	for (int i=0;i<len-1;i++) {
		if(str[i]!=str[i+1]) {
			maxPairs++;
			i++;
		}
	}
	return maxPairs;
}
int main() {
	int t=0;
	cin>>t;
	while(t--) {
		string str="";
		cin >>str;
		cout<<getMaxPairs(str)<<endl;
	}
	return 0;
}