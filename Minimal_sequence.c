# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# define TXT 1024
# define WORD 30
# define TRUE 1
# define FALSE 0

int check_ot(char ot){
    int value;
        value = ot-'`';
        if (value<0)
            value = ot-'A'+1;
        if(value>26||value<0)
            value = 0;
    return value;
}


void minSequenceGematria(char sentence[], int sentenceSize, int gematria){
    int i,j,k,sum, count=0;
    for(i=0; i<sentenceSize; i++){
        sum = 0;
        if(!check_ot(sentence[i]))
            continue;
        for(j=i; j<sentenceSize; j++){
            sum=sum+check_ot(sentence[j]);
            if(sum>gematria) 
                break;
            if(sum==gematria){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                 for(k=i; k<=j; k++){
                    printf("%c", sentence[k]);
                 }
                break;  
            }
        }
    }
}

void Gematria_Sequences(char word[], int wordSize, char sentence[], int sentenceSize){
    int word_gematria =0;
    for (int i = 0; i < wordSize; i++){
       word_gematria += check_ot(word[i]);
    }
    minSequenceGematria(sentence, sentenceSize, word_gematria);
    printf("\n");
}
char toAtbash(char c){
  if( (c<65||c>122) || (c>90 && c<97) )
    return c;
  if(c<90)
        return 90-(c-'A');
    else
        return 122-(c-'a');    
}

void minSequenceAtbash(char word[], int wordSize, char sentence[], int sentenceSize){
    int i,j,k,count=0;
    for(i=0; i<sentenceSize;i++){
        k=0;
        for (j = i; j <sentenceSize; j++){
            if (sentence[j]==word[k]){
                     k++;
                if (k==wordSize){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                    for (k=i; k<=j; k++)
                       printf("%c", sentence[k]);
                    break;   
                }
            }else{
                if(sentence[j] == ' '){
                    if(i==j)
                        break;
                    else
                        continue;
                }else
                    break;
            }
        }
        k=wordSize-1;
        for (j = i; j < sentenceSize; j++){
            if (sentence[j]==word[k]){
                     k--;                
                if (k==-1){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                    for (k=i; k<=j; k++)
                       printf("%c", sentence[k]);
                    break;   
                }
            }else{
                if(sentence[j] == ' '){
                    if(i==j)
                        break;
                    else
                        continue;
                }else
                    break;
            }
        }
    }
}

void Atbash_Sequences(char word[], int wordSize, char sentence[], int sentenceSize){
    char atbash[wordSize];
    for (int i = 0; i < wordSize; i++){
        atbash[i] = toAtbash(word[i]);
    }
    minSequenceAtbash(atbash, wordSize, sentence, sentenceSize);
    printf("\n");
}



void textCopy(char arry[], char word[], int wordSize){
    for (int i = 0; i < wordSize; i++){
        arry[i] = word[i];
    }
}

void minSequenceAnagram(char word[], int wordSize, char sentence[], int sentenceSize){
    char wordCopy[wordSize];
    int count = 0, areEquals = 1;
    for (int i = 0; i < sentenceSize-wordSize+1; i++){
        if(sentence[i] == ' '){
            continue;
            }
        textCopy(wordCopy, word, wordSize);
        int wscopy = wordSize;
        for (int j = i; j < i+wscopy; j++){
            if(j>sentenceSize)
                break;
            if(sentence[j] == ' '){
                wscopy++;
                continue;
            }
            for (int k = 0; k < wordSize; k++){
                if(wordCopy[k] == sentence[j])
                    wordCopy[k] = '~';
            } 
        }
        for (int q = 0; q < wordSize; q++){
            if(wordCopy[q] != '~')
                areEquals = 0;
        }
        if(areEquals){
            if(count)
                printf("~");
            else
                count++;
            for (int k=i; k<wscopy+i; k++)
                printf("%c", sentence[k]);
        }
        areEquals =1;
    }    
}

void Anagram_Sequences(char word[], int wordSize, char sentence[], int sentenceSize){
    minSequenceAnagram(word, wordSize, sentence, sentenceSize);
    printf("\n");
}