import java.util.Scanner;


public class Mai {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x;
		x =sc.nextInt();
		int[] arr = new int[x];
		int[] arr2 = new int[x];
		int[] arr3 = new int[x];
		for(int i = 0 ; i < x ; i++) {
			arr2[i] = sc.nextInt();
			arr3[i] = sc.nextInt();
			arr[i] = arr2[i] + arr3[i];
		}
		for(int i = 0 ; i < x ; i++) {
			System.out.printf("Case #%d: %d + %d = %d%n",i+1,arr2[i],arr3[i], arr[i] );
		}
	}
	

}
