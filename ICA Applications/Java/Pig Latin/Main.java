import java.util.Arrays;
import java.util.Scanner;

class Main {
  public static String pigLatin(String input) {
    char[] vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    String[] inputWords = input.split("\\W+"); // regex, matches all non-letter characters
    String[] outputWords = new String[inputWords.length];

    int rootIndex = 0;

    try {
      for (String i : inputWords) {
        String preVowel = "";
        String returnWord = "";

        //System.out.println( String.format("Word: %s", i) ); // REMOVE

        // STAGE 1: Obtain all consonants before the first vowel.
        boolean vowelReached = false;
        boolean invalidWord = false;
        int index = 0;

        while (!vowelReached) { // loop until a vowel is found
          for (char j : vowels) { // iterate through all possible vowels
            if (j == i.charAt(index)) {
              //System.out.println( String.format("Vowel detected: %s", j) ); // REMOVE
              vowelReached = true;
              break;
            }
          }
          if (!vowelReached) { // only run if vowel has still not been reached
            //System.out.println( String.format("Adding character: %s", String.valueOf(i.charAt(index))) ); // REMOVE
            preVowel += String.valueOf(i.charAt(index));
            index += 1;

            if (index == 1) {
              vowels = Arrays.copyOf(vowels, 12);
              vowels[10] = 'y'; // y is a vowel if not at the beginning
              vowels[11] = 'Y';
            } else if (index + 1 >= i.length()) { // no vowels in this word, return original
              vowelReached = true;
              invalidWord = true;
              returnWord = i;
              break;
            }
          }
        }

        if (!invalidWord) {
          // STAGE 2: Append "ay" or "way" depending on vowel location.

          if (index == 0) { // word started with a vowel, so we will take the rest of the word and append "way"
            returnWord = String.format("%sway", i);
          } else { // started with consonants; we will splice it as back, front, and "ay".
            String backToFront = i.substring(index);
            String frontToMid = preVowel;

            returnWord = String.format("%s%say", backToFront, frontToMid);
          }

          // STAGE 3: Capitalization/trimming.

          returnWord = returnWord.toLowerCase();

          //System.out.println( String.format("The first character is apparently %b", i.charAt(0)) ); // REMOVE
          //System.out.println(Character.isUpperCase(i.charAt(0))); // REMOVE

          if (Character.isUpperCase(i.charAt(0))) {
            returnWord = String.valueOf(returnWord.charAt(0)).toUpperCase() + returnWord.substring(1);
          }
        }

        outputWords[rootIndex] = returnWord;
        rootIndex += 1;
      }

      String output = String.join(" ", outputWords);

      return output+"."; // Currently no ability to return punctuation with implemented split/join method
    } catch(Exception e) {
      return "Unable to parse input";
    }
  }

  public static void main(String[] args) {
    System.out.println("Welcome to the Pig Latin translator!\n\nOr, as we like to say it,\nelcomeway otay ethay igpay atinlay anslatortray!\nCopyright (C) 2020 by Darren R. Skidmore\n");

    Scanner inputPhrase = new Scanner(System.in);

    while (true) {
      System.out.print("Input: ");
      System.out.println("Output: "+pigLatin( inputPhrase.nextLine() )+"\n\n");
    }
  }
}