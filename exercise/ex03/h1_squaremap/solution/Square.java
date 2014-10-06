import java.util.Scanner;

public class Square {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int lastC,
			ans,
			R=kb.nextInt(),
			C=kb.nextInt(),
			grid[]=new int[C];
		String row=kb.next();
		for(int c=0;c<C;++c)
			grid[c]=row.charAt(c)-'0';
		ans=row.indexOf('1')<0?0:1;
		for(int r=1;r<R;++r){
			row=kb.next();
			lastC=grid[0];
			grid[0]=row.charAt(0)-'0';
			for(int c=1;c<C;++c){
				int tmp=grid[c];
				grid[c]=row.charAt(c)=='0'?0:(Math.min(grid[c], Math.min(grid[c-1], lastC))+1);
				lastC=tmp;
				ans=Math.max(ans, grid[c]);
			}
		}
		System.out.print(ans);

	}

}
