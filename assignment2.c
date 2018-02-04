#include <stdio.h>
#include <stdlib.h>
void addsub()
{
    int r1,r2,c1,c2,i,j;
    printf("Enter the number of rows & columns of 1st matrix\n");
    scanf("%d%d",&r1,&c1);
    printf("Enter the number of rows & columns of 2nd matrix\n");
    scanf("%d%d",&r2,&c2);
    if(r1==r2&&c1==c2)
    {
        int ar1[r1][c1],ar2[r2][c2],sum[r1][c1],sub[r1][c1];
        printf("Enter the 1st matrix\n");
        for(i=0; i<r1; i++)
            for(j=0; j<c1; j++)
                scanf("%d",&ar1[i][j]);
        printf("Enter the 2nd matrix\n");
        for(i=0; i<r2; i++)
            for(j=0; j<c2; j++)
                scanf("%d",&ar2[i][j]);
        for(i=0; i<r2; i++)
            for(j=0; j<c2; j++)
                sum[i][j]=ar1[i][j]+ar2[i][j];
        for(i=0; i<r2; i++)
            for(j=0; j<c2; j++)
                sub[i][j]=ar1[i][j]-ar2[i][j];
        printf("The matrix after addition is -->\n");
        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
                printf("%d ",sum[i][j]);
            printf("\n");
        }
        printf("The matrix after subtraction is -->\n");
        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
                printf("%d ",sub[i][j]);
            printf("\n");
        }
    }
    else
        printf("Cannot perform addition or subtraction for this order of matrices\n");
}
void transpose()
{
    int r, c, i, j;
    printf("Enter the number of rows and columns of matrix\n");
    scanf("%d%d", &r, &c);
    int ar[r][c],transpose[c][r];
    printf("Enter elements of the matrix\n");
    for (i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &ar[i][j]);
    for (i = 0; i < r; i++)
        for( j = 0 ; j < c ; j++ )
            transpose[j][i] = ar[i][j];
    printf("Transpose of the matrix:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d\t", transpose[i][j]);
        printf("\n");
    }
}
void multiply()
{
    int r1, c1, r2, c2, i, j, k, sum = 0;
    int first[10][10], second[10][10], multiply[10][10];
    printf("Enter the number of rows and columns of first matrix\n");
    scanf("%d%d", &r1, &c1);
    printf("Enter the number of rows and columns of second matrix\n");
    scanf("%d%d", &r2, &c2);
    if (c1 != r2)
        printf("Matrices with entered orders can't be multiplied with each other.\n");
    else
    {
        printf("Enter the elements of first matrix\n");
        for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                scanf("%d", &first[i][j]);
        printf("Enter the elements of second matrix\n");
        for (i = 0; i < r2; i++)
            for (j = 0; j < c2; j++)
                scanf("%d", &second[i][j]);
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                for (k = 0; k < r2; k++)
                {
                    sum = sum + first[i][k]*second[k][j];
                }
                multiply[i][j] = sum;
                sum = 0;
            }
        }
        printf("Product of entered matrices:-\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
                printf("%d\t", multiply[i][j]);
            printf("\n");
        }
    }
}
void diagonal()
{
    int i,j,r,c;
    printf("Enter the rows and columns of the matrixs\n");
    scanf("%d%d",&r,&c);
    if(r==c)
    {
        int ar[r][c];
        printf("Enter the matrix\n");
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                scanf("%d",&ar[i][j]);
        printf("The diagonal element of the matrics are\n");
        for(i=0; i<r; i++)
            printf("%d ",ar[i][i]);
        printf("\n");
    }
    else
        printf("Error!! The given order is not of a square matrix\n");
}
void interchange()
{
    int i,j,r,c,tmp;
    printf("Enter the rows and columns of the matrixs\n");
    scanf("%d%d",&r,&c);
    if (r==c)
    {
        int ar[r][c];
        printf ("Enter the  matrix\n");
        for (i=0; i<r; i++)
            for (j=0; j<c; j++)
                scanf ("%d",&ar[i][j]);
        printf ("The given matrix is \n");
        for (i=0; i<r; ++i)
        {
            for (j=0; j<c; ++j)
                printf (" %d",ar[i][j]);
            printf ("\n");
        }
        for (i=0; i<r; i++)
        {
            tmp = ar[i][i];
            ar[i][i] = ar[i][c-i-1];
            ar[i][c-i-1] =tmp;
        }
        printf ("The matrix after interchanging the main & secondary diagonal -->\n");
        for (i=0; i<r; i++)
        {
            for (j=0; j<c; j++)
                printf (" %d",ar[i][j]);
            printf ("\n");
        }
    }
    else
        printf ("Error!! The given order is not of a square matrix\n");
}
void rcsum()
{
    int r, c, i, j, sum=0;
    printf("Enter the number of rows and columns of matrix\n");
    scanf("%d%d", &r, &c);
    int ar[r][c];
    printf("Enter the elements of the matrix\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &ar[i][j]);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            sum+=ar[i][j];
        printf ("row %d sum=%d\n",(i+1),sum);
        sum=0;
    }
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
            sum+=ar[j][i];
        printf ("Column %d sum=%d\n",(i+1),sum);
        sum=0;
    }
}
void sparse()
{
    int i, j, r,c,count = 0;
    printf("Enter the number of rows & columns of the matix : \n");
    scanf("%d %d", &r, &c);
    int ar[r][c];
    printf("Enter the matix \n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
        {
            scanf("%d", &ar[i][j]);
            if (ar[i][j] == 0)
                count++;
        }
    printf("There are %d number of zeros\n", count);
    if (count > ((r*c) / 2))
        printf("The given matrix is sparse matrix \n");
    else
        printf("The given matrix is not a sparse matrix \n");
}
void identity()
{
    int i, j, r,c, check = 1;
    printf("Enter the rows & columns of the matrix: \n");
    scanf("%d %d", &r, &c);
    int ar[r][c];
    printf("Enter the elements of the matrix\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &ar[i][j]);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            if (i==j && ar[i][j] != 1)
            {
                check = 0;
                break;
            }
            else if(i!=j && ar[i][j] != 0)
            {
                check = 0;
                break;
            }
        }
    if (check == 1 )
        printf("It is an identity matrix \n");
    else
        printf("It is not an identity matrix \n");
}
void symmetric()
{
    int r,c,i,j,check=1;
    printf("Enter the number of rows & columns of the matrix\n");
    scanf("%d%d",&r,&c);
    if(r==c)
    {
        int ar[r][c],transpose[r][c];
        printf("Enter the elements of the matrix\n");
        for (  i = 0 ; i < r; i++)
            for ( j = 0 ; j < c ; j++ )
                scanf("%d",&ar[i][j]);
        for(i = 0 ; i < r ; i++ )
            for( j = 0 ; j < c ; j++ )
                transpose[j][i] = ar[i][j];
        for ( i = 0 ; i < r ; i++ )
            for ( j = 0 ; j < c ; j++ )
            {
                if ( ar[i][j] != transpose[i][j] )
                {
                    check=0;
                    break;
                }
                else
                    check=1;
            }
        if ( check == 1 )
            printf("Symmetric matrix.\n");

        else
            printf("Not a symmetric matrix.\n");
    }
    else
        printf("Error!! The given order is not of a square matrix\n");
}
void upper()
{
    int array[10][10];
    int row,MAX_ROWS, col,MAX_COLS, isUpper,sum=0;
    printf("Enter the number of rows and columns of matrix\n");
    scanf("%d%d",&MAX_ROWS,&MAX_COLS);
    printf("Enter elements in matrix of size %dx%d: \n", MAX_ROWS, MAX_COLS);
    for(row=0; row<MAX_ROWS; row++)
        for(col=0; col<MAX_COLS; col++)
            scanf("%d", &array[row][col]);
    isUpper = 1;
    for(row=0; row<MAX_ROWS; row++)
        for(col=0; col<MAX_COLS; col++)
            if(col<row && array[row][col]!=0)
                isUpper = 0;
    if(isUpper == 1)
    {
        printf("The matrix is Upper triangular matrix.\n");
        for(row=0; row<MAX_ROWS; row++)
        {
            for(col=0; col<MAX_COLS; col++)
            {
                printf("%d ", array[row][col]);
                sum+=array[row][col];
            }
            printf("\n");
        }
        printf("The sum of its elements is:%d\n",sum);
    }
    else
        printf("The matrix is not Upper triangular matrix.\n");
}
void lower()
{
    int array[10][10];
    int row,MAX_ROWS, col,MAX_COLS, isLower,sum=0;
    printf("Enter the number of rows and columns of matrix\n");
    scanf("%d%d",&MAX_ROWS,&MAX_COLS);
    printf("Enter elements in matrix of size %dx%d: \n", MAX_ROWS, MAX_COLS);
    for(row=0; row<MAX_ROWS; row++)
        for(col=0; col<MAX_COLS; col++)
            scanf("%d", &array[row][col]);
    isLower = 1;
    for(row=0; row<MAX_ROWS; row++)
        for(col=0; col<MAX_COLS; col++)
            if(col>row && array[row][col]!=0)
                isLower = 0;
    if(isLower == 1)
    {
        printf("The matrix is Lower triangular matrix.\n");

        for(row=0; row<MAX_ROWS; row++)
        {
            for(col=0; col<MAX_COLS; col++)
            {
                printf("%d ", array[row][col]);
                sum+=array[row][col];
            }
            printf("\n");
        }
        printf("The sum of its elements is:%d\n",sum);
    }
    else
        printf("The matrix is not Lower triangular matrix.\n");
}
void pointer2()
{
    int r,c,i,j,sum=0;
    printf("How many rows and columns you want in the array?\n");
    scanf("%d%d",&r,&c);
    int *arr[r];
    for (i=0; i<r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    printf("Enter the %d numbers\n",r*c);
    for (i = 0; i <  r; i++)
        for (j = 0; j < c; j++)
        {
            scanf("%d",&arr[i][j]);
            sum+=arr[i][j];
        }
    printf("The sum off the matrix elements = %d\n",sum);
}
void pointer1()
{
    int r,c,i,j;
    printf("How many rows and columns you want in the array?\n");
    scanf("%d%d",&r,&c);
    int *arr[r];
    for (i=0; i<r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    printf("Enter the %d numbers\n",r*c);
    for (i = 0; i <  r; i++)
        for (j = 0; j < c; j++)
            scanf("%d",&arr[i][j]);
    printf("The %d numbers are\n",r*c);
    for (i = 0; i <  r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}
void search()
{
    int r,c,i,j,key,check=0;
    printf("How many rows and columns you want in the array?\n");
    scanf("%d%d",&r,&c);
    printf("What number u want to search in the array?\n");
    scanf("%d",&key);
    int *arr[r];
    for (i=0; i<r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    printf("Enter the %d numbers\n",r*c);
    for (i = 0; i <  r; i++)
        for (j = 0; j < c; j++)
            scanf("%d",&arr[i][j]);
    for (i = 0; i <  r; i++)
        for (j = 0; j < c; j++)
        {
            if(arr[i][j]==key)
            {
                printf("Element found at position %d \n",(i+1)*(j+1));
                check=1;
            }
        }
    if(check==0)
        printf("Element not found \n");
}
void main()
{
    int ch;
    for(;;)
    {
        printf("Enter the choice\n");
        printf("0. Exit\n");
        printf("1. Addition & Substraction of 2 matrices\n");
        printf("2. Sum of each row and column of a matrix\n");
        printf("3. Transpose of matrix\n");
        printf("4. Multiplication of 2 matrices\n");
        printf("5. Diagonal of a matrix\n");
        printf("6. Interchange diagonal of a matrix\n");
        printf("7. Sparse matrix\n");
        printf("8. Identity matrix\n");
        printf("9. Symmetric matrix\n");
        printf("10.Upper triangular matrix\n");
        printf("11.Lower triangular matrix\n");
        printf("12.Accessing array elements using array of pointers\n");
        printf("13.Sum of array elements using pointers\n");
        printf("14.Search for an array element using pointers\n");
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
            case 1:
                addsub();
                break;
            case 2:
                rcsum();
                break;
            case 3:
                transpose();
                break;
            case 4:
                multiply();
                break;
            case 5:
                diagonal();
                break;
            case 6:
                interchange();
                break;
            case 7:
                sparse();
                break;
            case 8:
                identity();
                break;
            case 9:
                symmetric();
                break;
            case 10:
                upper();
                break;
            case 11:
                lower();
                break;
            case 12:
                pointer1();
                break;
            case 13:
                pointer2();
                break;
            case 14:
                search();
                break;
            default:
                printf("Wrong Input. Please try again ! \n");
            }
        }
    }
}

