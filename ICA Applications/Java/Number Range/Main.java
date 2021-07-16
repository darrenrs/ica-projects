import java.util.Scanner; // User input
import java.util.Random; // RNG
import java.lang.Math; // Necessary for log2

class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in); // Define the user input scanner

    boolean minimaSet = false; // controls while loops
    boolean maximaSet = false;
    int minimaInt = 0; // integer storage (not set at this time)
    int maximaInt = 0;

    System.out.println("Welcome to Number Range. In this game, you will need to guess the correct number.\n");

    /*
      Locks execution until an integer is chosen.
    */
    while (!minimaSet) {
      System.out.print("Choose the minima of the range > ");
      String minimaString = input.nextLine();

      if (isInteger(minimaString)) {
        minimaInt = Integer.parseInt(minimaString);
        minimaSet = true;
      } else {
        System.out.println( String.format("The string \"%s\" is not an integer. Please try again.\n", minimaInt) );
      }
    }

    /*
      Locks execution until an integer that is GREATER THAN the minima is chosen.
    */
    while (!maximaSet) {
      System.out.print("Choose the maxima of the range > ");
      String maximaString = input.nextLine();

      if (isInteger(maximaString)) {
        if (Integer.parseInt(maximaString) > minimaInt) {
          maximaInt = Integer.parseInt(maximaString);
          maximaSet = true;
        } else {
          System.out.println( String.format("The integer %s is less or equal to %d. Please try again.\n", maximaString, minimaInt) );
        }
      } else {
        System.out.println( String.format("The string \"%s\" is not an integer. Please try again.\n", maximaInt) );
      }
    }

    int par = parGuesses(maximaInt - minimaInt);
    int randomNumber = randomNumber(minimaInt, maximaInt); // generates a random number
    int guesses = 1;
    boolean hasGuessedCorrectly = false; // main loop

    System.out.println( String.format("\nYou must guess a number between %d and %d. The par is %d.\n\nLet's begin!", minimaInt, maximaInt, par) );

    while (!hasGuessedCorrectly) {
      System.out.print( String.format("\nGuess %d > ", guesses) );
      String lastGuess = input.nextLine();

      if (isInteger(lastGuess)) { // Guess was an integer, proceed to check
        int lastGuessInt = Integer.parseInt(lastGuess);

        if (lastGuessInt == randomNumber) { // correct guess
          System.out.println( String.format("You guessed the number correctly within %d guesses!", guesses) );

          if (guesses > par) {
            System.out.println( String.format("Pathetic job. You took %d attempts, while the par was %d attempts.", guesses, par) );
          } else if (guesses == par) {
            System.out.println( String.format("Not bad. You took %d attempts to guess the number, which was equivalent to the par.", guesses) );
          } else {
            System.out.println( String.format("Well done! Although the par was %d, you managed to guess the number within %d attempts.", par, guesses) );
          }
          System.out.println( String.format("Estimated I.Q.: %d", estimatedIQ(par, guesses)) );

          hasGuessedCorrectly = true;
        } else { // incorrect guess
          String direction = "";

          if (lastGuessInt > randomNumber) {
            direction = "LOWER";
          } else {
            direction = "HIGHER";
          }

          System.out.println( String.format("%d is wrong! I implore you to go %s.", lastGuessInt, direction) );

          guesses += 1;
        }

      } else { // not an int
        System.out.println( String.format("The string \"%s\" is not an integer. Please try again.", minimaInt) );
      }

    }
    System.out.println("\n\nCopyright (C) 2020 by Darren R. Skidmore");
  }

  /*
    Checks if string can be represented as int
  */
  public static boolean isInteger(String input) {
    try {
      Integer.parseInt(input);
      return true;
    } catch(Exception e) {
      return false;
    }
  }

  /*
    Returns a random int given a minimum and maximum
  */
  public static int randomNumber(int minimaInt, int maximaInt) {
    Random rng = new Random(); // RNG

    int generatedBase = rng.nextInt(maximaInt - minimaInt + 1);
    int generatedIntercept = generatedBase + minimaInt;

    return generatedIntercept;
  }

  /*
    Calculates the par guesses based on the log2 model
  */
  public static int parGuesses(int range) {
    double log2 = Math.log(range)/Math.log(2);
    int logFloor = (int)Math.floor(log2)+1;

    return logFloor;
  }

  /*
    Estimated I.Q. based on ratio model (not SS)
  */
  public static int estimatedIQ(int par, int guesses) {
    double ratio = ((double)par / (double)guesses)*100;

    int ratioInt = (int)Math.round(ratio);

    return ratioInt;
  }
}