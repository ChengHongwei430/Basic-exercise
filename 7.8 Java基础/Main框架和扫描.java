
import java.util.Scanner;

public class Main{
    
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);//创建一个扫描实例，将键盘输入放入
        
        while(sc.hasNextInt()){
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(a+b);
        }
        
    }
   
}

/*
1、Java Main方法框架写法
public class Main{
    public static void main(String[] args){ }
}


2、扫描函数写法
import java.util.Scanner;
Scanner sc = new Scanner(System.in);
while(sc.hasNextInt())
int a = sc.nextInt();

*/

