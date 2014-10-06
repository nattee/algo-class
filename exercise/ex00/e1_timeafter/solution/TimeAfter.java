import java.util.Scanner;

public class TimeAfter {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int h=kb.nextInt(),m=kb.nextInt(),x=kb.nextInt();
		m+=x%60;
		h=(h+x/60+m/60)%24;
		m%=60;
		System.out.print((h>9?h:("0"+h))+" "+(m>9?m:("0"+m)));
	}

}
