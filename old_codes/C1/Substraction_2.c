#include<stdio.h>
#include<string.h>

int main(void)
{
	char A[100], B[100], temp[100];
	int minus = 0;
	scanf("%s%s", A, B);

	if(strcmp(A, B) < 0 && strlen(A) < strlen(B))// big num subs(-) small num
	{
		strcpy(temp, A);
		strcpy(A, B);
		strcpy(B, temp);
		minus = 1;
	}
	int Alen = strlen(A), Blen = strlen(B), i;
	
	for(; Blen>0; Alen--, Blen--)
	{
		int diff = A[Alen-1]-B[Blen-1]+'0';
		if(diff < '0')
		{
			for(i = 2; A[Alen-i]<='0'; i++)
				A[Alen-i]+=9;

			A[Alen-i]--;
			diff+=10;
		}
		A[Alen-1] = diff;// result is stored in A
	}
	for(i=0; A[i]=='0';)
		i++;

	if(minus)
		printf("-%s\n", A+i);
	else
		printf("%s\n", A+i);

	return 0;
}