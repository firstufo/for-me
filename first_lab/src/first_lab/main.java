package first_lab;
import java.util.Scanner;

public class main

{
  public static void main(String[] args)
    {
   Scanner in = new Scanner(System.in);
  
    System.out.println("Введите число начала промежутка");
    int a = in.nextInt();
    System.out.println("До какого числа вывести промежуток?");
    int b = in.nextInt();
      for (int i=a; i <= b; i++)
      {
          if (i == 0)
          {
            i++;
          }  
        int k=0;
        for (int j=1; j <= i; j++)
          {
            if (i % j == 0) k++;
          }
          if (k == 2)
          {
           System.out.println(i);
          }
        }
    in.close();
  }
}
