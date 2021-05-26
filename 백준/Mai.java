import java.util.Scanner;


public class Mai {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x;
		int y = 0;
		x = sc.nextInt();
		for(int i = 1 ; i < 10; i++) {
			y = x * i;
			System.out.printf("%d * %d = %d%n", x ,i ,y);
		}
	
	}
	

}
