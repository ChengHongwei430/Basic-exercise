

import java.util.ArrayList;
import java.util.Scanner;

public class Main{
    
    public static void main(String[] Args){
        
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNextInt()){
            
            ArrayList<Integer> ar = new ArrayList<Integer>();
            
            int n = sc.nextInt();
            if(n==0) break;
            
            int sum=0;
            for(int i=0;i<n;++i){
                int x = sc.nextInt();
                ar.add(x);
                sum+=x;
            }
            int mid = sum/n;
            
            int de=0;
            for(Integer i:ar){
                if(i>mid) de+=i-mid;
            }
            
            System.out.println(de);
            System.out.println();

        }
        
    }
    
}
