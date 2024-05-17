#pragma once
#include<string>
using namespace std;

class nodeClass {
public:
	int position;
	string letter;

	nodeClass(int pos, string l) {
		position = pos;
		letter = l;
	}

	int traverse(int i) {

		//variables used
		int down = position + 6;
		int up = position - 6;
		int back = position + 3;
		int forward = position - 3;
		int left = position - 1;
		int right = position + 1;
		bool front = false;
		bool onLeft = false;
		bool onRight = false;

		if (position == 0 || position == 1 || position == 2 || position == 6 || position == 7 || position == 8 || position == 12 || position == 13 || position == 14) {
			front = true;
		}
		if (position == 2 || position == 5 || position == 8 || position == 11 || position == 14 || position == 17) {
			onRight = true;
		}
		if (position == 0 || position == 3 || position == 6 || position == 9 || position == 12 || position == 15) {
			onLeft = true;
		}
		//previous if statements prevent illegal movements

		bool go = true;
		while (go == true) {
			if (i == 0) { //i is just a number to tell the code what direction to travel
				if (down <= 17 && down >= 0) { //if statements to check if we can travel that direction
					position += 6; //changes position
					break; //ends loop to only change position once just in case
				}
				else { //if it cant move in that direction...
					++i; //add i to move in the next direction
				}
			}
			if (i == 1) {
				if (up <= 17 && up >= 0) {
					position -= 6;
					break;
				}
				else {
					++i;
				}
			}
			if (i == 2) {
				if (back <= 17 && back >= 0 && front == true) {
					position += 3;
					break;
				}
				else {
					++i;
				}
			}
			if (i == 3) {
				if (forward <= 17 && forward >= 0 && front == false) {
					position -= 3;
					break;
				}
				else {
					++i;
				}
			}
			if (i == 4) {
				if (left <= 17 && left >= 0 && onLeft == false) {
					position -= 1;
					break;
				}
				else {
					++i;
				}
			}
			if (i == 5) {
				if (right <= 17 && right >= 0 && onRight == false) {
					position += 1;
					break;
				}
				else {
					++i;
				}
			}
			if (i == 6) { //if it can only move in direction 1 and it starts with direction 5 then we rerun the i's to make sure it always eventually moves in a direction
				i = 0;
			}
		}
		return position;
	}

	void set(int i) {
		position = i;
	}

	int getPos() {
		return position;
	}
};