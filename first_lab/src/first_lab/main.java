package first_lab;

import java.util.Scanner;
import java.util.InputMismatchException;

public class main

{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Введите промежуток от");
		int a;

		while (true) {
			try {
				a = Integer.parseInt(in.next());
				if (a <= 0)
					throw new IllegalArgumentException("1ое число не натуральное");

				break;
			} catch (NumberFormatException e) {
				System.out.println("Ввод должен состять только из цифр");
			} catch (IllegalArgumentException e) {
				System.out.println("Должны быть только натуральные числа");
			}
		}

		System.out.println("До какого числа вывести промежуток?");
		int b;
		while (true) {
			try {
				b = Integer.parseInt(in.next());
				if (b <= 0)
					throw new IllegalArgumentException("1ое число не натуральное");
				break;
			} catch (NumberFormatException e) {
				System.out.println("Ввод должен состять только из цифр");
			} catch (IllegalArgumentException e) {
				System.out.println("Должны быть только натуральные числа");
			}
		}

		for (int i = a; i <= b; i++) {
			if (i == 0) {
				i++;
			}
			int k = 0;
			for (int j = 1; j <= i; j++) {
				if (i % j == 0)
					k++;
			}
			if (k == 2) {
				System.out.println(i);
			}
		}
		in.close();
	}
}
