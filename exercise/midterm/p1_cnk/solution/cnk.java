import java.util.Scanner;

public class Cnk {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int N=kb.nextInt(),
			K=kb.nextInt(),
			c[][]=new int[N+1][N+1];
		for(int n=1;n<=N;++n){
			c[n][0]=c[n][n]=1;
			for(int k=1;k<n;++k)
				c[n][k]=c[n-1][k]+c[n-1][k-1];
		}
		System.out.print(c[N][K]);
	}

}
