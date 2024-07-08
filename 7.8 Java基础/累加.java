
import java.util.Scanner;

public class Main{

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()){

            int n = sc.nextInt();
            if(n==0) break;
            int sum=0;
            for(int i=0;i<n;++i){
                int x = sc.nextInt();
                sum+=x;
            }
            System.out.println(sum);

        }

    }

}