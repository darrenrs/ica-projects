import java.util.Scanner; // User input

class Main {
  public static int stringToInt(String string) { // converts a string integer to a pure integer
    String stringNoComma = string.replaceAll(",", ""); // remove commas
    int stringIntRepresentation = Integer.parseInt( stringNoComma ); // convert to int

    return stringIntRepresentation;
  }

  public static int[] speedOffsets(int speedLimit, int interval, int minima, int maxima) { // returns array of speed offsets
    int[] returnArray = new int[minima*-1 + maxima + 1];

    for (int i = 0; i <= minima*-1 + maxima; i++) {
      returnArray[i] = interval*i + speedLimit + minima*interval;
    }

    return returnArray;
  }

  public static void main(String[] args) {
    // Required variables
    String destination = "";
    int miles = 0;
    int speedLimit = 0;

    int interval = 2;
    int minima = -5;
    int maxima = 10;

    Scanner input = new Scanner(System.in); // Define the user input scanner

    System.out.println("Hello, traveler!");
    System.out.println("Where is your destination? >");

    destination = input.nextLine(); // User input: Destination

    System.out.println( String.format("\nHow far away in miles is %s? >", destination) );

    miles = stringToInt( input.nextLine() ); // User input: Miles (converted to int)

    System.out.println("\nMuch to your chagrin, speed limits still exist, even in code.");
    System.out.println( String.format("What is the average speed limit in miles per hour during your trip to %s?", destination) );

    speedLimit = stringToInt( input.nextLine() ); // User input: Speed Limit (converted to int)

    int[] speedLimits = speedOffsets(speedLimit, interval, minima, maxima);

    System.out.println("\nSpeed  Offset   Time          Time Saved\n-----------------------------------");

    for (int i = 0; i < speedLimits.length; i++) {
      double speed = speedLimits[i];
      double offset = speed-speedLimit;
      double timeHours = miles / speed;
      double timeSave = (miles/speedLimit)-timeHours;

      /*
      String speedString = Double.toString(speed);
      String offsetString = Double.toString(offset);
      String timeHoursString = Double.toString(timeHours);
      String timeSaveString = Double.toString(timeSave);
      */

      System.out.println( String.format(
        "%.0f mph %.0f mph  %.2f hours %.2f hours",
        speed, offset, timeHours, timeSave) ); // extremely ugly
    }
  }
}