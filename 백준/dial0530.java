import java.util.Scanner;

public class Mai {

	public static void main(String[] args)  {
		Scanner sc = new Scanner (System.in);
		String a = sc.next();
		String[] arr = a.split(""); 
		int x = 0;
		for(int i = 0 ; i < a.length() ; i++) {
			switch(a.charAt(i)) {
			case 'A' : case 'B' : case 'C' : 
				x+=3;
				break;
			case 'D' : case 'E' : case 'F' : 
				x+=4;
				break;
			case 'G' : case 'H' : case 'I' : 
				x+=5;
				break;
			case 'J' : case 'K' : case 'L' : 
				x+=6;
				break;
			case 'M' : case 'N' : case 'O' : 
				x+=7;
				break;
			case 'P' : case 'Q' : case 'R' : case 'S':
				x+=8;
				break;
			case 'T' : case 'U' : case 'V' : 
				x+=9;
				break;
			case 'W' : case 'X' : case 'Y' :case 'Z': 
				x+=10;
				break;
			}
			
		}
		System.out.println(x);
	
		
		
	}

}
	

