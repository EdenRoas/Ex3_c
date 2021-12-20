#include "Minimal_sequence.h"
#include <stdio.h>
#include <string.h>
# define TXT 1024
# define WORD 30
int main()
{
    char word[WORD];
    for (int i = 0; i < WORD; i++) {
        if (word[i - 1] == '\n' || word[i - 1] == '\t' || word[i - 1] == ' ') {
            word[i] = '\0';
            break;
        }
        scanf("%c", &word[i]);
    }
    char text[TXT];
    for (int i = 0; i < TXT; i++) {
        if (text[i - 1] == '~') {
            text[i] = '\0';
            break;
        }
        scanf("%c", &text[i]);
    }
    printf("Gematria Sequences: ");
    Gematria_Sequences(word,strlen(word),text,strlen(text));
    printf("Atbash Sequences: ");
    Atbash_Sequences(word,text);
    printf("Anagram Sequences: ");
    Anagram_Sequences(word,text);
    return 0;
}
