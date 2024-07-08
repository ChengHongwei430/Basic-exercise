
import java.util.ArrayList;
import java.util.Scanner;

public class Main{
    
    public static void main(String[] Args){
        
        Scanner sc = new Scanner(System.in);
        
        ArrayList<Integer> ar = new ArrayList<Integer>();
        
        while(sc.hasNextInt()){
            
            int n = sc.nextInt();
            
            for(int i=0;i<n;++i) ar.add(sc.nextInt());
            
            for(int i=n-1;i>=0;--i){
                System.out.print(ar.get(i));
                //不能写成ar[i]，要写
                if(i!=0) System.out.print(" ");
            }
            
            for(int i=0;i<n;i+=2){
                System.out.print(ar.get(i));
                if(i!=0) System.out.print(" ");
            }

        }
        
    }
    
}

/*
3、集合ArrayList的用法
import java.util.ArrayList;//包
ArrayList<Integer> ar = new ArrayList<Integer>();//新建方法
ar.add();//添加
ar.remove();//删除
ar.get(i);//查找,不能使用ar[i]的方式进行查询
ar.size();//长度
*/


