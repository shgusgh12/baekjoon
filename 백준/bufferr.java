import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Mai {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int x;
		x = Integer.parseInt(bf.readLine());
		for(int i = 0; i < x; i++) {
			String a = bf.readLine();
			int y = Integer.parseInt(a.split(" ")[0]);
			int z = Integer.parseInt(a.split(" ")[1]);
			bw.write(y+z+"\n");
		}
	
		bw.flush();   
		 
	}
	

}
