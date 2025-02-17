import java.util.*;

public class faltud {

    static class A{
        static int a = 20;
        A(){
            a += 5;
        }
    }
    public static void main(String[] args) {

        A a1 = new A();
        A a2 = new A();

        System.out.println(A.a);


       
    }
}
