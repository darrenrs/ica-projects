class InputVerification {
  protected static boolean inputValidBool0(String valueString) {
    char firstCharacter = valueString.strip().toLowerCase().charAt(0);

    if (firstCharacter == 'y' || firstCharacter == 'n') {
      return true;
    } else {
      System.out.println("\nPlease enter YES or NO!\n");
      return false;
    }
  }

  protected static boolean inputValidVal0(String valueString) {
    char firstCharacter = valueString.strip().toLowerCase().charAt(0);

    if (firstCharacter == 'y') {
      return true;
    } else {
      return false;
    }
  }

  protected static boolean inputValidBool4(String valueString) {
    char firstCharacter = valueString.strip().toLowerCase().charAt(0);

    if (firstCharacter == 'm' || firstCharacter == 'f' || firstCharacter == 'b' || firstCharacter == 'g') {
      return true;
    } else {
      System.out.println("\nPlease enter MALE or FEMALE!\n");
      return false;
    }
  }

  protected static boolean inputValidVal4(String valueString) {
    char firstCharacter = valueString.strip().toLowerCase().charAt(0);

    if (firstCharacter == 'm' || firstCharacter == 'b') {
      return true;
    } else {
      return false;
    }
  }

  protected static boolean inputValidBool12(String valueString) {
    double valueDouble = 0.00;

    try {
      valueDouble = Double.parseDouble(valueString); 
    } catch (NumberFormatException e) {
      System.out.println("\nPlease enter a NUMBER!\n");
      return false;
    }

    if (valueDouble <= 0) {
      System.out.println("\nPlease enter a number GREATER THAN ZERO!\n");
      return false;
    } else {
      return true;
    }
  }

  protected static double inputValidVal12(String valueString) {
    return Double.parseDouble(valueString);
  }

  protected static boolean inputValidBool3(String valueString) {
    int valueInt = 0;

    try {
      valueInt = Integer.parseInt(valueString); 
    } catch (NumberFormatException e) {
      System.out.println("\nPlease enter a NUMBER!\n");
      return false;
    }

    if (valueInt < 2 || valueInt >= 100) {
      System.out.println("\nPlease enter a number BETWEEN 2 and 99!\n");
      return false;
    } else {
      return true;
    }
  }

  protected static int inputValidVal3(String valueString) {
    return Integer.parseInt(valueString);
  }
}