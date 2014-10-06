import java.util.Arrays;
import java.util.Scanner;

public class PairSum {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			m=kb.nextInt(),
			a[]=new int[n];
		for(int i=0;i<n;++i)
			a[i]=kb.nextInt();
		Arrays.sort(a);
		while(m-->0){
			int l=0,
				r=n-1,
				x=kb.nextInt();
			while(l<r){
				int sum=a[l]+a[r];
				if(sum==x) break;
				else if(sum<x) ++l;
				else --r;
			}
			System.out.println(l<r?"YES":"NO");
		}
	}

}
