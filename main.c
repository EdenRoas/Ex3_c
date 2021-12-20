#include "Minimal_sequence.h"
#include <stdio.h>
#include <string.h>
#define WORD 30
#define TXT 1024
int main()
{
    char input_word[WORD];
    char input_text[TXT];
    
      
    scanf("%[^\n\t' ']",input_word); 
    scanf("%[^~]",input_text);
    strcat(input_text,"~");
    printf("Gematria Sequences: ");
    Gematria_Sequences(input_word,strlen(input_word),input_text,strlen(input_text));
    printf("Atbash Sequences: ");
    Atbash_Sequences(input_word,input_text);
    printf("Anagram Sequences: ");
    Anagram_Sequences(input_word,strlen(input_word),input_text,strlen(input_text));
    return 0;
}