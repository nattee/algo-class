import java.util.Arrays;
import java.util.Scanner;

public class Gaa2 {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		int n=kb.nextInt();
		String g="gaa",G="";
		while(G.length()<n){
			G+=g+G;
			g+='a';
		}
		System.out.print(G.charAt(n-1));
	}

}
