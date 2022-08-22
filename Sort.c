#include <stdio.h>

typedef int ElementType;

void Swap(ElementType* a, ElementType *b)
{
	ElementType c = *a;
	*a = *b;
	*b = c;
}

void Bubble_Sort(ElementType A[],int N)
{
	for (int i = 0; i < N; ++i)
		{
			int flag = 0;
			for (int j = 1; j < N-i; ++j)
			{
				if(A[j]<A[j-1])
				{
					flag = 1;
					Swap(&A[j],&A[j-1]);
				}
			}
			if(!flag)
				break;
		}	
}

void Insertion_Sort(ElementType A[],int N)
{
	ElementType tmp;
	int i,j;
	for (i = 1; i < N; ++i)
	{
		tmp = A[i];
		for ( j = i;tmp < A[j-1] && j > 0; j--)
			A[j] = A[j-1];
		A[j] = tmp;
	}
}

int main()
{
	ElementType a[5] = {5,4,3,6,1};

	Bubble_Sort(a,5);
	//Insertion_Sort(a,5);
	
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n",a[i]);
	}
	
}