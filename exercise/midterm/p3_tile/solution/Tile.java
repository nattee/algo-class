import java.util.Arrays;
import java.util.Scanner;

public class Tile {
	// O(n(m^1.5))
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			m=kb.nextInt(),
			a=kb.nextInt(),
			dp[][]=new int[n][m+1],
			limit=(int)Math.sqrt(m);
		for(int i=0;i<n;++i)
			Arrays.fill(dp[i], 98011);
		for(int i=1;i<=limit;++i)
			dp[0][i*i]=(a-i)*(a-i);
		for(int i=1;i<n;++i){
			a=kb.nextInt();
			for(int j=1;j<=m;++j){
				limit=(int)Math.sqrt(j);
				for(int k=1;k<=limit;++k)
					dp[i][j]=Math.min(dp[i][j], dp[i-1][j-k*k]+(a-k)*(a-k));
			}
		}
		System.out.print(dp[n-1][m]>98010?"-1":dp[n-1][m]);
	}

}
