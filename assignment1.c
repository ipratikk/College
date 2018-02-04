#include<stdio.h>
#include<stdlib.h>
int *p;
int n;
int *p2;
void input()
{
	int i;
	printf("How many numbers do you want to enter in the array?\n");
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	printf("Enter the %d numbers\n",n);
	for(i=0;i<n;i++)
	scanf("%d",p+i);
}

void input2()
{
        p2=(int *)realloc(p,(n)*sizeof(int));
        p2[n-1]=-4;
	p=(int *)realloc(p2,n*sizeof(int));
}

void display()
{
	int i;
	printf("\n\n\n\n");
	printf("The array after the desired operation is -->\n");
	for(i=0;i<n;i++)
		printf("%d ",p[i]);
	printf("\n\n\n\n");
}

int lsearch(int *p,int n,int x,int y)
{
	int i,check=1;
	for(i=y+1;i<n;i++)
	{
		if(p[i]==x)
		{
			return i;
		}
		else
			check=1;
	}
	if(check==1 && y==-1)
		return -1;
	else if(check==1 && y!=-1)
		return -2;
}

int binsearch(int *p,int n,int x,int y)
{
	int low=y+1,up=n-1,mid,check=1;
	while(low<up)
	{
		mid=(low+up)/2;
		if(x<p[mid])
			up=mid-1;
		else if(x>p[mid])
			low=mid+1;
		else if(x==p[mid])
		{
			return mid;
		}
		else
			check=1;
	}
	if(check==1 && y==-1)
		return -1;
	else if(check==1 && y!=-1)
		return -2;
}
		
void swap(int x, int y)
{
	int temp = p[x];
	p[x]=p[y];
	p[y]= temp;
}
 
void bsort(int *p, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n-i-1; j++)
			if (p[j] > p[j+1])
				swap(j, j+1);
}

void ushift(int *p,int n,int x)
{
	int i;
	for(i=n-1;i>x;i--)
	p[i]=p[i-1];
}

void lshift(int *p,int n,int x)
{
        int i;
        for(i=x;i<n;i++)
        p[i]=p[i+1];
}

int main()
{
	int i,j,y=-1,x=0,n1,n2,*p1,*p2,ch,check=0;
	input();
for(;;)
{
	printf("Enter the choice\n");
	printf("0. Exit\n");
	printf("1. Implement Linear Search\n");
	printf("2. Implement Binary Search\n");
	printf("3. Find 2nd largest number from a given list of numbers\n");
	printf("4. Insert a new element at any given position in a 1D array\n");
	printf("5. Insert a new element at a proper position of a sorted array\n");
	printf("6. Delete an element from an array\n");
	printf("7. Remove duplicate elements from an array\n");
	printf("8. Merge two already sorted array\n");
	printf("9. Exchange the position of consecutive elements\n");
	printf("10.Implement Bubble Sort Algorithm\n");
	scanf("%d",&ch);
	if(ch==0)
	{
		printf("Terminated\n");
		break;
	}
	else
	{
		switch(ch)
		{
			y=-1;
			case 1:
			printf("Enter the number to be searched\n");
			scanf("%d",&x);
			y=-1;
			y=lsearch(p,n,x,y);
				if(y==-1)
					printf("Number not found\n");
				else if(y==-2)
					break;
				else
					printf("Number found at index %d\n",y);
			break;
		
			case 2:
			printf("Enter the number to be searched\n");
			scanf("%d",&x);
			{
                                y=binsearch(p,n,x,y);
                                if(y==-1)
                                        printf("Number not found\n");
                                else if(y==-2)
                                        break;
                                else
                                        printf("Number found at %d index\n",y);
                        }
			break;
		
			case 3:
			bsort(p,n);
			printf("The second largest number is %d\n",p[n-2]);
			break;

			case 4:
			n=n+1;
			input2();
			printf("Enter the position starting from 1 where you want to enter the number\n");
			scanf("%d",&x);
			ushift(p,n,x-1);
			printf("Enter the number\n");
			scanf("%d",&p[x-1]);
			display();
			break;

			case 5:
			n=n+1;
			input2();
			n=n-1;
			bsort(p,n);
			n=n+1;
			printf("Enter the number to add to the array\n");
			scanf("%d",&x);
			display();
			for(i=0;i<n-1;i++)
			{
				if(x<=p[0])
				{
					ushift(p,n,0);
					p[0]=x;
					break;
				}
				else if(p[i]<=x && p[i+1]>=x)
				{
					ushift(p,n,i);
					p[i+1]=x;
					break;
				}
				else if(x>=p[n-2])
				{
					p[n-1]=x;
					break;
				}
			}
			display();
			break;
			
			case 6:
			printf("Enter the element to delete\n");
			scanf("%d",&x);
			for(;;)
			{
                                y=lsearch(p,n,x,y);
				if(y>=0)
				{
					lshift(p,n,y);
					n--;
				}
				else
					break;
                        }
			display();
			break;

			case 7:
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					y=i;
					for(;;)
					{
						y=lsearch(p,n,p[i],y);
						if(y>=0)
						{
							lshift(p,n,y);
							n--;
						}
						else
						{
							check=1;
							break;
						}
					}
				}
			}
			display();
			break;

			case 8:
			printf("How many numbers do you want to enter in 1st array?\n");
			scanf("%d",&n1);
			printf("Enter the %d numbers\n",n1);
			p1=(int *)malloc(n1*sizeof(int));
			for(i=0;i<n1;i++)
				scanf("%d",p1+i);
			printf("How many numbers do you want to enter in 2nd array?\n");
                        scanf("%d",&n2);
                        printf("Enter the %d numbers\n",n2);
                        p2=(int *)malloc(n2*sizeof(int));
                        for(i=0;i<n2;i++)
                                scanf("%d",p2+i);
			n=n1+n2;
			y=n1;
			p=(int *)malloc(n*sizeof(int));
			for(i=0;i<n;i++)
			{
				if(i<n1)
					p[i]=p1[i];
				else
					p[i]=p2[i-n1];
			}
			bsort(p,n);
			for(i=0;i<n;i++)
                        {
                                y=i;
                                for(j=i+1;j<n;j++)
                                {
                                        y=lsearch(p,n,p[i],y);
                                        if(y>=0)
                                        {
                                                lshift(p,n,y);
                                                n--;
                                        }
                                        else
                                                break;
                                }
                        }
                        display();
                        break;

			case 9:
			if(n%2!=0)
			printf("Cannot perform operation for odd number of data\n");
			else
			{
				for(i=0;i<n;i=i+2)
				swap(i,i+1);
			}
			display();
			break;

			case 10:
			bsort(p,n);
			display();
			break;
			
			default:
			printf("Wrong choice. Please try again\n");
			break;
		}
	}
}
}
