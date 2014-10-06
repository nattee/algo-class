import java.util.Scanner;

public class Cnk2 {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int N=kb.nextInt(),
			K=kb.nextInt();
		System.out.print(c(N,K));
	}
	
	static int c(int n,int k){
		if(k==0||k==n) return 1;
		return c(n-1,k)+c(n-1,k-1);
	}

}
