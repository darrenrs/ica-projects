<?php
date_default_timezone_set("America/Denver");
?>
<!DOCTYPE html>
<html>
  <head>
    <title>International Human Registry</title>
    <link rel="stylesheet" href="style.css">
  </head>
  <body>
    <header>
      <h1>International Human Registry</h1>
    </header>
    <form id="form" action="/login" method="POST">
      <div class="form">
        <h2>Demographics</h2>
        <fieldset>
          <legend>Name</legend>
          <div>
            <label for="name-legal-last">Legal Name</label>
            <input type="text" id="name-legal-last" name="nameLegalLast" placeholder="Surname" required>
            <span class="required">*</span>,
            <input type="text" id="name-legal-first" name="nameLegalFirst" placeholder="First name" required>
            <span class="required">*</span>
            <input type="text" id="name-legal-middle" name="nameLegalMiddle" placeholder="Middle name">
          </div>
          <div>
            <label for="name-pref-last">Preferred Name</label>
            <input type="text" id="name-pref-last" name="namePrefLast" placeholder="Preferred surname">,
            <input type="text" id="name-pref-first" name="namePrefFirst" placeholder="Preferred first name">
          </div>
        </fieldset>
        <fieldset>
          <legend>Dates</legend>
          <div>
            <label for="birthday-date">Date of Birth</label>
            <input type="date" id="birthday-date" name="birthdayDate" required>
            <span class="required">*</span> at
            <input type="time" id="birthday-time" name="birthdayTime">
          </div>
        </fieldset>
        <fieldset>
          <legend>Sex/Gender</legend>
          <div>
            <span>Biological Sex</span>
            <span class="required">*</span><br>
            <input type="radio" id="sex-male" name="sex" value="M" required>
            <label for="sex-male">Male</label><br>
            <input type="radio" id="sex-female" name="sex" value="F" required>
            <label for="sex-female">Female</label>
          </div>
          <div>
            <span>Preferred Gender</span>
            <span class="required">*</span><br>
            <input type="radio" id="gender-male" name="gender" value="M" required>
            <label for="gender-male">Male</label><br>
            <input type="radio" id="gender-female" name="gender" value="F" required>
            <label for="gender-female">Female</label><br>
            <input type="radio" id="gender-other" name="gender" value="O" required>
            <label for="gender-other">Other</label>
          </div>
        </fieldset>
        <fieldset>
          <legend>Race/Ethnicity</legend>
          <div>
            <span>Race</span><br>
            <input type="checkbox" id="white" name="race" value="C">
            <label for="white">White</label><br>
            <input type="checkbox" id="black" name="race" value="B">
            <label for="black">Black or African American</label><br>
            <input type="checkbox" id="native" name="race" value="I">
            <label for="native">American Indian or Native American</label><br>
            <input type="checkbox" id="asian" name="race" value="A">
            <label for="asian">Asian</label><br>
            <input type="checkbox" id="aiap" name="race" value="P">
            <label for="aiap">Native Hawaiian or Pacific Islander</label><br>
            <input type="checkbox" id="nos" name="race" value="O">
            <label for="nos">Other, not specified</label>
          </div>
          <div>
            <span>Ethnicity</span>
            <span class="required">*</span><br>
            <input type="radio" id="hispanic" name="hispanic" value="true" required>
            <label for="hispanic">Hispanic or Latino/Latina</label><br>
            <input type="radio" id="not-hispanic" name="hispanic" value="false" required>
            <label for="not-hispanic">Not Hispanic or Latino/Latina</label>
          </div>
        </fieldset>
        <fieldset>
          <legend>Address</legend>
          <div>
            <span>Living status</span>
            <span class="required">*</span><br>
            <input type="radio" id="home-owner" name="homeStatus" value="O" required>
            <label for="home-owner">I own a home or live with a homeowner</label><br>
            <input type="radio" id="home-renter" name="homeStatus" value="R" required>
            <label for="home-renter">I rent a home or live with a home renter</label><br>
            <input type="radio" id="home-unstable" name="homeStatus" value="U" required>
            <label for="home-unstable">I do not have a permanent home</label><br>
            <input type="radio" id="home-none" name="homeStatus" value="N" required>
            <label for="home-none">I am homeless</label>
          </div>
          <div id="address-master">
            <span>Address</span><br>
            <label for="house-number">House Number (with direction): </label>
            <input type="text" id="house-number" name="houseNumber"><br>
            <label for="house-street">Street Name (with suffix): </label>
            <input type="text" id="house-street" name="houseStreet"><br>
            <label for="house-city">City: </label>
            <input type="text" id="house-city" name="houseCity">,
            <select id="cars" name="cars">
              <option value="UT">Utah</option>
              <option value="CA">California</option>
              <option value="NY">New York</option>
              <option value="Other">Other (too lazy to code in other states)</option>
            </select>
            <label for="house-zip">ZIP Code: </label>
            <input type="number" id="house-zip" name="houseZip" min="10000" max="99999">
          </div>
        </fieldset>
      </div>
      <div class="form">
        <h2>Family</h2>
        <fieldset>
          <legend>Living Status</legend>
          <div>
            <span>With whom are you living with?</span><br>
            <input type="checkbox" id="mother" name="family" value="M">
            <label for="mother">Mother or Step-mother</label><br>
            <input type="checkbox" id="father" name="family" value="F">
            <label for="father">Father or Step-father</label><br>
            <input type="checkbox" id="brother" name="family" value="B">
            <label for="brother">Any number of brothers or step-brothers</label><br>
            <input type="checkbox" id="sister" name="family" value="S">
            <label for="sister">Any number of sisters or step-sisters</label><br>
            <input type="checkbox" id="children" name="family" value="C">
            <label for="children">Any number of children or step-children</label><br>
            <input type="checkbox" id="uncle" name="family" value="U">
            <label for="uncle">Uncle</label><br>
            <input type="checkbox" id="aunt" name="family" value="A">
            <label for="aunt">Aunt</label><br>
            <input type="checkbox" id="grandparents" name="family" value="G">
            <label for="grandparents">Grandparents</label><br>
            <input type="checkbox" id="friends" name="family" value="R">
            <label for="friends">Friends</label><br>
            <input type="checkbox" id="other" name="family" value="O">
            <label for="other">Other, not otherwise specified</label>
          </div>
          <div>
            <span>How many brothers/sisters/children?</span><br>
            <label for="brother-count">Brothers:</label>
            <input type="number" id="brother-count" name="brotherCount" min="0" max="9"><br>
            <label for="sister-count">Sisters:</label>
            <input type="number" id="sister-count" name="sisterCount" min="0" max="9"><br>
            <label for="dependent-count">Children:</label>
            <input type="number" id="dependent-count" name="dependentCount" min="0" max="9">
          </div>
        </fieldset>
      </div>
      <div class="form">
        <h2>Financial</h2>
        <fieldset>
          <legend>Employment</legend>
          <div>
            <span>Are you employed?</span>
            <span class="required">*</span><br>
            <input type="radio" id="employed" name="employed" value="true" required>
            <label for="employed">Yes</label><br>
            <input type="radio" id="not-employed" name="employed" value="false" required>
            <label for="not-employed">No</label>
          </div>
          <div id="job-master">
            <label for="job-title">Job Title: </label>
            <input type="text" id="job-title" name="jobTitle"><br>
            <label for="job-title">Job Description: </label>
            <input type="text" id="job-description" name="jobDescription"><br>
            <label for="job-rating">Job Rating (between 0 and 10): </label>
            <input type="range" id="job-rating" name="jobRating" min="0" max="10">
          </div>
        </fieldset>
        <fieldset>
          <legend>Income</legend>
          <div>
            <label for="income-gross">Gross Income: </label>
            <input type="number" id="income-gross" name="incomeGross" min="0" max="1000000000"><br>
            <label for="income-net">Net Income: </label>
            <input type="number" id="income-net" name="incomeNet" min="0" max="1000000000"><br>
          </div>
        </fieldset>
      </div>
      <div class="form">
        <h2>Personal</h2>
          <label for="email-address">Email: </label>
          <input type="email" id="email-address" name="emailAddress"><br>
          <label for="color">Favorite Color: </label>
          <input type="color" id="color" name="color">
        </fieldset>
      </div>
      <div class="form">
        <h2>Form Management</h2>
        <p>Note: Fields marked with a <span class="required">*</span> are required.</p>
        <fieldset>
          <legend>Account Creation</legend>
          <label for="username">Username: </label>
          <span class="required">*</span>
          <input type="text" id="username" name="username" readonly  placeholder="Automatically generated"><br>
          <label for="password">Password: </label>
          <span class="required">*</span>
          <input type="password" id="password" name="password">
        </fieldset>
        <br>
        <input type="submit" value="Submit Data">
        <input type="reset" value="Reset Data">
      </div>
      <br>
      <br>
    </form>
    <footer>
      <a href="/">&lt;&mdash; previous</a>
      <span>Page generated <?php echo date("Y-m-d H:i:s") ?></span>
      <a class="link-hidden" href="">next &mdash;&gt;</a>
    </footer>
    <script src="form/form.js"></script>
  </body>
</html>