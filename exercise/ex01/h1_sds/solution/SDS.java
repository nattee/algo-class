import java.util.Arrays;
import java.util.Scanner;

public class SDS {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int ans[]=new int[673366],
			n=kb.nextInt(),
			at=0,
			iAns=0;
		ans[0]=1;
		while(ans[iAns++]<=2e9){
			while(at<iAns&&ans[at]<=iAns) ++at;
			ans[iAns]=ans[iAns-1]+at;
		}
		while(n-->0){
			int x=kb.nextInt(),
				sol=Arrays.binarySearch(ans,0,iAns, x);
			System.out.println(sol<0?-sol-1:sol+1);
		}
	}

}
