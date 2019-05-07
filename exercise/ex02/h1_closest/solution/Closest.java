import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Closest {
	static class Reader {
		static BufferedReader reader;
		static StringTokenizer tokenizer;

		/** call this method to initialize reader for InputStream */
		static void init(InputStream input) {
			reader = new BufferedReader(
						 new InputStreamReader(input) );
			tokenizer = new StringTokenizer("");
		}

		/** get next word */
		static String next() throws IOException {
			while ( ! tokenizer.hasMoreTokens() ) {
				tokenizer = new StringTokenizer(reader.readLine());
			}
			return tokenizer.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt( next() );
		}
	}
	static Point[] px;
	static int minDist=1800000000;
	static Comparator<Point>
	xComparator=new Comparator<Point>() {
		@Override
		public int compare(Point a, Point b) {
			return a.x==b.x?a.y-b.y:a.x-b.x;
		}
	},
	yComparator=new Comparator<Point>() {
		@Override
		public int compare(Point a, Point b) {
			return a.y==b.y?a.x-b.x:a.y-b.y;
		}
	};

	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		int n=Reader.nextInt(),x,y;
		px=new Point[n];
		for(int i=0;i<n;++i) {
			x=Reader.nextInt();
			y=Reader.nextInt();
			px[i]=new Point(x, y);
		}
		Arrays.sort(px,xComparator);
		System.out.println(minDist(0,n));
	}

	static int minDist(int l, int r) {
		if(l+1==r) return minDist;
		int mid=(l+r)/2,
			dist=(int)Math.ceil(Math.sqrt(Math.min(minDist(l, mid), minDist(mid, r)))),
			up=0,
			down=0;
		l = Arrays.binarySearch(px, l, mid, new Point(px[mid].x - dist + 1, px[mid].y - dist + 1), xComparator);
		r = Arrays.binarySearch(px, mid, r, new Point(px[mid].x + dist - 1, px[mid].x + dist), xComparator);
		l=l<0?-l-1:l;
		r=r<0?-r-1:r;
		Point[] pls=Arrays.copyOfRange(px, l, mid),
				prs=Arrays.copyOfRange(px, mid, r);
		int lenR=r-mid;
		Arrays.sort(pls,yComparator);
		Arrays.sort(prs,yComparator);
		for(Point pl : pls) {
			while(down<lenR-1&&pl.y-prs[down].y>=dist) ++down;
			while(up<lenR&&prs[up].y-pl.y<dist) ++up;
			for(int i=down;i<up;++i) {
				int dx=pl.x-prs[i].x,
					dy=pl.y-prs[i].y;
				minDist=Math.min(minDist,dx*dx+dy*dy);
			}
		}
		return minDist;
	}

}