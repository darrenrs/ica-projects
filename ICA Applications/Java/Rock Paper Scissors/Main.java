// Modified in Eclipse and transferred to repl.it at 2020-09-22T20:23:36-06:00

import java.util.Scanner;
import java.util.Random; // RNG

class Main {
  public static String[] validMovesLongDb() {
    String[] r = {"ROCK", "PAPER", "SCISSORS"};

    return r;
  }

  public static String[] validMovesShortDb() {
    String[] r = {"R", "P", "S"};
    
    return r;
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

  public static String intPadding(int rounds) {
    if (rounds >= 10) {
      return "";
    } else {
      return " ";
    }
  }

  public static String namePadding(String name) {
    int maxLength = 31;
    int spaceInsert = maxLength - name.length();
    String provisionalString = "";

    while (provisionalString.length() < spaceInsert) {
      provisionalString += " ";
    }

    provisionalString += name;

    return provisionalString;
  }

  public static int checkWinner(int player, int computer) {
    /*
       -1  No victory
        0  Player victory
        1  Computer victory

        Yes this code sucks.
    */
    int returnInt = 0;

    switch (player) {
      case 0:
        switch (computer) {
          case 1:
            System.out.print("PAPER covers ROCK.\n");
            returnInt = 1;
            break;
          case 2:
            System.out.print("ROCK breaks SCISSORS.\n");
            returnInt = 0;
            break;
          default:
            System.out.print("ROCK neutralizes ROCK.\n");
            returnInt =-1;
        }
        break;
      case 1:
        switch (computer) {
          case 0:
            System.out.print("PAPER covers ROCK.\n");
            returnInt = 0;
            break;
          case 2:
            System.out.print("SCISSORS cuts PAPER.\n");
            returnInt = 1;
            break;
          default:
            System.out.print("PAPER neutralizes PAPER.\n");
            returnInt =-1;
            break;
        }
        break;
      case 2:
        switch (computer) {
          case 0:
            System.out.print("ROCK breaks SCISSORS.\n");
            returnInt = 1;
            break;
          case 1:
            System.out.print("SCISSORS cuts PAPER.\n");
            returnInt = 0;
            break;
          default:
            System.out.print("SCISSORS neutralizes SCISSORS.\n");
            returnInt =-1;
        }
        break;
    }

    return returnInt;
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    boolean roundsSet = false;
    boolean nameSet = false;
    int currentRound = 1;
    int cpuScore = 0;
    int plrScore = 0;

    String name = "";
    int rounds = 0;

    System.out.print("Welcome to Rock Paper Scissors!\nCopyright (C) 2020 Darren R. Skidmore. All rights reserved.\n\n");
    
    while (!nameSet) {
      System.out.print("Please enter your name > ");

      name = input.nextLine();

      if (name.length() <= 31) {
        nameSet = true;
      } else {
        System.out.print("Invalid input; name is too long (maximum 31 chars).\n");
      }
    }

    while (!roundsSet) {
      System.out.printf("%s, how many rounds would you like to play? > ", name);
      try {
        rounds = input.nextInt();

        if (rounds % 2 > 0 && rounds < 100) {
          System.out.print("\n\n");
          roundsSet = true;
        } else if (rounds % 2 == 0) {
          System.out.print("Invalid input; odd number required.\n");
        } else {
          System.out.print("Invalid input; too many rounds (maximum 99).\n");
        }
      } catch (Exception e) {
        System.out.print("Invalid input; integer required.\n");
      }
    }

    while (currentRound <= rounds) {
      String namePad = namePadding(name);
      boolean moveSet = false;
      int moveIndex = 0;

      System.out.printf(
        "/-------------------------------------\\\n| ROCK, PAPER, SCISSORS               |\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n|                       ROUND %s%d / %s%d |\n|                                     |\n|                                     |\n| Computer: %s%d                        |\n|~~~~~~~~~~~~~~~~ vs. ~~~~~~~~~~~~~~~~|\n| %s: %s%d |\n\\-------------------------------------/\n\n",
        intPadding(currentRound), currentRound, intPadding(rounds), rounds, intPadding(cpuScore), cpuScore, namePad, intPadding(plrScore), plrScore
      );

      while (!moveSet) {
        String[] movesDbLong = validMovesLongDb();
        String[] movesDbShort = validMovesShortDb();
        int provisionalIndex = 0;

        String printValidMoves = String.format( String.join(",", movesDbShort) );
        System.out.printf("Make your move! [R/P/S] > ", printValidMoves);

        String move = input.nextLine();
        
        for (String s : movesDbShort) {
          String moveMutated = move.toUpperCase().trim();

          if (moveMutated.equals(s)) { // match found
            moveIndex = provisionalIndex;
            moveSet = true;
            break;
          } else {
            provisionalIndex += 1;
          }
        }

        provisionalIndex = 0; // reset index

        for (String s : movesDbLong) {
          String moveMutated = move.toUpperCase().trim();

          if (moveMutated.equals(s)) { // match found
            moveIndex = provisionalIndex;
            moveSet = true;
            break;
          } else {
            provisionalIndex += 1;
          }
        }

        if (!moveSet) {
          if (move.equals("")) { // ok boss, not sure why this is necessary
            System.out.print("For some reason the first run passes NUL, so just ignore this message.\n");
          } else {
            System.out.printf("Invalid input; no match found for %s.\n\n", move);
          }
        }
      }

      int computerRNG = randomNumber(0, 2);
      int winner = checkWinner(moveIndex, computerRNG);

      switch (winner) {
        case -1:
          System.out.printf("A tie occurred! :/\n");
          break;
        case  0:
          currentRound += 1;
          plrScore += 1;
          System.out.printf("%s won this round! >:)\n", name);
          break;
        case  1:
          currentRound += 1;
          cpuScore += 1;
          System.out.printf("The System won this round! >:(\n");
          break;
      }
      
      System.out.print("\n");

    }
    
    if (cpuScore > plrScore) {
      System.out.printf("Unfortunately, the System managed to beat you, %s!\n", name);
      if (cpuScore > plrScore + 1) {
        System.out.printf("You were thrashed, losing by %d points.", cpuScore-plrScore);
      } else {
        System.out.print("Close game! You only lost by one point...");
      }
    } else {
      System.out.printf("Well done, %s! You usurped the System.\n", name);
      if (plrScore > cpuScore + 1) {
        System.out.printf("You annihilated the System, winning by %d points.", plrScore-cpuScore);
      } else {
        System.out.print("Close game! You only won by one point, but that's still something!");
      }
    }
    
    System.out.print("\n");
  }
}