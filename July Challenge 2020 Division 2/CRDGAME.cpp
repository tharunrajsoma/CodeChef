/*************QUESTION***********
Chef is playing a card game with his friend Morty Smith.

The rules of the game are as follows:

There are two piles of cards, pile A and pile B, each with N cards in it. Pile A belongs to Chef and pile B belongs to Morty.
Each card has one positive integer on it
The ‘power’ of a card is defined as the sum of digits of the integer on that card
The game consists of N rounds
In each round, both players simultaneously draw one card each from the top of their piles and the player who draws the card with higher power wins this round and gets a point. If the powers of both players' cards are equal then they get 1 point each.
The winner of the game is the player who has more points at the end of N rounds. If both players have equal number of points then the game ends in a draw.
The game is now over and Chef has told Morty to find the winner. Unfortunately, this task is too complex for him. Help Morty find the winner.

Input:
First line will contain T, number of testcases.
The first line of each test case will contain N, the number of rounds played.
The ith of the next N lines of each test case will contain Ai and Bi, the number on the card drawn by Chef and Morty respectively in round i.
Output:
For each test case, output two space separated integers on a new line:
Output

0 if Chef wins,
1 if Morty wins,
2 if it is a draw,
followed by the number of points the winner had.
(If it is a draw then output either player’s points).
Constraints
1≤T≤1000
1≤N≤100
1≤Ai,Bi≤109
*/

#include <iostream>
typedef long long int ll;
using namespace std;
ll sumDigits(ll num) {
	ll sumDigits;
	for(sumDigits=0;num>0;sumDigits+=num%10,num=num/10);
	return sumDigits;
}

int main() {
	ll t=0,n=0,aCount=0,bCount=0,a=0,b=0;
	cin>>t;
	while(t--) {
		cin>>n;
		aCount=0,bCount=0;
		while(n--) {
			cin>>a>>b;
			if(sumDigits(a)>sumDigits(b))
				aCount++;
			else if(sumDigits(a)<sumDigits(b))
				bCount++;
			else
				aCount++,bCount++;
		}
		if(aCount>bCount) {
			cout<<0<<" "<<aCount<<endl;
		} else if(aCount<bCount) {
			cout<<1<<" "<<bCount<<endl;
		} else {
			cout<<2<<" "<<aCount<<endl;
		}

	}
	return 0;
}