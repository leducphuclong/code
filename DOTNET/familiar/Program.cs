// See https://aka.ms/new-console-template for more information
using System;


class Program {
    static void Main(string[] args) {
        Console.Write("Enter a string: ");
        int userinput = Console.Read();
        if (userinput != 0)
            Console.WriteLine((char)(userinput));

    }
}
