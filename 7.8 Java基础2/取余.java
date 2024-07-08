


import java.util.ArrayList;
import java.util.Scanner;

public class Main{
    
    public static ArrayList<Integer> getArrayByNum(int num){
        
        ArrayList<Integer> ar = new ArrayList<Integer>();
        
        while(num!=0){
            ar.add(num%10);//取余，从个位开始
            num=num/10;
        }
        
        return ar;
        
    }
    
    public static void main(String[] Args){
        
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNextInt()){
            
            int x = sc.nextInt();
            
            ArrayList<Integer> ar = getArrayByNum(x);
            
            //System.out.println(x);//全是形参

            int sum=0;
            for(Integer i:ar){
                if(i%2==0) sum+=i;
            }
            
            System.out.println(sum);
            System.out.println();

        }
        
    }
    
    
    
}
