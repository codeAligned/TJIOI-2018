import java.io.*;


public class prime {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(f.readLine());
        switch(n) {
            case 1: System.out.println(4); break;
            case 2: System.out.println(4); break;
            case 3: System.out.println(4); break;
            case 4: System.out.println(2); break;
            case 6: System.out.println(1); break;
            default: System.out.println(0);
        }
    }
}
