import java.util.Scanner;


public class Triangle {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),a[][]=new int[101][101],ans=0;
		a[1][1]=kb.nextInt();
		for(int i=2;i<=n;++i)
			for(int j=1;j<=i;++j)
				a[i][j]=Math.max(a[i-1][j-1],a[i-1][j])+kb.nextInt();
		for(int i=1;i<=n;++i)
			ans=Math.max(ans,a[n][i]);
		System.out.println(ans);
	}

}
