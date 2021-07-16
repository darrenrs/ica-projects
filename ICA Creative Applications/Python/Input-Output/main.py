FILE_OPT = "opt.cfg"
FILE_INF = "manifest.cfg"

if __name__ == "__main__":
  ## Import Modules
  import sys
  import time
  import datetime
  import os
  import math
  import configparser

  ## Config
  INF = configparser.ConfigParser()
  INF.read(FILE_INF)
  INF_INFO = INF["Info"]

  OPT = configparser.ConfigParser()
  OPT.read(FILE_OPT)

  OPT_INTRO = OPT["Intro"]

  # Gets the width and height of the console in characters
  CONSOLE_WIDTH  = os.get_terminal_size()[0]
  CONSOLE_HEIGHT = os.get_terminal_size()[1]

  ## Intro
  # Only perform the intro if True
  if OPT_INTRO.getboolean("INTRO_IS_ACTIVE"):
    INTRO_JL_TIME_MSEC = OPT_INTRO.getint("INTRO_JL_TIME_MSEC")
    INTRO_LN_TIME_MSEC = OPT_INTRO.getint("INTRO_LN_TIME_MSEC")

    with open(OPT_INTRO.get("INTRO_FILENAME"), "r") as f:
      # Iterate thru lines
      for i in f.readlines():
        # String "JUMP_LTR" signifies the end of a letter; wait longer
        INTRO_JL_STRING = OPT_INTRO.get("INTRO_JL_STRING")
        if i == "{}\n".format(INTRO_JL_STRING) or i == INTRO_JL_STRING:
          time.sleep(INTRO_JL_TIME_MSEC / 1000)
          sys.stdout.write('\n')
          continue
        # Regular line as normal
        else:
          time.sleep(INTRO_LN_TIME_MSEC / 1000)
          
          # Padding is defined as the midpoint in the screen
          sppadding = math.floor((CONSOLE_WIDTH-len(i))/2)

          sys.stdout.write('{}{}'.format(' '*sppadding,i))
          sys.stdout.flush()
      print('\n')

    print('-'*CONSOLE_WIDTH+'\n')
  
  ## Information
  INF_TITLE = INF_INFO.get("INF_TITLE")
  INF_CREATOR_NAME = INF_INFO.get("INF_CREATOR_NAME")
  INF_REVISION_NUM = INF_INFO.get("INF_REVISION_NUM")
  INF_DATE_CREATED = datetime.datetime.strptime(INF_INFO.get("INF_DATE_CREATED"),"%Y-%m-%dT%H:%M:%S%z").isoformat()
  INF_DATE_MODIFIED = datetime.datetime.strptime(INF_INFO.get("INF_DATE_MODIFIED"),"%Y-%m-%dT%H:%M:%S%z").isoformat()
  #INF_INFO.get("INF_DATE_CREATED")

  print('Welcome to {} by {}! (rev. {})'.format(INF_TITLE, INF_CREATOR_NAME, INF_REVISION_NUM))
  print('Date Created: {}'.format(INF_DATE_CREATED))
  print('Last Updated: {}'.format(INF_DATE_MODIFIED))

else:
  raise ImportError('Not available for import')