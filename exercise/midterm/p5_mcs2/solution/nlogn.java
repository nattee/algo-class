import java.util.Scanner;

public class Mcs2 {
	// O(n)
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			sumPlus=0,
			maxsum=-1000,
			sumMinus=0,
			minsum=1000,
			sum=0,
			a;
		for(int i=0;i<n;++i) {
			a=kb.nextInt();
			sum+=a;
			maxsum=Math.max(maxsum, sumPlus=sumPlus>0?sumPlus+a:a);
			minsum=Math.min(minsum, sumMinus=sumMinus<0?sumMinus+a:a);
		}
		System.out.print(Math.max(maxsum,sum==minsum?-1000:sum-minsum));
	}

}
