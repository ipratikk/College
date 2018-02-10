#include<stdio.h>
#include<string.h>
char str1[200];
char str2[200];
char str3[200];
int slen(char *s)
{
	int i=0;
	while(s[i]!='\0')
	i++;
	return i;
}
void scon(char *s1,char *s2)
{
	int l1=slen(s1),l2=slen(s2),i;
	for(i=0;i<(l1+l2);i++)
	{
		if(i<l1)
		str3[i]=s1[i];
		else
		str3[i]=s2[i-l1];
	}
}
void lower(char *s)
{
	int i;
	char tmp;
	for(i=0;i<slen(s);i++)
		if(s[i]>='A'&&s[i]<='Z')
		{
			tmp=s[i]+ 32;
			s[i]=tmp;
		}
}
void upper(char *s)
{
	int i;
	char tmp;
	for(i=0;i<slen(s);i++)
		if(s[i]>='a'&&s[i]<='z')
		{
			tmp=s[i]-32;
			s[i]=tmp;
		}
}
void vowcons(char *s)
{
	int vow=0,cons=0,num=0,i;
	for(i=0;i<slen(s);i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
		vow++;
		else if(s[i]>='0'&&s[i]<='9')
		num++;
		else
		cons++;
	}
	printf("Vowels = %d & Consonants = %d\n",vow,cons);
}
int subocc(char *s1,char *s2)
{
	int i,j,l1=slen(s1),l2=slen(s2),count=0,count1=0;
	for (i = 0; i < l1;)
    	{
        j = 0;
        count = 0;
        while ((s1[i] == s2[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;                                   
            count = 0;
        }
        else
            i++;
 	}
	return count1;
}
int scmp(char *s1,char *s2)
{
    int i=0;
    while(s1[i]==s2[i])
    {
        if(s1[i]=='\0'||s2[i]=='\0')
            break;
        i++;
    }
    if(s1[i]=='\0' && s2[i]=='\0')
        return 0;
    else
        return -1;
}
void smallarg(char *p)
{
	int i,char *sml,*lrg,tmp;
	for(i=0;i<slen(p);i++)
	{
		if(p[i]==' ')
		{
			if(slen(tmp)<=slen(sml))
			{
				sml=tmp;
				tmp="";
void main()
{
	
}
			
