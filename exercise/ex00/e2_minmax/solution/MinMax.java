import java.util.Scanner;

public class MinMax {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			m=kb.nextInt(),
			r=kb.nextInt(),
			mat[][]=new int[n+1][m+1];
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				mat[i][j]=kb.nextInt();
		while(r-->0){
			int r1=kb.nextInt(),
				c1=kb.nextInt(),
				r2=kb.nextInt(),
				c2=kb.nextInt();
			if(r1>r2||c1>c2)
				System.out.println("INVALID");
			else if(r1>n||r2<1||c1>m||c2<1)
				System.out.println("OUTSIDE");
			else{
				r1=Math.max(r1, 1);
				c1=Math.max(c1, 1);
				r2=Math.min(r2, n);
				c2=Math.min(c2, m);
				int ans=mat[r1][c1];
				do
					for(int c=c1;c<=c2;++c)
						ans=Math.max(ans,mat[r1][c]);
				while(r1++<r2);
				System.out.println(ans);
			}
		}
	}

}
