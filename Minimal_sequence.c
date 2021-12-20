# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# define TXT 1024
# define WORD 30
# define TRUE 1
# define FALSE 0



int Gematria_ot (char ot){
    if((ot >=97) && (ot <= 122)){
        return (ot-96);
    }
    if ((ot >=65) && (ot <= 90)){
        return (ot-64);
    }
    return 0; 
} 

int sum_gematria_word(char word[WORD]){
    int sum =0;
    for (int i = 0; i <strlen(word); i++)
    {
       sum +=Gematria_ot(word[i]);
    }
    return sum;
}
void Gematria_Sequences(char word[WORD],char txt[TXT]){
    int sum_word = sum_gematria_word(word);
    int sum_find = 0, j, i ,count=0;
    for (i = 0; i < strlen(txt) ; i++)
    {
        sum_find =0;
        for (j = i; j < strlen(txt); j++)
        {
            if (Gematria_ot(txt[i])==0 && sum_find==0){
                        break;
                    }
            sum_find += Gematria_ot(txt[j]);
            if (sum_find < sum_word){
                continue;
            }
            else if (sum_find == sum_word){
                if(count != 0){
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c",txt[k]); 
                }
                count++; 
                sum_find=0;
                break;
            }
            else 
            {
                sum_find = 0;
                break;
            }
        }
    }
    printf("\n");
    
}
char replace_letters(char ot){
    int count_ot =0;
     if ((ot >=65) && (ot <= 90)){
         count_ot = ot - 65;
         ot = (90 - count_ot);
         return ot ;
     }
     if((ot >=97) && (ot <= 122)){
         count_ot = ot - 97;
         ot = (122-count_ot);
         return ot;
     }
     else {
        return ot;
     }
     
}
void Revers(char word[WORD])
{
  int n = strlen(word);
  for (int i = 0; i < n / 2; i++)
  {
    char ch = word[i];
    word[i] = word[n - i - 1];
    word[n - i - 1] = ch;
  }
}
int count_index_end(char word[], char text[],int n) {
int count_ot=0 ;
    for (int i=n; i<strlen(text); i++)
    {
        if (word[count_ot] == text[i])
        { 
            if(count_ot == strlen(word)-1)
            {
            return i;
            }
        count_ot++;
        continue;
        }  
        if(text[i]==32)
        {
        continue;
        }
        if (word[count_ot] != text[i]){
            return -1;}
    }
    return -1;
}

int min_index(int word_index , int reverse_word_index){
    while ((word_index != -1) && (reverse_word_index != -1)){
        if (word_index < reverse_word_index)
            return word_index;
        if (reverse_word_index < word_index)
            return reverse_word_index;
    }
    if (word_index == -1)
        return reverse_word_index;
    if (reverse_word_index == -1)
        return word_index;
    }
void Atbash_Sequences(char word[WORD],char txt[TXT]){
for (int i = 0; i < strlen(word); i++)
{
        word[i]=replace_letters(word[i]);
} 
char revers_word [WORD];
int count_prints=0;
for (int i = 0; i < WORD; i++) //copy the replace word to knew word
{
    revers_word[i] = word[i];
}
Revers(revers_word); //now we have the reverse_replace_word
for (int i = 0; i < strlen(txt);i++)
{
    int index=count_index_end(word,txt,i);
    int index_reverse =count_index_end(revers_word,txt,i);
    int find_min = min_index(index , index_reverse);
    if (find_min != -1)
    {
        if(count_prints != 0)
            printf("~");
        for (int j = i; j <= find_min; j++)
        {   
            printf("%c",txt[j]);
        }
        count_prints++;
    }
    
}   
}

void Anagram_Sequences(char word[WORD],char txt[TXT])
{
    int flag = TRUE, indexWord = 0, indexTxt = 0, indexAnagram = 0, maxWord = 2 * strlen(word), printCount = 0;
    int isChecked[strlen(word)];

    for(int i = 0; i < strlen(word); i++)
    {
        isChecked[i] = FALSE;
    }
    char anagram[maxWord];
    for(int i = 0; i < strlen(txt); i++)
    {
        indexTxt = i;
        while(indexTxt < strlen(txt))
        {
            if(txt[indexTxt] == 32)
            {
                int isSomeCheck = FALSE;
                for(int i = 0; i < strlen(word); i++)
                {
                    if(isChecked[i] != FALSE)
                    {
                        isSomeCheck = TRUE;
                        break;
                    }
                }
                if(isSomeCheck == TRUE)
                {
                    anagram[indexAnagram] = txt[indexTxt];
                    indexAnagram++;
                    indexTxt++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            
            while((indexWord < strlen(word)) && (flag))
            {
                if((txt[indexTxt] == word[indexWord]) && (isChecked[indexWord] != TRUE))
                {
                    anagram[indexAnagram] = txt[indexTxt];
                    indexAnagram++;
                    isChecked[indexWord] = 1;
                    flag = FALSE;
                    break;
                }
                else
                {
                    indexWord++;
                } 
            }
        
            if(!flag)
            {
                flag = TRUE;
                indexTxt++;
                indexWord = 0;
            }
        
            else
            {
                int isAllChecked = TRUE;
                for(int i = 0; i < strlen(word); i++)
                {
                    if(isChecked[i] != 1)
                    {
                        isAllChecked = FALSE;
                    }
                }
                if(isAllChecked == TRUE)
                {
                    indexAnagram = 0;
                    if(printCount > 0)
                    {
                        printf("~");
                    }
                    for(int i = 0; i < maxWord; i++)
                    {
                        printf("%c", anagram[i]);
                    }
                    for(int i = 0; i < strlen(word); i++)
                    {
                        isChecked[i] = FALSE;
                    }
                    printCount++;
                    flag = TRUE;
                    indexWord = 0;
                    break;
                } 
                else
                {
                    for(int i = 0; i < strlen(word); i++)
                    {
                        isChecked[i] = FALSE;
                    }
                    indexAnagram = 0;
                    flag = TRUE;
                    indexWord = 0;
                    break;
                }
            }
        }
    } 
}

