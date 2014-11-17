import java.util.Scanner;

public class Inversion {
	// O(nlogn)
	static int a[];
	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt();
		a=new int[n];
		for(int i=0;i<n;++i)
			a[i]=kb.nextInt();
		System.out.print(msort(0,n));
	}
	
	static int msort(int l,int r){
		if(l+1==r) return 0;
		int tmp[]=new int[r-l],
			mid=(l+r)/2,
			i=l,
			j=mid,
			k=0,
			ret=msort(l,mid)+msort(mid,r);
		while(i<mid&&j<r)
			if(a[i]>a[j]){
				tmp[k++]=a[j++];
				ret+=mid-i;
			}
			else
				tmp[k++]=a[i++];
		while(i<mid) tmp[k++]=a[i++];
		while(j<r) tmp[k++]=a[j++];
		System.arraycopy(tmp, 0, a, l, k);
		return ret;
	}
}
