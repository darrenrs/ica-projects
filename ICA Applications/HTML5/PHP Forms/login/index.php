<?php
date_default_timezone_set("America/Denver");

if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
  http_response_code(405);
  die("<!DOCTYPE html>
<html>
  <head>
    <title>International Human Registry</title>
    <link rel=\"stylesheet\" href=\"style.css\">
  </head>
  <body>
    <header>
      <h1>International Human Registry</h1>
    </header>
    <blockquote>
      <h2>405 Method Not Allowed</h2>
      <p>Please make sure you're submitting the form through the main page.</p>
    </blockquote>
    <footer>
      <a href=\"/\">&lt;&mdash; previous</a>
      <span>Page generated ".date('Y-m-d H:i:s')."</span>
      <a class=\"link-hidden\" href=\"\">next &mdash;&gt;</a>
    </footer>
  </body>
</html>
");
}
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
    <div class="form">
      <h2>Welcome!</h2>
      <p>Thanks for registering with the International Human Registry, <em><?php echo $_POST["nameLegalFirst"]." ".$_POST["nameLegalLast"] ?></em>. Your account username is <em><?php echo $_POST["username"] ?></em>.</p>
    </div>
    <footer>
      <a href="/">&lt;&mdash; previous</a>
      <span>Page generated <?php echo date("Y-m-d H:i:s") ?></span>
      <a class="link-hidden" href="">next &mdash;&gt;</a>
    </footer>
    <script src="form/form.js"></script>
  </body>
</html>