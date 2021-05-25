
public class Mai {

	public static void main(String[] args) {
		int x;
		int arr[] = new int[10001];
		
		for(x = 1; x <10000; x++) {
				int a = result(x);
				if( a <= 10000) {
					arr[a] = 1;
				}
				
		}
		for(int i =1 ; i < 10000; i++) {
			if(arr[i]!=1) {
				System.out.println(i);
			}
		}
	}
	public static int result(int x)  {
		int k = x;
		if(x >= 10000) {
			k += x/10000; x%=10000;
		}
		if(x >= 1000) {
			k+= x/1000; x%=1000;
		}
		if(x >= 100) {
			k+=x/100; x%=100;
		}
		if(x >= 10) {
			k+=x/10; x%=10;
		}
		return k+=x;
	}

}
