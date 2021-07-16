data  = None
wait  = 0.80
var   = {
  "mode": "prod"
}
regex = [
  "^\*.*",
  "\${(.*?)}"
]

def path(id="intro"):
  time.sleep(wait)
  try:
    # Make sure that the requested node exists
    idp = data[id]
  except KeyError:
    # If not, exit
    stdout("You have reached an incomplete node. Sorry!")
  else:
    # Exit game automatically after victory
    if id == 'victory':
      time.sleep(wait*5)
    else:
      # Print dialogue message from JSON
      for i in idp["text"]:
        rv = re.compile(regex[1])
        # Scan for variables call in text
        # Regex is given at regex[1]
        # Syntax: ${var} where var is the variable that you want to set
        if re.search(rv, i):
          # If there is a match, replace with variable value
          rt = var[re.search(rv, i).group(1)]
          stdout(re.sub(rv, rt, i))
        else:
          # If no match, print normally
          stdout(i)
        time.sleep(wait/2)
      time.sleep(wait)
      
      if "response" in idp:
        idpk = idp["response"].keys()
        ci = False

        # Scan for input with asterik
        # Asterik inputs will set text after the asterik as a variable key
        svr = re.compile(regex[0])
        svl = list(filter(svr.search, idpk))

        if len(svl) > 0:
          ci = True
        
        if "lastwords" in var:
          # No action to path() will end the game
          pass
        else:
          loop = True

          newline()
          stdout(idp["input"])
          swline('-')
          time.sleep(wait)

          # No variable input, print normal actions    
          if not ci:
            for n, k in enumerate(idpk):
              stdout('({}) {}'.format(n, idp["response"][k]["text"]))
              time.sleep(wait/2)

          time.sleep(wait)

          # Loop until input correct input
          while loop:

            res = input("> ")

            if res.strip() not in idpk:
              # Variable input, set the input to the variable
              if ci:
                loop = False

                vn = svl[0][1:]
                var[vn] = res

                # Proceed to next path
                swline('=')
                path(idp["response"][svl[0]]["next"])
              else:
              # Invalid input, try again
                loop = True
            else:
              # Valid input, proceed to next path
              loop = False

              swline('=')
              path(idp["response"][res]["next"])
      else:
        # No input, passthrough only
        swline('=')
        path(idp["next"])

# StdOut
def stdout(t):
  for i, l in enumerate(t):
    sys.stdout.write(t[i])
    sys.stdout.flush()
    time.sleep(stdout_wd(t))
  newline()

def stdout_wd(t):
  return wait / len(t)

# Prints a new line
def newline():
  print("\u0000")
  return "\u0000"

# Prints a Screen Width Line
def swline(c):
  newline()
  print( c * os.get_terminal_size()[0] )
  newline()
  return c * os.get_terminal_size()[0]

# Execute if not imported as a module
if __name__ == "__main__":
  # Import modules
  import json
  import re
  import time
  import sys
  import os

  try:
    # Attempt to load the story data
    f = open("data.json", "r")
    data = json.load(f)
  except Exception as e:
    # Can't play no more
    print("Error!\n{}\nCan't play no more.".format(e))
  else:
    # Testing, set my name without prompt
    if var["mode"] == "dev":
      var["name"] = "Darren"
      var["hand"] = "middle"
      wait = 0.0
      path("start_entry")
    else:
      path()