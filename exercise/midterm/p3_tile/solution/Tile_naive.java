import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Tile2 {

	static int N;
	static ArrayList<ArrayList<ArrayList<int[]>>> dp;
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		N=kb.nextInt();
		int m=kb.nextInt(),
			a[]=new int[N],
			ans=98010;
		dp=new ArrayList<ArrayList<ArrayList<int[]>>>(N);
		for(int i=0;i<N;++i){
			dp.add(new ArrayList<ArrayList<int[]>>(m+1));
			dp.get(i).add(new ArrayList<int[]>());
			for(int j=0;j<m;++j)
				dp.get(i).add(null);
		}
		for(int i=0;i<N;++i)
			a[i]=kb.nextInt();
		Arrays.sort(a);
		ArrayList<int[]> al=com(N-1,m,100);
		if(al.size()==0)
			System.out.print(-1);
		else{
			for(int[] arr : al){
				Arrays.sort(arr);
				int cost=0;
				for(int i=0;i<N;++i)
					cost+=(arr[i]-a[i])*(arr[i]-a[i]);
				ans=Math.min(ans, cost);
			}
			System.out.print(ans);
		}
	}
	static ArrayList<int[]> com(int n,int m,int lim){
		if(dp.get(n).get(m)!=null)
			return dp.get(n).get(m);
		ArrayList<int[]> ret=new ArrayList<int[]>();
		int isq=(int)Math.sqrt(m);
		if(n==0){
			if(isq*isq==m){
				int tmp[]=new int[N];
				tmp[0]=isq;
				ret.add(tmp);
			}
		}
		else{
			lim=Math.min(lim, isq);
			for(int i=1;i<=lim;++i){
				ArrayList<int[]> list=com(n-1,m-i*i,lim);
				for(int[] arr : list){
					int[] tmp=Arrays.copyOf(arr, N);
					tmp[n]=i;
					ret.add(tmp);
				}
			}
		}
		dp.get(n).set(m,ret);
		return ret;
	}

}
