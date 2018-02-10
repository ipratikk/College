#include <stdio.h>
#include <string.h>
#include <ctype.h>
void lower_string(char s[]) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'A' && s[c] <= 'Z') {
            s[c] = s[c] + 32;
        }
        c++;
    }
}
void upper_string(char s[]) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'a' && s[c] <= 'z') {
            s[c] = s[c] - 32;
        }
        c++;
    }
}
int length(char str[]) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
int compare(char str1[], char str2[]) {
    int i;
    i = 0;
    while (str1[i] != '\0') {
        if (str1[i] > str2[i])
            return (1);
        if (str1[i] < str2[i]) return (-1);
        i++;
    }
    return (0);
}
void copy(char str2[], char str1[]) {
    int i = 0;
    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}
int palindrome(char str[]) {
    int i, j;
    i = j = 0;
    while (str[j] != '\0')
        j++;
    j--;
    while (i < j) {
        if (str[i] != str[j])
            return (0);
        i++;
        j--;
    }
    return (1);
}
void reverse(char str[]) {
    int i, j;
    char temp;
    i = j = 0;
    while (str[j] != '\0')
        j++;
    j--;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
void removeAll(char * str, const char toRemove, int index)
{
    int i;
    while(str[index] != '\0')
    {
        if(str[index] == toRemove)
        {
            i = index;
            while(str[i] != '\0')
            {
                str[i] = str[i + 1];
                i++;
            }
        }
        index++;
    }
}
void removeDuplicates(char * str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        removeAll(str, str[i], i + 1);
        i++;
    }
}
void swap(char *str1, char *str2)
{
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}
void concat(char str1[], char str2[]) {
    int i, j;
    i = 0;
    while (str1[i] != '\0')
        i++;
    for (j = 0; str2[j] != '\0'; i++, j++)
        str1[i] = str2[j];
    str1[i] = '\0';
}
void main()
{
    int i,j,ch,ch2,count,tmp,vowels,consonants,y=0,x=0,k=0,n,n2,minIndex=0,maxIndex=0,max=0,min=0,l;
    char s[200],s1[200],substr[100][100]= {0},str[25][25],temp[25],*ptr;
    for(;;) {
        printf("\nEnter the choice\n");
        printf("0. Exit\n");
        printf("1. Implement library functions on a string\n");
        printf("2. Calculate string length in user defined function\n");
        printf("3. concat using user defined function\n");
        printf("4. lowercase conversion using user defined function\n");
        printf("5. uppercase conversion using user defined function\n");
        printf("6. count vowels and consonants using user defined function\n");
        printf("7. substring search using user defined function\n");
        printf("8. compare strings using user defined function\n");
        printf("9. find the largest and smallest word in a string\n");
        printf("10.check palindromic string using user defined function\n");
        printf("11.reverse a string using user defined function\n");
        printf("12.remove duplicate characters in a string using user defined function\n");
        printf("13.copy one string into another string using user defined function\n");
        printf("14.swap 2 string using user defined function\n");
        printf("15.search for a string in a user given sentence\n");
        printf("16.sort n number of words in alphabetical order\n");
        printf("17.print abbreviations of an input string\n");
        scanf("%d",&ch);
        if(ch==0) {
            printf("Terminated\n");
            break;
        }
        else {
            switch(ch) {
            case 1:
                for(;;)
                {
                    printf("0.Return to main menu\n");
                    printf("1.Length of string\n");
                    printf("2.Concate two strings\n");
                    printf("3.Convert string to lowercase\n");
                    printf("4.Convert string to uppercase\n");
                    scanf("%d",&ch2);
                    if(ch2==0)
                        break;
                    else
                    {
                        printf("Enter the String\n");
                        scanf("%s",s);
			switch(ch2)
                        {
			case 1:
                            l=strlen(s);
                            printf("String length of s = %d\n",l);
                            break;
                        case 2:
                            printf("Enter 2nd string\n");
                            scanf("%s",s1);
                            strcat(s,s1);
                            printf("Concatenated String is --> %s\n",s);
                            break;
                        case 3:
                            for(i=0; i<l; i++)
                            {
                                tmp=tolower(s[i]);
                                s[i]=tmp;
                            }
                            printf("Lowercase string = %s\n",s);
                            break;
                        case 4:
                            for(i=0; i<l; i++)
                            {
                                tmp=toupper(s[i]);
                                s[i]=tmp;
                            }
                            printf("Uppercase string = %s\n",s);
                            break;
                        default:
                            printf("Wrong Input\n");
                            break;
                        }
                    }
                }
                break;
            case 2:
                printf("Enter the string\n");
                scanf("%s",s);
                y = length(s);
                printf("Length of %s= %d\n", s, y);
                break;
            case 3:
                printf("Enter the 1st string\n");
                scanf("%s",s);
                printf("Enter the 2nd String\n");
                scanf("%s",s1);
                concat(s, s1);
                printf("The concated string is --> %s", s);
                break;
            case 4:
                printf("Enter the string\n");
                scanf("%s",s);
                lower_string(s);
                printf("String in lower case is \"%s\"\n",s);
                break;
            case 5:
                printf("Enter the string\n");
                scanf("%s",s);
                upper_string(s);
                printf("String in upper case is \"%s\"\n",s);
                break;
            case 6:
                printf("Enter a string with a tab at the end\n");
                scanf("%[^\t]",s);
                vowels=consonants=0;
                for(i=0; s[i]!='\0'; ++i)
                {
                    if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||
                            s[i]=='o' || s[i]=='u' || s[i]=='A' ||
                            s[i]=='E' || s[i]=='I' || s[i]=='O' ||
                            s[i]=='U')
                        ++vowels;
                    else if((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z'))
                        ++consonants;
                }
                printf("Vowels: %d\n",vowels);
                printf("Consonants: %d\n",consonants);
                break;
            case 7:
                printf("Enter a string with a tab at the end\n");
                scanf("%[^\t]",s);
                printf("Enter the substring to search\n");
                scanf("%s",s1);
                for(i=0; s[i]!='\0'; i++)
                {
                    j=0;
                    if(s[i]==s1[j])
                    {
                        tmp=i+1;
                        while(s[i]==s1[j])
                        {
                            i++;
                            j++;
                        }
                        if(s1[j]=='\0')
                            printf("The substring is present in given string at position %d\n",tmp);
                        else
                        {
                            i=tmp;
                            tmp=0;
                        }
                    }
                }
                if(tmp==0)
                    printf("The substring is not present in given string\n");
                break;
            case 8:
                printf("Enter the 1st string\n");
                scanf("%s",s);
                printf("Enter the 2nd string\n");
                scanf("%s",s1);
                n2 = compare(s, s1);
                if (n2 == 0)
                    printf("Both are same\n");
                else if (n2 > 0)
                    printf("1st>2nd\n");
                else
                    printf("1st<2nd\n");
                break;
            case 9:
                i=0;
                k=0;
                printf("Enter a string with a tab at the end\n");
                scanf("%[^\t]",s);
                while(s[k]!='\0')
                {
                    j=0;
                    while(s[k]!=' '&&s[k]!='\0')
                    {
                        substr[i][j]=s[k];
                        k++;
                        j++;
                    }
                    substr[i][j]='\0';
                    i++;
                    if(s[k]!='\0')
                        k++;
                }
                int len=i;
                max=length(substr[0]);
                min=length(substr[0]);
                for(i=0; i<len; i++)
                {
                    y=length(substr[i]);
                    if(y>max)
                    {
                        max=y;
                        maxIndex=i;
                    }
                    if(y<min)
                    {
                        min=y;
                        minIndex=i;
                    }
                }
                printf("Largest Word is --> %s\nSmallest word is --> %s\n",substr[maxIndex],substr[minIndex]);
                break;
            case 10:
                printf("Enter the string\n");
                scanf("%s",s);
                x = palindrome(s);
                if (x == 0)
                    printf("\nNot a palindrome");
                else
                    printf("\nA palindrome");
                break;
            case 11:
                printf("Enter the string\n");
                scanf("%s",s);
                reverse(s);
                printf("The reversed string is --> %s", s);
                break;
            case 12:
                printf("Enter the string\n");
                scanf("%s",s);
                removeDuplicates(s);
                printf("String after removing duplicates: %s\n", s);
                break;
            case 13:
                printf("Enter the 1st string\n");
                scanf("%s",s);
                printf("Enter the 2nd string\n");
                scanf("%s",s1);
                copy(s, s1);
                printf("\nResultant s = %s", s);
                break;
            case 14:
                printf("Enter the 1st string\n");
                scanf("%s",s);
                printf("Enter the 2nd string\n");
                scanf("%s",s1);
                swap(s, s1);
                printf("s is %s, s1 is %s\n", s, s1);
                break;
            case 15:
                printf("press 7 please\n");
                break;
            case 16:
                printf("How many words do you want to enter?\n");
                scanf("%d",&count);
                printf("Enter the sentence\n");
                for(i=0; i<count; i++)
                    scanf("%s",str[i]);
                for(i=0; i<=count; i++)
                    for(j=i+1; j<=count; j++) {
                        if(strcmp(str[i],str[j])>0) {
                            strcpy(temp,str[i]);
                            strcpy(str[i],str[j]);
                            strcpy(str[j],temp);
                        }
                    }
                printf("The sentence sorted alphabetically is --> ");
                for(i=0; i<=count; i++)
                    printf("%s ",str[i]);
                break;
            case 17:
                printf("Enter a string with a tab at the end\n");
                scanf("%[^\t]",s);
                l=strlen(s);
                ptr=s;
                printf("%c",*(ptr+1));
                for(i=1; i<l; i++)
                {
                    if(*(ptr+i-1)==' ')
                        printf("%c",*(ptr+i));
                }
                break;
            default:
                printf("Invalid choice");
                break;
            }
        }
    }
}
