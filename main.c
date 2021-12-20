#include "Minimal_sequence.h"
#include <stdio.h>
#include <string.h>
#define word 30
#define txt 1024
int main()
{
    char input_word[word];
    char input_text[txt];
    
      
    scanf("%[^\n\t' ']",input_word); 
    scanf("%[^~]",input_text);
    strcat(input_text,"~");
    Gematria_Sequences(input_word,strlen(input_word),input_text,strlen(input_text));
    Atbash_Sequences(input_word,input_text);
    Anagram_Sequences(input_word,input_text);
    return 0;
}