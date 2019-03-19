#ifndef GAME_H
#define GAME_H

int draw(int number);
bool decide();
int throwing(int &score);
int player(int &score);
int computer(int &score);
int game(int& max_score);
int steps(int &first_score, int &second_score, int &max_score, void(*vfirst)(int&), void(*vsecond)(int&));
int throwingPC(int &score);
#endif // !GAME_H