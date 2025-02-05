// Arturo Gonzalez
// CSC 321
// Lab #4

import java.util.Scanner;

public class agonzalez4
{
	public static void main(String[] args)
	{
		System.out.println("Choose an option from 1-4: ");
		Scanner user_in = new Scanner(System.in);
		int choice = user_in.nextInt();

		if(choice == 1)
		{
			System.out.println("Hello There!");}
		else if(choice == 2)
		{
			System.out.println("It sure is a fine day.");}
		else if(choice == 3)
		{
			System.out.println("Hamburger with onions please.");}
		else
		{
			System.out.println("The final option has been chosen");}
	}
}
