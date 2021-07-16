import random, math

nRange  = None
toGuess = None
gnLabel = ['min', 'max']
rlLtr   = list('YOTS')

def getRange():
  rng = [0, 0]

  def getNumbers(i):
    isset = False
    while not(isset):
      inp = input('Please enter the {}: '.format(gnLabel[i]))
      try:
        int(inp)
      except:
        print('Integer is required.')
      else:
        isset = True
        rng[i] = int(inp)

  for i in range(2):
    getNumbers(i)

  return rng

if __name__ == '__main__':
  print('Welcome!\n')

  while True:
    nRange = getRange()
    toGuess = random.randint(nRange[0], nRange[1])
    nFound = False
    guessCount = 0

    while not(nFound):
      inp = input('\nMake a guess> ')

      try:
        int(inp)
      except:
        print('Your guess must be an integer.')
      else:
        inp = int(inp)
        guessCount += 1
        if inp == toGuess:
          nFound = True
          par = math.ceil(math.log2(nRange[1]-nRange[0]))+1
          parString = None

          print('You won after {} guesses!'.format(guessCount))
          print('The par for your range is {}.'.format(par))

          if guessCount > par:
            parString = 'terrible'
          elif guessCount < par:
            parString = 'great'
          else:
            parString = 'OK'

          print('That means that you did {}.'.format(parString))

        elif inp < toGuess:
          print('You guessed too low.')
        else:
          print('You guessed too high.')
    
    restart = input('\nWould you like to play again?\n>').strip().upper()[:1]

    if restart in rlLtr:
      print('We meet again ... \n')
    else:
      print('Goodbye, then!')
      break