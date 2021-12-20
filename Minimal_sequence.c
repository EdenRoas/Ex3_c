# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# define TXT 1024
# define WORD 30
# define TRUE 1
# define FALSE 0



// int Gematria_ot (char ot){
//     if((ot >=97) && (ot <= 122)){
//         return (ot-96);
//     }
//     if ((ot >=65) && (ot <= 90)){
//         return (ot-64);
//     }
//     return 0; 
// } 

// int sum_gematria_word(char word[WORD]){
//     int sum =0;
//     for (int i = 0; i <strlen(word); i++)
//     {
//        sum +=Gematria_ot(word[i]);
//     }
//     return sum;
// }
// void Gematria_Sequences(char word[WORD],char txt[TXT]){
//     int sum_word = sum_gematria_word(word);
//     int sum_find = 0, j, i ,count=0;
//     for (i = 0; i < strlen(txt) ; i++)
//     {
//         sum_find =0;
//         for (j = i; j < strlen(txt); j++)
//         {
//             if (Gematria_ot(txt[i])==0 && sum_find==0){
//                         break;
//                     }
//             sum_find += Gematria_ot(txt[j]);
//             if (sum_find < sum_word){
//                 continue;
//             }
//             else if (sum_find == sum_word){
//                 if(count != 0){
//                     printf("~");
//                 }
//                 for (int k = i; k <= j; k++)
//                 {
//                     printf("%c",txt[k]); 
//                 }
//                 count++; 
//                 sum_find=0;
//                 break;
//             }
//             else 
//             {
//                 sum_find = 0;
//                 break;
//             }
//         }
//     }
//     printf("\n");
    
// }
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

int min_index(int word_index , int reverse_word_index)
{
    while ((word_index != -1) && (reverse_word_index != -1)){
        if (word_index < reverse_word_index)
            return word_index;
        if (reverse_word_index < word_index)
            return reverse_word_index;
    }
    if (word_index == -1)
    {
        return reverse_word_index;
    }
    if (reverse_word_index == -1)
    {
        return word_index;
    }
    else
    {
        return -1;
    }
}
void Atbash_Sequences(char word[WORD],char txt[TXT]){
char copy_word [WORD];
for (int i = 0; i < strlen(word); i++)
{
    copy_word[i] = word[i];
}
//printf("the copy word :%s\n",copy_word);
for (int i = 0; i < strlen(word); i++)
{
        copy_word[i]=replace_letters(copy_word[i]);
}
//printf("the replace word :%s\n",copy_word);
char revers_word [WORD];
int count_prints=0;
for (int i = 0; i < WORD; i++) //copy the replace word to new word
{
    revers_word[i] = copy_word[i];
}
Revers(revers_word); //now we have the reverse_replace_word
//printf("the reverse word :%s\n",revers_word);
for (int i = 0; i < strlen(txt);i++)
{
    int index=count_index_end(copy_word,txt,i);
    int index_reverse =count_index_end(revers_word,txt,i);
   // printf("%d",index_reverse);
   // printf("%d",index);
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
printf("\n");
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
                    for(int i = 0; i < maxWord-1; i++)
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
// int main(){
//     // char c; 
//     // printf("enter char to check the ascii value:");
//     // scanf("%c",&c);
//     // printf("the ascii value of %c is %d",c,c);
//     //char a;
//     char word [WORD] = "abcd";
//     char text [TXT] = "a-bc,dbca-zwxyzabzyxw0dcba~";
//     //char text[TXT] = "I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee – OUCH!! It stung me!!~";
//     //char word [WORD] = "bee";
//     //printf("%s\n",text);
//     //Revers(word);
//     //Gematria_ot('a');
//     //sum_gematria_word(word);
//     Gematria_Sequences(word,strlen(word),text,strlen(text));
//     //printf("\n");    
//     // printf("\n");
//      //replace_letters('!');
//     //printf("the revers test : %s\n",word);
//     //check_contain(text,word);
//     //char word [word] = "a"
//     Atbash_Sequences(word,text);
//     //printf("\n");
//     Anagram_Sequences(word,text);
//     //printf("\n");
//     //char s1 [TXT] = "abababa ba";
//     //char s2 [WORD] = "aba";
//     //printf("%d",a);
//     //int index_end = count_index_end(word,text,17);
//     //printf("%d",index_end);
//     //int index_start = count_index_start(word,text,0);
//    // printf("%d",index_start);
//     //Atbash_Sequences(word ,text);
//     //printf("the size is %d",strlen(word));

//     //Gematria_Sequences(word,text);
//     //printf("the size is %d",strlen(word));
//     //printf("\n");
// }
