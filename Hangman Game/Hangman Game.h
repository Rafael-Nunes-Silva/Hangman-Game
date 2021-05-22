#ifndef HANGMANGAME_H
#define HANGMANGAME_H

char GetUserGuess();

void UpdateConsole(int clear);

void GetRandomWord();
void AddWord();

int Won();
int Lost();
int HasGuessed(char* c);

void PrintGallows(int* misses);
void PlayerWon();
void PlayerLose();
#endif