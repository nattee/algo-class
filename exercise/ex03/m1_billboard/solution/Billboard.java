import java.util.Scanner;

public class Billboard {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt()+3,
			c[]=new int[n],
			ans=0;
		for(int i=3;i<n;++i){
			c[i]=kb.nextInt()+Math.max(c[i-2], c[i-3]);
			ans=Math.max(ans, c[i]);
		}
		System.out.print(ans);

	}

}
