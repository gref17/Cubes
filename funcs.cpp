#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void draw(int number) {
	if (number >= 6) {
		cout << "#######\n";
		cout << "#* * *#\n";
		cout << "#     #\n";
		cout << "#* * *#\n";
		cout << "#######\n";
	}
	else if (number == 5) {
		cout << "#######\n";
		cout << "# * * #\n";
		cout << "#  *  #\n";
		cout << "# * * #\n";
		cout << "#######\n";
	}
	else if (number == 4) {
		cout << "#######\n";
		cout << "# * * #\n";
		cout << "#     #\n";
		cout << "# * * #\n";
		cout << "#######\n";
	}
	else if (number == 3) {
		cout << "#######\n";
		cout << "#  *  #\n";
		cout << "#     #\n";
		cout << "# * * #\n";
		cout << "#######\n";
	}
	else if (number == 2) {
		cout << "#######\n";
		cout << "#     #\n";
		cout << "# * * #\n";
		cout << "#     #\n";
		cout << "#######\n";
	}
	else if (number == 1) {
		cout << "#######\n";
		cout << "#     #\n";
		cout << "#  *  #\n";
		cout << "#     #\n";
		cout << "#######\n";
	}
	else {
		cout << "#######\n";
		cout << "#     #\n";
		cout << "#     #\n";
		cout << "#     #\n";
		cout << "#######\n";
	}
}

bool decide() { // This func should decide who's turn is first, but it doesn't work at all;
	srand(time(NULL));
	int temp[2];
	temp[0] = rand();
	srand(time(NULL));
	temp[1] = rand();
	if (temp[0]/100 > temp[1]/100) return 1;
	else return 0;
}

int throwing(int &score) { // This func returns rand digit to player
	srand(time(NULL) - score);
	srand(rand());
	int random_digit = 1 + rand() % 9;
	score += random_digit;
	return random_digit;
}

int throwingPC(int &score) { // And this to computer
	srand(score + time(NULL));
	srand(rand());
	int random_digit = 1 + rand() % 9;
	score += random_digit;
	return random_digit;
}

void player(int &score) { // Just for design
	cout << "Print anything to throw..." << endl;
	string input;
	cin >> input;
	system("CLS");
	cout << "Player: \n";
	draw(throwing(score));
	cout << "Player score = " << score << endl;
}

void computer(int &score) { // This stuff just for design too
	cout << "Computer: \n";
	draw(throwingPC(score));
	cout << "Computer score = " << score << endl;
}

int steps(int &first_score, int &second_score, int &max_score, void(*vfirst)(int&), void(*vsecond)(int&)) { // This func is need to 
	while (first_score < max_score && second_score < max_score) {
		vfirst(first_score);
		vsecond(second_score);
	}
	if (first_score > second_score) return first_score;
	else if (first_score == second_score) return first_score;
	else return second_score;
}

int game(int& max_score) { // Wrap for all stuff
	int player_score = 0;
	int computer_score = 0;
	if (decide()) {
		steps(player_score, computer_score, max_score, player, computer);
	}
	else {
		steps(computer_score, player_score, max_score, computer, player);
	}
	if (player_score > computer_score) {
		cout << "Player's score = " << player_score << "	Computer's score = " << computer_score << endl;
		cout << "Player wins!\n";
		return player_score;
	}
	else if (player_score < computer_score) {
		cout << "Player's score = " << player_score << "	Computer's score = " << computer_score << endl;
		cout << "Computer wins!\n";
		return computer_score;
	}
	else {
		cout << "Player's score = " << player_score << "	Computer's score = " << computer_score << endl;
		cout << "Draw...\n";
		return player_score;
	}
}