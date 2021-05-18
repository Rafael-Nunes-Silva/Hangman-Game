#ifndef HANGMANGAME_H
#define HANGMANGAME_H
const char alphabet[] = {
    'a', 'A', 'b', 'B', 'c', 'C',
    'd', 'D', 'e', 'E', 'f', 'F',
    'g', 'G', 'h', 'H', 'i', 'I',
    'j', 'J', 'k', 'K', 'l', 'L',
    'm', 'M', 'n', 'N', 'o', 'O',
    'p', 'P', 'q', 'Q', 'r', 'R',
    's', 'S', 't', 'T', 'u', 'U',
    'v', 'V', 'w', 'W', 'x', 'X',
    'y', 'Y', 'z', 'Z', 'ç', 'Ç'
};

char GetUserGuess();
void UpperChar(char* c);
void LowerChar(char* c);

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