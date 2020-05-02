package first_lab;

import java.util.Scanner;

public class main

{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Введите промежуток от");
		int a = in.nextInt();
		try {
			if (a <= 0)
				throw new IllegalArgumentException("1ое число не простое");
		} catch (IllegalArgumentException e) {
			System.out.println("Должны быть только простые числа");
			in.nextInt();
		}
		System.out.println("До какого числа вывести промежуток?");
		int b = in.nextInt();
		try {
			if (b <= 0)
				throw new IllegalArgumentException("2ое число не простое");
		}

		catch (IllegalArgumentException e) {
			System.out.println("Должны быть только простые числа");
			b = in.nextInt();
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
