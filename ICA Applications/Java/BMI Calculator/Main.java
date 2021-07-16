import java.util.Scanner;

class Main {
  public static double calculate(double weight, double height, boolean isMetric) {
    double weightConstant = 0.45359237;
    double heightConstant = 2.54;

    if (!isMetric) {
      weight *= weightConstant;
      height *= heightConstant;
    }

    double bmi = 10000*(weight / Math.pow(height, 2));

    return bmi;
  }

  public static void main(String[] args) {
    System.out.print("Welcome to the BMI Calculator!\nCopyright (C) 2020 Darren R. Skidmore\n\n");

    Scanner input = new Scanner(System.in);
    InputVerification inputVer = new InputVerification();
    BMINorms norms = new BMINorms();

    boolean isMetric= false;
    boolean isMale  = false;
    
    String heightUnit = "";
    double height   = 0.00;

    String weightUnit = "";
    double weight   = 0.00;
    
    int age         = 0;
    int[] valid     = {0, 0, 0, 0, 0};

    while (valid[0] <= 0) {
      System.out.printf("Would you like to use metric rather than imperial units? > ");

      String provisionalInput = input.nextLine();

      if (inputVer.inputValidBool0(provisionalInput)) {
        valid[0] = 1;

        isMetric = inputVer.inputValidVal0(provisionalInput);

        if (isMetric) {
          heightUnit = "cm";
          weightUnit = "kg";
        } else {
          heightUnit = "in";
          weightUnit = "lbs";
        }
      }
    }

    while (valid[4] <= 0) {
      System.out.printf("What sex is this person? > ");

      String provisionalInput = input.nextLine();

      if (inputVer.inputValidBool4(provisionalInput)) {
        valid[4] = 1;

        isMale = inputVer.inputValidVal4(provisionalInput);
      }
    }

    while (valid[1] <= 0) {
      System.out.printf("What is the height (in %s)? > ", heightUnit);

      String provisionalInput = input.nextLine();

      if (inputVer.inputValidBool12(provisionalInput)) {
        valid[1] = 1;

        height = inputVer.inputValidVal12(provisionalInput);
      }
    }

    while (valid[2] <= 0) {
      System.out.printf("What is the weight (in %s)? > ", weightUnit);

      String provisionalInput = input.nextLine();

      if (inputVer.inputValidBool12(provisionalInput)) {
        valid[2] = 1;

        weight = inputVer.inputValidVal12(provisionalInput);
      }
    }

    while (valid[3] <= 0) {
      System.out.printf("How many years old are they? > ");

      String provisionalInput = input.nextLine();

      if (inputVer.inputValidBool3(provisionalInput)) {
        valid[3] = 1;

        age = inputVer.inputValidVal3(provisionalInput);
      }
    }

    double bmi = calculate(weight, height, isMetric);

    System.out.printf("\nYour BMI is %f.", bmi);

    if (age <= 20) { //child-based norms
      double bmiZScore = 0.00;

      if (isMale) {
        bmiZScore = norms.childNormsMaleZScore(bmi, age);
      } else {
        bmiZScore = norms.childNormsFemaleZScore(bmi, age);
      }

      System.out.printf("\nBased on your age, your BMI Z-Score is %f (standard score %f).", bmiZScore, (bmiZScore*15)+100);
      System.out.printf("\nThis is a(n) %s BMI.\n", norms.zScoreQualitative(bmiZScore));

    } else {
      System.out.printf("\nThis is a(n) %s BMI.\n", norms.bmiAdultQualitative(bmi));
    }
  }
}