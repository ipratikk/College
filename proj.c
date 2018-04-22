#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j,ch,fc=0;
char filename[50],e,c,s[100000],flist[1000][50];
FILE *fp1,*fp;
void Create();
void Append();
void Delete();
void Display();
void Rename();
void Details();
void list();
void rmv(char *s);
int main()
{
 do 
 {
  printf("MENU:\n-----\n");
  printf("1.CREATE\n2.OPEN\n3.UPDATE\n4.DELETE\n5.RENAME\n6.DETAILS\n7.List Files created in this run\n8.EXIT\n");
  printf("Enter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
     Create();
     break;
   case 2:
     Display();
     break;
   case 3:
     Append();
     break;
    case 4:
     Delete();
     break;
	case 5:
     Rename();
     break;
    case 6:
     Details();
     break;
    case 7:
    	list();
    	break;
    case 8:
     exit(0);
    default: printf("Wrong Choice\n");
  } system("clear");
 }while(1);
 return 0;
}
void rmv(char *s)
{
	for(i=0;i<fc;i++)
	{
		if(strcmp(flist[i],s)==0)
			strcpy(flist[i],"0");
	}
}
void Create()
{
	ch=1;
	int count=0;
   while(ch!=0)
   {
	   printf("Enter then new filename with extension (max 50 characters) : \n");
	   scanf("%s",filename);
	   fp=fopen(filename,"r");
	   if(fp==NULL)
	   {
	   		fp1=fopen(filename,"w");
	   	    fclose(fp1);
	   	    count++;
	   	    strcpy(flist[fc++],filename);
	   	    printf("Press 1 to create another file or 0 to exit\n");
	   }
	   else
		   	printf("Filename already exists, press 1 to try again with a different name or press 0 to exit\n");
		scanf("%d",&ch);
   }
   printf("%d file(s) created\n",count);
}
void Display()
{
  printf("Enter the file name: ");
  scanf("%s",filename);
  fp1=fopen(filename,"r");
  if(fp1==NULL)
   printf("File not found!\n");
  else
  {
  	while(!feof(fp1))
  	{
  	 c=getc(fp1);
  	 printf("%c",c);
    }
    fclose(fp1);
   }
}
void Delete()
{
  printf("Enter the file name: ");
  scanf("%s",filename);
  fp1=fopen(filename,"r");
  if(fp1==NULL)
   printf("File not found!\n");
  if(remove(filename)==0)
  {
  	rmv(filename);
  	printf("File has been deleted successfully!\n");
  }
  else
   printf("Error!\n");
}
void list()
{
	printf("The files created in this run of the program are-->>\n");
	for(i=0;i<fc;i++)
	{
		if(strcmp(flist[i],"0")!=0)
		printf("%s\t",flist[i]);
	}
	printf("\n");
}
void Append()
{
	printf("Enter the file name: ");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	if(fp==NULL)
		printf("File not found!\n");
	else
	{
		fclose(fp);
		printf("1.Rewrite the file\n");
		printf("2.Append data to the file\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			fp=fopen(filename,"w");
			printf("Type the text to write ending with a tab\n");
			break;
			case 2:
			fp=fopen(filename,"a+");
			printf("Type the text to append ending with a tab\n");
			break;
			default:
			printf("Wrong choice, try again\n");
			break;
		}
		while((ch=getchar())!='\t')
		fputc(ch,fp);
		fclose(fp);
	}	
}
void Rename()
{
	int ret;
   char oldname[50],newname[50];
   printf("Enter filename: ");
   scanf("%s",oldname);
      printf("Enter new filename: ");
   scanf("%s",newname);
   ret = rename(oldname, newname);
   if(ret == 0)
      printf("File renamed successfully\n");
 	else 
      printf("Error: unable to rename the file\n");
}
void Details()
{
	printf("Enter the file name: ");
	scanf("%s",filename);
	fp1=fopen(filename,"r");
	if(fp1==NULL) 
		printf("File Not Found\n");
	else
	{
		int i;
 		 i=0;
 		 char ch;
  		while( ( ch = fgetc(fp1) ) != EOF )
		{
  		 if(ch!='\0')        
  		 {
      	 i=i+1;
  		 }
		}
		printf("The length of the file is: \n");
		printf("%d\n",i); 
	}
}
