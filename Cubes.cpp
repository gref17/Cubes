#include "game.h"
#include <iostream>

using namespace std;

int main()
{
	int max_score;
	cout << "Please, type max score: \n";
	cin >> max_score;
	game(max_score);
	system("pause");
    return 0;
}