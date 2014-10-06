import java.util.Arrays;
import java.util.Scanner;

public class Inversion3 {
	// O(n^2)
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			a,
			at,
			set[]=new int[n];
		long ans=0;
		for(int i=0;i<n;++i){
			a=kb.nextInt();
			at=Arrays.binarySearch(set, 0, i, a);
			if(at<0)
				at=-at-1;
			else
				while(set[at]==a) ++at;
			ans+=i-at;
			System.arraycopy(set, at, set, at+1, i-at);
			set[at]=a;
		}
		System.out.print(ans);
	}
}
