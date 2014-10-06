import java.util.Scanner;

public class Mcs22 {
	// O(n^2)
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			ans=-1000,
			a[]=new int[n];
		for(int i=0;i<n;++i)
			a[i]=kb.nextInt();
		for(int i=0;i<n;++i){
			int j=i,
				sum=0;
			do{
				sum+=a[j];
				ans=Math.max(ans, sum);
				if(++j==n) j=0;
			}while(j!=i);
		}
		System.out.print(ans);
	}

}
