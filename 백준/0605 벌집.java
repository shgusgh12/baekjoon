import java.util.Scanner;

public class Mai {

	public static void main(String[] args)  {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int answer = 0;
		int result = 2;
		int last = 7;
		for(int i = 0; i < 10000000; i++) {
			if(a==1)
			{
				answer=1;
				break;
			}
			else if(result<=a&&a<=last) {
				answer = (last-result+1)/6+1; 
				break;
			}
			result = result+6*(i+1);
			last = last+(6+6*(i+1));
			
		}
		System.out.println(answer);
	}
}
	

