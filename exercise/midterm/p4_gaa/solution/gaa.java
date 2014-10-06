import java.util.Arrays;
import java.util.Scanner;

public class Gaa {
	// O(k) ; k=min_i length(G(i))>n
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),
			a[]=new int[28];
		a[0]=3;
		for(int i=0;a[i]<1000000000;++i)
			a[i+1]=a[i]*2+i+4;
		int at=Arrays.binarySearch(a, n);
		at=at<0?-at-1:at;
		while(at>0){
			if(n>a[at-1]){
				n-=a[at-1];
				if(n<at+4)
					break;
				else
					n-=at+3;
			}
			--at;
		}
		System.out.print(n==1?'g':'a');
	}

}
