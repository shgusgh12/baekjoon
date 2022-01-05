	import java.io.BufferedReader;
	import java.io.IOException;
	import java.io.InputStreamReader;
	import java.util.StringTokenizer;
	import java.util.Scanner;
	
	public class Main {
	
		public static void main(String[] args)  {
			Scanner sc = new Scanner(System.in);
			int N = sc.nextInt();
			int x, y;
			
			
			int x1=0, y1=0, r1=0, x2=0, y2=0, r2=0;
			for (int i = 0; i < N; i++)
			{
				x1 = sc.nextInt();
				y1 = sc.nextInt();
				r1 = sc.nextInt();
				x2 = sc.nextInt();
				y2 = sc.nextInt();
				r2 = sc.nextInt();
				
				System.out.println(point(x1, y1, r1, x2, y2, r2));
			
				
			}
			
			
		}
		public static int point(int x1, int y1, int r1, int x2, int y2, int r2)
		{
			int len = (int)(Math.pow(x1 - x2,2) + Math.pow(y1 - y2, 2));
			
			
			if(x1 == x2 && y1 == y2 && r1==r2)
			{
				return -1;
			}
			else if(len > Math.pow(r1+r2,2))
			{
				return 0;
			}
			else if(len == Math.pow(r1 - r2, 2))
			{
				return 1;
			}
			else if(len < Math.pow(r1 - r2, 2))
			{
				return 0;
			}
			else if(len == Math.pow(r1 + r2, 2))
			{
				return 1;
			}
			else 
				return 2;
		}
	}
			

		
