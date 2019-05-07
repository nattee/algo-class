import java.util.Scanner;

public class Lis {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int ans=1,
			n=kb.nextInt(),
			s[]=new int[n],
			dp[]=new int[n];
		for(int i=0;i<n;++i){
			s[i]=kb.nextInt();
			for(int j=0;j<i;++j)
				if(s[j]<=s[i])
					dp[i]=Math.max(dp[i],dp[j]);
			ans=Math.max(ans,++dp[i]);
		}
		System.out.print(ans);
	}

}
