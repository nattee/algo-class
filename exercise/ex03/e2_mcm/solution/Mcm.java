import java.util.Scanner;

public class Mcm {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			dp[][]=new int[n][n],
			s[]=new int[n+1];
		for(int i=0;i<=n;++i)
			s[i]=kb.nextInt();
		for(int i=1;i<n;++i)
			for(int j=0;j+i<n;++j){
				dp[j][i]=dp[j+1][i-1]+s[j]*s[j+1]*s[j+i+1];
				for(int k=1;k<i;++k)
					dp[j][i]=Math.min(dp[j][i], dp[j][k]+dp[j+k+1][i-k-1]+s[j]*s[j+k+1]*s[j+i+1]);
			}
		System.out.print(dp[0][n-1]);
	}

}
