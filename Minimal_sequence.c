# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define TXT 1024
# define WORD 30


int Gematria_ot (char ot){
    if((ot >=97) && (ot <= 122)){
        //printf ("the gematria of %c is %d\n",ot,(ot-96));
        return (ot-96);
    }
    if ((ot >=65) && (ot <= 90)){
       // printf ("the gematria of %c is %d\n",ot,(ot-64));
        return (ot-64);
    }
    //printf ("the gematria of %c is %d\n",ot,0);
    return 0; 
} 

int sum_gematria_word(char word[WORD]){
    int sum =0;
    for (int i = 0; i <strlen(word); i++)
    {
       sum +=Gematria_ot(word[i]);
    }
   // printf ("the sum of %s is %d",word,sum);
    return sum;
}
void Gematria_Sequences(char word[WORD],char txt[TXT]){
    int sum_word = sum_gematria_word(word);
    //printf("sum word is %d\n",sum_word);
    int sum_find = 0, j, i ,count=0;
    for (i = 0; i < strlen(txt) ; i++)
    {
      //  printf("%d\n",i);
        for (j = i; j < strlen(txt); j++)
        {
            if (Gematria_ot(txt[i])==0 && sum_find==0){
                        break;
                    }
            //printf("%d\n",j);
            //printf("the char is %c and value is %d\n",txt[j],Gematria_ot(txt[j]));
            sum_find += Gematria_ot(txt[j]);
            //printf("total sum: %d",sum_find);
            if (sum_find < sum_word){
                continue;
                //printf("sum is smaller: %d\n",sum_find);
            }
            else if (sum_find == sum_word){
                if(count != 0){
                    printf("~");
                }
                //printf("Equal\n");
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
    
}
char replace_letters(char ot){
    int count_ot =0;
     if ((ot >=65) && (ot <= 90)){
         count_ot = ot - 65;
         ot = (90 - count_ot);
         //printf("%c\n",ot);
         return ot ;
     }
     if((ot >=97) && (ot <= 122)){
         count_ot = ot - 97;
         ot = (122-count_ot);
         //printf ("%c\n",ot);
         return ot;
     }
     else {
        //printf ("%c\n",ot);
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
//int n = strlen(TXT);
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
    //printf("%d ,%d",word_index,reverse_word_index);
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
//printf("the word is:%s\n",word);
for (int i = 0; i < strlen(word); i++)
{
        word[i]=replace_letters(word[i]);
} 
//printf("the replace word is: %s\n",word);
char revers_word [WORD];
int count_prints=0;
for (int i = 0; i < WORD; i++) //copy the replace word to knew word
{
    revers_word[i] = word[i];
}
//printf("the copy word is: %s\n",revers_word);
Revers(revers_word); //now we have the reverse_replace_word
//printf("the Reverse word is: %s\n",revers_word);
for (int i = 0; i < strlen(txt);i++)
{
    int index=count_index_end(word,txt,i);
    //printf("%d\n",index);
    int index_reverse =count_index_end(revers_word,txt,i);
    //printf("%d\n",index_reverse);
    int find_min = min_index(index , index_reverse);
    //printf("test %d\n",find_min);
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

// void Anagram_Sequences(char word[WORD],char txt[TXT])
// {
//     int flag = TRUE, indexWord = 0, indexTxt = 0, indexAnagram = 0, maxWord = 2 * WORD;
//     int isChecked[WORD] = {FALSE};
//     // char* anagramPtr = (char*)malloc(maxWord * sizeof(char));

//     // // if memory cannot be allocated
//     // if(anagramPtr == null)
//     // {
        
//     // }
//     char anagram[maxWord];
//     while (indexTxt < TXT)
//     {
//         if(txt[indexTxt] == " ")
//         {
//             anagram[indexAnagram++] = txt[indexTxt];
//             indexTxt++;
//             continue;
//         }
//         while((indexWord < WORD) && (flag))
//        {
//           if((txt[indexTxt] == word[indexWord]) && (isChecked[indexWord] != 1))
//           {
//               anagram[indexAnagram++] = txt[indexTxt];
//               isChecked[indexWord] = 1;
//               indexWord = 0;
//               flag = FALSE;
//           }
//           indexWord++;
//        }

//        if(!flag)
//        {
//            indexTxt++;
//        }
//        else
//        {
//             int isAllChecked = TRUE;
//             for(int i = 0; i < WORD; i++)
//             {
//                 if(isChecked[i] != 1)
//                 {
//                    isAllChecked = FALSE;
//                 }
//             }
//             if(isAllChecked == TRUE)
//             {
//                 for(int i = 0; i < maxWord; i++)
//                 {
//                     printf("%c", anagram[i]);
//                 }
//                 indexTxt++;
//                 for(int i = 0; i < WORD; i++)
//                 {
//                     isChecked[i] = FALSE;
//                 }
//             } 
//             else
//             {
//                 indexTxt++;
//                  for(int i = 0; i < WORD; i++)
//                 {
//                    isChecked[i] = FALSE;
//                 }
//             }
//        }
       
//     }
// }

int main(){
    // char c; 
    // printf("enter char to check the ascii value:");
    // scanf("%c",&c);
    // printf("the ascii value of %c is %d",c,c);
    //char a;
    char text [TXT] = "a-bc,dbca-zwxyzabzyxw0dcba~";
    char word [WORD] = "abcd";
    //printf("%s\n",text);
    //Revers(word);
    //Gematria_ot('a');
    //sum_gematria_word(word);
    // Gematria_Sequences(word,text);
     //replace_letters('!');
    //printf("the revers test : %s\n",word);
    //check_contain(text,word);
    //Atbash_Sequences(word,text);
    //char s1 [TXT] = "abababa ba";
    //char s2 [WORD] = "aba";
    //printf("%d",a);
    //int index_end = count_index_end(word,text,17);
    //printf("%d",index_end);
    //int index_start = count_index_start(word,text,0);
   // printf("%d",index_start);
    Atbash_Sequences(word ,text);
}