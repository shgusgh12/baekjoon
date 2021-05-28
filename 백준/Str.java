import java.util.Scanner;

public class Str {

	public static void main(String[] args)  {
		Scanner sc = new Scanner (System.in);
		String x = sc.nextLine();
		String word = "";
		int cnt =0;
		for(int i=0; i<x.length(); i++) {
			String c = String.valueOf(x.charAt(i));
			if(c.equals(" ")) {
				word = "";
			}
			else {
				if(word.length()==0) {
					cnt++;
				}
				word = c;
			}
			
			
		}
		System.out.println(cnt);
	}
		
}
	

