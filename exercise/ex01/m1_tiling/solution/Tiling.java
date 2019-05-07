import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Tiling {

	static int[] type=new int[]{0,1,2,3};
	static OutputStreamWriter out = new OutputStreamWriter(System.out);

	public static void main(String[] args) throws IOException {
		int l,x,y;
		Scanner kb=new Scanner(System.in);
		l=kb.nextInt();
		x=kb.nextInt();
		y=kb.nextInt();
		System.out.println(l*l/3);
		tile(l,0,0,x,y);
		out.flush();
	}

	static void tile(int l,int xx,int yy,int x,int y) throws IOException {
		int mode;
		if(l==2) {
			mode=type[x+(y<<1)];
			if((mode&1)==1) --x;
			if(mode>1) --y;
//			System.out.println(mode+" "+(xx+x)+" "+(yy+y));
			out.write(mode+" "+(xx+x)+" "+(yy+y));
			out.write('\n');
			return;
		}
		l>>=1;
		int midx=xx+l,midy=yy+l;
		if(y<l) {
			tile(l,xx,midy,l-1,0);
			tile(l,midx,midy,0,0);
			if(x<l) {
				tile(l,xx,yy,x,y);
				tile(l,midx,yy,0,l-1);
				mode=0;
			}
			else {
				tile(l,xx,yy,l-1,l-1);
				tile(l,midx,yy,x-l,y);
				mode=1;
			}
		}
		else {
			tile(l,xx,yy,l-1,l-1);
			tile(l,midx,yy,0,l-1);
			if(x<l) {
				tile(l,xx,midy,x,y-l);
				tile(l,midx,midy,0,0);
				mode=2;
			}
			else {
				tile(l,xx,midy,l-1,0);
				tile(l,midx,midy,x-l,y-l);
				mode=3;
			}
		}
//		System.out.println(mode+" "+(xx+l-1)+" "+(yy+l-1));
		out.write(mode+" "+(xx+l-1)+" "+(yy+l-1));
		out.write('\n');
	}

}
