import java.util.Scanner; // User input

class Main {
  // Method that returns an array of requested information
  public static String[] retrieveData() {
    String[] array = new String[2]; // Define the array with type String

    array[0] = "Darren R. Skidmore"; // Name
    array[1] = "Back to the Future"; // Favorite movie

    return array;
  }

  public static void main(String[] args) {
    String[] data = retrieveData(); // Set the array as the return value of retrieveData();
    String[] yourData = new String[2]; // Prepare for user input

    System.out.println( String.format("My name is %s,\nand my favorite movie is %s.", data[0], data[1]) ); // Print the string using formatting

    System.out.println("\nNow, tell me about yourself!\n");

    Scanner input = new Scanner(System.in); // Define the user input scanner

    System.out.println("What is your name? >");
    yourData[0] = input.nextLine(); // User input: name

    System.out.println("\nWhat is your favorite movie? >");
    yourData[1] = input.nextLine(); // User input: favorite movie

    System.out.println( String.format("\nNice to meet you, %s. I also like the movie %s!", yourData[0], yourData[1]) ); // Print the string using formatting
  }
}