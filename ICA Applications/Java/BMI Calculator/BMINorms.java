class BMINorms {
  double[] childNormsMaleMean = {16.57502768,
16.01938111,
15.64047335,
15.42443435,
15.38157537,
15.50449934,
15.76862107,
16.14907171,
16.62454647,
17.17648317,
17.78808887,
18.44374288,
19.12862799,
19.82839223,
20.52867566,
21.21445576,
21.86949503,
22.47670112,
23.02029424
  };
  double[] childNormsMaleSD   = {1.431240258,
1.206499748,
1.170618388,
1.279812900,
1.498828510,
1.786101778,
2.102231148,
2.415747425,
2.703269240,
2.948671783,
3.142480898,
3.281557300,
3.368946015,
3.413773670,
3.431091993,
3.441610945,
3.471389188,
3.551772955,
3.720008648
  };

  double[] childNormsFemaleMean = {16.42339664,
15.72199750,
15.30989264,
15.15347266,
15.21050813,
15.44074737,
15.80912032,
16.28440007,
16.83795071,
17.44310531,
18.07493225,
18.71021144,
19.32753430,
19.90747605,
20.43278335,
20.88847810,
21.26172855,
21.54135608,
21.71699934
  };
  double[] childNormsFemaleSD   = {1.444949608,
1.324590585,
1.368174743,
1.532939438,
1.777775533,
2.068750250,
2.379276733,
2.688813220,
2.981980785,
3.248175170,
3.481446925,
3.680503125,
3.848758533,
3.994392360,
4.130366975,
4.274353403,
4.448509518,
4.679101378,
4.996054368
  };

  protected double childNormsMaleZScore(double bmi, int age) {
    int index = age - 2;

    return (bmi - childNormsMaleMean[index]) / childNormsMaleSD[index];
  }

  protected double childNormsFemaleZScore(double bmi, int age) {
    int index = age - 2;

    return (bmi - childNormsFemaleMean[index]) / childNormsFemaleSD[index];
  }

  protected String zScoreQualitative(double zscore) {
    if (zscore <= -4) {
      return "flat Stanley";
    } else if (zscore <= -3) {
      return "severely underweight";
    } else if (zscore <= -2) {
      return "underweight";
    } else if (zscore <= -1) {
      return "below average";
    } else if (zscore < 1) {
      return "average";
    } else if (zscore < 2) {
      return "overweight";
    } else if (zscore < 3) {
      return "obese";
    } else if (zscore < 4) {
      return "morbidly obese";
    } else {
      return "elephant";
    }
  }

  protected String bmiAdultQualitative(double bmi) {
    if (bmi < 13) {
      return "flat Stanley";
    } else if (bmi < 15) {
      return "anorexic";
    } else if (bmi < 18.5) {
      return "underweight";
    } else if (bmi < 25) {
      return "healthy";
    } else if (bmi < 30) {
      return "overweight";
    } else if (bmi < 35) {
      return "mildly obese";
    } else if (bmi < 40) {
      return "moderately obsese";
    } else if (bmi < 60) {
      return "morbidly obese";
    } else {
      return "elephant";
    }
  }
}