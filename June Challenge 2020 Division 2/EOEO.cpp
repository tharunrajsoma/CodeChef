/*********************** QUESTION *********************
As usual, Tom and Jerry are fighting. Tom has strength TS and Jerry has strength JS. You are given TS and your task is to find the number of possible values of JS such that Jerry wins the following game.

The game consists of one or more turns. In each turn:

If both TS and JS are even, their values get divided by 2 and the game proceeds with the next turn.
If both TS and JS are odd, a tie is declared and the game ends.
If TS is even and JS is odd, Tom wins the game.
If TS is odd and JS is even, Jerry wins the game.
Find the number of possible initial values of JS such that 1≤JS≤TS, there is no tie and Jerry wins the game.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer TS.
Output
For each test case, print a single line containing one integer ― the number of values of JS such that Jerry wins the game.

Constraints
1≤T≤105
1≤TS≤1018
Subtasks
Subtask #1 (20 points): T,TS≤100
Subtask #2 (80 points): original constraints

Example Input
2
1
11
Example Output
0
5
*/


#include <iostream>
#include <vector>
using namespace std;

long long int totalPossibilities(long long int tval) {
	if (tval == 1) {
		return 0;
	} else if (tval%2 != 0) {
		return (tval-1)/2;
	} else {
		return totalPossibilities(tval/2);
	}
}

int main() {
	long long int t=0;
	cin>>t;
	while(t--) {
		long long int tval=0;
		cin>>tval;
		cout<<totalPossibilities(tval)<<endl;
	}
	return 0;
}