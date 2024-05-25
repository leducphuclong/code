using System;
using System.Text.RegularExpressions;
using CalculatorLibrary;

class Program
{
    static void Main(string[] args)
    {
        bool endApp = false;

        Console.WriteLine("Console Calculator in C#\n");
        Console.WriteLine("--------------------------");
    
        while (!endApp)
        {
            string numInput1, numInput2;
            int result;

            Console.Write("Type a number, and then press Enter: ");
            numInput1 = Console.ReadLine();

            int cleanNum1;
            while (!int.TryParse(numInput1, out cleanNum1))
            {
                Console.Write("This is not valid input. Please enter a numeric value: ");
                numInput1 = Console.ReadLine();
            }

            Console.Write("Type another number, and then press Enter: ");
            numInput2 = Console.ReadLine();

            int cleanNum2;
            while (!int.TryParse(numInput2, out cleanNum2))
            {
                Console.Write("This is not valid input. Please enter a numeric value: ");
                numInput2 = Console.ReadLine();
            }

            Console.WriteLine("Choose an operator from the following list:");
            Console.WriteLine("\ta - Add");
            Console.WriteLine("\ts - Subtract");
            Console.WriteLine("\tm - Multiply");
            Console.WriteLine("\td - Divide");
            Console.Write("Your option? ");

            string op = Console.ReadLine();

            if (op == null || !Regex.IsMatch(op, "[a|s|m|d]"))
            {
                Console.WriteLine("Error: Unrecognized operation");
            }
            else
            {
                try
                {
                    Calculator calculator = new Calculator();
                    result = calculator.DoOperation(cleanNum1, cleanNum2, op);
                    Console.WriteLine($"Your result: {result}\n");
                }
                catch (Exception e)
                {
                    Console.WriteLine($"An exception occurred: {e.Message}");
                }
 /           }

            Console.Write("Press 'n' and Enter to close the app, or press any other key and Enter to continue: ");
            if (Console.ReadLine() == "n")
                endApp = true;

            Console.WriteLine();
        }
    }
}
