import java.util.Scanner;

public class Lcs {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int ans=0,
			dp[][]=new int[501][501];
		String a=kb.nextLine(),
			   b=kb.nextLine();
		for(int i=0;i<a.length();++i)
			for(int j=0;j<b.length();++j)
				ans=Math.max(ans, dp[i+1][j+1]=a.charAt(i)==b.charAt(j)?dp[i][j]+1:Math.max(dp[i][j+1],dp[i+1][j]));
		System.out.println(ans);
	}

}
