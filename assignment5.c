#include<stdio.h>
void insert(FILE *fp)
{
	char ch;
	while((ch=getchar())!='1')
		fputc(ch,fp);
	fclose(fp);
}
void read(FILE *fp)
{
	char ch;
	printf("The data stored in file 1 is -->\n");
	while((ch=fgetc(fp))!=EOF)
		printf("%c",ch);
	printf("\n");
	fclose(fp);
}
void append(FILE *fp)
{
	char ch;
	printf("Enter data to append\n");
	while((ch=getchar())!='1')
		fputc(ch,fp);
	fclose(fp);
}
void copy(FILE *fp,FILE *fp1)
{
	char ch;
	while((ch=fgetc(fp))!=EOF)
		fputc(ch,fp1);
	fclose(fp);
	fclose(fp1);
}
void main()
{
	int opt;
	FILE *fp,*fp2;
	for(;;)
	{
		printf("0.EXIT\n");
		printf("1.WAP to create a file, open it and update the file\n");
		printf("2.WAP to copy the data of one file into another\n");
		printf("3.WAP to count the number of characters,lines,spaces in a file\n");
		printf("4.WAP to store student records in a file and search a record using enrollment number\n");
		printf("5.WAP to read information of students(name,address,phno) from user and arrange them in ascending order using the concept of array of pointers\n");
		printf("6.WAP to read marks of 3 subjects for n number of students. Sort the data in each row and find the highest marks using array of pointers\n");
		printf("7.WAP to intialise an array and store the addresses of the array elements to another array and print the elements using 2nd array\n");
		scanf("%d",&opt);
		if(opt==0)
		break;
		else
		{	
			switch(opt)
			{
				case 3:
					int sp=0,l=0,chr=0;
					fp=fopen("myfile.txt","w");
					while((ch=getchar())!='1')
						fputc(ch,fp);
					fclose(fp);
					fp=fopen("myfile.txt","r");
					while((ch=fgetc(fp))!=EOF)
					{
						if(ch==' ')
							sp++;
						if(ch=='\n')
							l++;
						chr++;
						3
					}
					fclose(fp);
					printf("Number of characters: %d\n",chr);
					printf("Number of spaces: %d\n",sp);
					printf("Number of lines: %d\n",(l+1));
				break;
				case 2:
					fp=fopen("myfile.txt","r");
					fp1=fopen("myfile2.txt","w+");
					copy(fp,fp1);
					fp=fopen("myfile2.txt","r");
					read(fp);
				break;
				case 1:
					fp=fopen("myfile.txt","w+");
					insert(fp);
					printf("enter data to append\n");
					fp=fopen("myfile.txt","a+");
					append(fp);
					
