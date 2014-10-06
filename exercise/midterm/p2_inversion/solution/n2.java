import java.util.Scanner;

public class Inversion2 {
	// O(n^2)
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			a[]=new int[n];
		long ans=0;
		for(int i=0;i<n;++i)
			a[i]=kb.nextInt();
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(a[i]>a[j]) ++ans;
		System.out.print(ans);
	}
}
