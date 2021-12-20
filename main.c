#include "Minimal_sequence.h"
#include <stdio.h>
#include <string.h>
#define WORD 30
#define TXT 1024
int main()
{
    char pre_word[31];
    char pre_sentence[1024];
    int letter = 0;  
    int idx = 0; 
    
    while ((letter = getchar()) != ' ' && letter != '\n' && letter != '\t'){
        pre_word[idx] = letter;
        idx++;
        }
    char word[idx];
    int wordSize = idx;
    for (int i = 0; i < idx; i++)
       word[i] = pre_word[i];
    idx = 0; 
    while ((letter = getchar()) != '~'){
        pre_sentence[idx] = letter;
        idx++;
        }
    char sentence[idx];
    for (int i = 0; i < idx; i++)
       sentence[i] = pre_sentence[i];
    printf("Gematria Sequences: ");
    Gematria_Sequences(word, wordSize , sentence, idx);
    printf("Atbash Sequences: ");
    Atbash_Sequences(word, wordSize, sentence, idx);
    printf("Anagram Sequences: ");
    Anagram_Sequences(word, wordSize, sentence, idx);
    return 0;
}