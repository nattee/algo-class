import java.util.Scanner;
public class MCS {
	public static void main(String[] args) {
		int n,a;
		long sum=0,maxsum=-1000000;
		Scanner kb=new Scanner(System.in);
		n=kb.nextInt();
		for(int i=0;i<n;++i) {
			a=kb.nextInt();
			sum=sum>0?sum+a:a;
			if(sum>maxsum)
				maxsum=sum;
		}
		System.out.println(maxsum);
	}
}
