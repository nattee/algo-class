
#include <stdio.h>

/* Compute the length of S(k) */
int len(int k)
{
	int x;
	if (k==-1) return 0; 
	x = len(k-1);
	return x + k+3 + x;
}

/* Return nth character in S(k) */
char solve(int n, int k)
{
	if (n > len(k)) return solve(n,k+1);
	if (n <= len(k-1)) return solve(n,k-1);
	n = n - len(k-1); /* Discount S(k-1) from beginning of string */
	if (n <= k+3) /* n in middle section? */
		return (n==1) ? 'g' : 'a';
	n = n - (k+3);
	return solve(n,k-1); 
}

int main(void)
{
	int n;
	scanf ("%d", &n);
	printf ("%c\n", solve(n,0));
	return 0;
}