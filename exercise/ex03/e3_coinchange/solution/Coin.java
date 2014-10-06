import java.util.Scanner;

public class Coin {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			m=kb.nextInt(),
			dp[]=new int[m+1],
			denom[]=new int[n];
		for(int i=0;i<n;++i)
			denom[i]=kb.nextInt();
		for(int i=1;i<=m;++i){
			dp[i]=i;
			for(int j=n-1;j>=0&&i-denom[j]>=0;--j)
				dp[i]=Math.min(dp[i], dp[i-denom[j]]);
			++dp[i];
		}
		System.out.print(dp[m]);
	}

}
