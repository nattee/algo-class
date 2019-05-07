import java.util.Scanner;


public class Barcode {

	public static void main(String[] args) {
		int b[][][]=new int[32][32][32];
		Scanner kb=new Scanner(System.in);
		int N=kb.nextInt(),M=kb.nextInt(),K=kb.nextInt();
		for(int m=1;m<=M;++m) {
			for(int k=0;k<=K;++k)
				b[k+1][m][k]=1;
			for(int n=1;n<=m;++n)
				b[n][m][0]=1;
		}
		for(int n=2;n<=N;++n)
			for(int m=1;m<=M;++m)
				for(int k=1;k<n-1;++k)
					b[n][m][k]=b[n-1][m-1][k]+b[n-1][M][k-1];
		System.out.println(b[N][M][K]);
	}

}
