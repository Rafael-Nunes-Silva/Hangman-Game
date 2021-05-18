#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hangman Game.h"

int guesses = 0, misses = 0;
char guessedLetters[26], secretWord[26];

int main() {
    printf("********************************\n");
    printf("* Welcome to the Hangman Game! *\n");
    printf("********************************\n");

    GetRandomWord();

    UpdateConsole(0);

    do {
        char guess = GetUserGuess();
        if (!HasGuessed(guess)) {
            guessedLetters[guesses] = guess;
            guesses++;
        }
        UpdateConsole(1);
    } while (!Won() && !Lost());

    AddWord();

    return 0;
}

char GetUserGuess() {
    char c = ' ';
    printf("Your guess: ");
    scanf(" %c", &c);
    UpperChar(&c);

    int miss = 0;
    for (int i = 0; i < strlen(secretWord); i++) {
        if (c != secretWord[i]) {
            miss = 1;
            continue;
        }
        miss = 0;
        break;
    }
    if (miss==1) misses++;

    return c;
}
void UpperChar(char* c) {
    for (int i = 0; i < strlen(alphabet); i += 2) {
        if (*c == alphabet[i]) {
            *c = alphabet[i + 1];
            break;
        }
    }
}
void LowerChar(char* c) {
    for (int i = 1; i < strlen(alphabet); i += 2) {
        if (*c == alphabet[i]) {
            *c = alphabet[i - 1];
            break;
        }
    }
}

void UpdateConsole(int clear) {
    if (clear) system("cls");

    PrintGallows(&misses);

    printf("Guessed Letters:\n");
    for (int i = 0; i < guesses; i++)
        printf("%c, ", guessedLetters[i]);
    printf("\n\n");

    for (int i = 0; i < strlen(secretWord); i++) {
        int found = 0;
        for (int j = 0; j < guesses; j++) {
            if (guessedLetters[j] == secretWord[i]) {
                found = 1;
                break;
            }
        }

        if (found) printf("%c ", secretWord[i]);
        else printf("_ ");
    }
    printf("\n");
}

void GetRandomWord() {
    FILE* file = fopen("words.txt", "r");
    if (file == 0) {
        printf("File 'words.txt' not found in the main directory");
        return 1;
    }
    int totalWords = 0;
    fscanf(file, "%i", &totalWords);
    for (int i = 0; i <= rand() % totalWords; i++)
        fscanf(file, "%s", &secretWord);
    fclose(file);

    for (int i = 0; i < strlen(secretWord); i++)
        UpperChar(&secretWord[i]);
}
void AddWord() {
    char newWord[26];
    printf("Type in a new word to be added to the game: ");
    scanf(" %s", &newWord);
    if (strlen(newWord) <= 0) return 0;
    for (int i = 0; i < strlen(newWord); i++) {
        if (i == 0) UpperChar(&newWord[i]);
        else LowerChar(&newWord[i]);
    }

    FILE* file = fopen("Words.txt", "r+");
    int totalWords = 0;
    fscanf(file, "%i", &totalWords);
    totalWords++;

    fseek(file, 0, SEEK_SET);
    fprintf(file, "%i", totalWords);

    fseek(file, 0, SEEK_END);
    fprintf(file, "\n%s", newWord);

    fclose(file);
}

int Won() {
    for (int i = 0; i < strlen(secretWord); i++) {
        if (!HasGuessed(secretWord[i]))
            return 0;
    }
    PlayerWon();
    return 1;
}
int Lost() {
    if (misses < 5) return 0;
    printf("\nThe right word was %s\n", secretWord);
    PlayerLose();
    return 1;
}
int HasGuessed(char* c) {
    for (int i = 0; i < guesses; i++) {
        if (c == guessedLetters[i])
            return 1;
    }
    return 0;
}

void PrintGallows(int* misses) {
    switch (*misses) {
    case 1:
        printf(" _________  \n");
        printf(" |/      |  \n");
        printf(" |      (_) \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|___       \n");
        printf("\n\n");
        break;
    case 2:
        printf(" _________  \n");
        printf(" |/      |  \n");
        printf(" |      (_) \n");
        printf(" |      \\|  \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|___       \n");
        printf("\n\n");
        break;
    case 3:
        printf(" _________  \n");
        printf(" |/      |  \n");
        printf(" |      (_) \n");
        printf(" |      \\|/ \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|___       \n");
        printf("\n\n");
        break;
    case 4:
        printf(" _________  \n");
        printf(" |/      |  \n");
        printf(" |      (_) \n");
        printf(" |      \\|/ \n");
        printf(" |       |  \n");
        printf(" |      /   \n");
        printf(" |          \n");
        printf("_|___       \n");
        printf("\n\n");
        break;
    case 5:
        printf(" _________  \n");
        printf(" |/      |  \n");
        printf(" |      (_) \n");
        printf(" |      \\|/ \n");
        printf(" |       |  \n");
        printf(" |      / \\ \n");
        printf(" |          \n");
        printf("_|___       \n");
        printf("\n\n");
        break;
    default:
        printf(" _________  \n");
        printf(" |/      |  \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|___       \n");
        printf("\n\n");
        break;
    }
}
void PlayerWon() {
    printf("\n\n");
    printf("       ___________   \n");
    printf("      '._==_==_=_.'  \n");
    printf("      .-\\:      /-.  \n");
    printf("     | (|:.     |) | \n");
    printf("      '-|:.     |-'  \n");
    printf("        \\::.    /    \n");
    printf("         '::. .'     \n");
    printf("           ) (       \n");
    printf("         _.' '._     \n");
    printf("        '-------'    \n");
    printf("\n\n");
}
void PlayerLose() {
    printf("\n\n");
    printf("    _______________       \n");
    printf("   /               \\     \n");
    printf("  /                 \\    \n");
    printf("//                   \\/\\\n");
    printf("\\|   XXXX     XXXX   | / \n");
    printf(" |   XXXX     XXXX   |/   \n");
    printf(" |   XXX       XXX   |    \n");
    printf(" |                   |    \n");
    printf(" \\__      XXX      __/   \n");
    printf("   |\\     XXX     /|     \n");
    printf("   | |           | |      \n");
    printf("   | I I I I I I I |      \n");
    printf("   |  I I I I I I  |      \n");
    printf("   \\_             _/     \n");
    printf("     \\_         _/       \n");
    printf("       \\_______/         \n");
    printf("\n\n");
}