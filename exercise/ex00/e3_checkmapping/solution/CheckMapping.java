import java.util.Scanner;


public class CheckMapping {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt(),d;
		boolean f[]=new boolean[n+1];
		for(int i=0;i<n;++i){
			d=kb.nextInt();
			if(d<1||d>n||f[d]){
				System.out.print("NO");
				return;
			}
			f[d]=true;
		}
		System.out.print("YES");
	}

}
