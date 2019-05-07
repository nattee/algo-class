import java.util.Scanner;

public class Celeb {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		boolean known[]=new boolean[1000],k;
		int n=kb.nextInt(),noNoOne=-1;
		for(int i=0;i<n;++i) {
			boolean know=false;
			for(int j=0;j<n;++j) {
				k=kb.nextInt()==1;
				know|=k;
				if(i!=j)
					known[j]|=!k;
			}
			if(!know) {
				noNoOne=i;
			}
		}
		System.out.println(noNoOne>=0&&!known[noNoOne]?noNoOne+1:0);
	}

}
