import java.util.Scanner;

public class Mai {

	public static void main(String[] args)  {
		Scanner sc = new Scanner (System.in);
		String a = sc.next();
		String b = sc.next();
		String result = "";
		String result1 = "";
		int x = 0;
		int y = 0;
		String[] arr = a.split("");
		String[] arr1 = b.split("");
		for(int i = 2; i >=0 ; i--) {
			result += arr[i];
			result1 += arr1[i];
		}
		
		
		
		if(Integer.parseInt(result1)>Integer.parseInt(result)) {
			System.out.println(Integer.parseInt(result1));
		}
		else
			System.out.println(Integer.parseInt(result));
		
		
	}

}
	

