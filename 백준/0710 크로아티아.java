	import java.io.BufferedReader;
	import java.io.IOException;
	import java.io.InputStreamReader;
	import java.util.StringTokenizer;
	import java.util.Scanner;
	
	public class Main {
	
		public static void main(String[] args) throws NumberFormatException, IOException {
			Scanner sc = new Scanner(System.in);
			String a = sc.next();
			int cnt = 0;
			for(int i = 0; i < a.length(); i++) {
				char ch = a.charAt(i);
				if(ch == 'c') {
					if(i+1 < a.length()) {
						if(a.charAt(i+1)=='=') {
							i++;
						}
						else if(a.charAt(i+1)=='-') {
						
							i++;
						}
					}
				}
				else if(ch == 'd') {
					if(i+1 < a.length()) {
						if(a.charAt(i+1)=='z') {
							if(i+2 < a.length()) {
								if(a.charAt(i+2)=='=') {
									i++;
									i++;
								}
							}
						}
						else if(a.charAt(i+1)=='-') {
					
							i++;
						}
					}
				}
				else if(ch == 'l') {
					if(i+1 < a.length()) {
						if(a.charAt(i+1)=='j') {
							
							i++;
						}
					}
				}
				else if(ch == 'n') {
					if(i+1 < a.length()) {
						if(a.charAt(i+1)=='j') {
						
							i++;
						}
					}
				}
				else if(ch == 's') {
					if(i+1 < a.length()) {
						if(a.charAt(i+1)=='=') {
							
							i++;
						}
					}
				}
				else if(ch == 'z') {
					if(i+1 < a.length()) {
						if(a.charAt(i+1)=='=') {
							i++;
						}
					}
				}
				cnt++;
				}
			System.out.println(cnt);
		}
		
	}
			

		
