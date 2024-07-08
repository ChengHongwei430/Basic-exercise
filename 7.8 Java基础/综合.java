
import java.util.Scanner;

public class Main{
    
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNextInt()){
            
            int n = sc.nextInt();
            
            for(int i=0;i<n;++i){
                
                int a = sc.nextInt();
                int sum=0;
                for(int j=0;j<a;++j){
                    int b = sc.nextInt();
                    sum+=b;
                }
                System.out.println(sum);
                if(i!=n-1) System.out.println();
                
            }
            
            
        }
        
    }
    
}