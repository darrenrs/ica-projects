opLabel = ['N1', 'N2', 'Op']
opChar  = list('+-*/^%')
status  = True
exitStr = "exit"
n       = 0

histre  = '^h\((\d+)\)'
history = []

def getEq():
  eqs = []

  def getInputs(n,i):
    global status

    isset = False
    while not(isset):
      inp = input('In[{},{}]: '.format(n,opLabel[i]))
      if i <= 1:
        if re.match(histre, inp):
          id = int( re.match(histre, inp).group(1) )

          try:
            history[ id ]
          except:
            print('Invalid history key (range between 0, {} allowed)'.format(len(history)-1))
          else:
            isset = True
            eqs.append( history[ id ] )
        elif inp.strip().lower() == exitStr:
          isset = True
          status = False
          eqs.append( exitStr )
        else:
          try:
            int(inp)
          except:
            print('Integer is required.')
          else:
            isset = True
            eqs.append( int(inp) )
      else:
        if inp.strip().lower() == 'exit':
          isset = True
          status = False
          eqs.append( exitStr )
        elif inp in opChar:
          isset = True
          eqs.append( inp )
        else:
          print('Not a valid operator (must be {})'.format(','.join(opChar)))

  for i in range(3):
    if exitStr in eqs:
      return exitStr
    else:
      getInputs(n,i)

  return eqs

def calc(eq):
  if exitStr in eq:
    return 'Goodbye!'

  if eq[2] == '^':
    eq[2] = '**'

  try:
    co = eval('{}{}{}'.format(eq[0], eq[2], eq[1]))
  except ZeroDivisionError as zde:
    return "Error: {}".format(zde)
  else:
    history.append(co)
    return co

if __name__ == '__main__':
  import re

  print('Welcome!\n')
  print('You must enter two operands, followed by an operator.')
  print('The operator may be:\n\taddition (+)\n\tsubtraction (-)\n\tmultiplication (*)\n\tdivision (/)\n\texponential (^)\n\tmodulus (%)')
  print('Enter h(idx) where idx is the output index to access history.')
  print('Enter <EXIT> at any time to leave.')

  while status:
    print('\n')
    print('Out[{}]: {}'.format(n, calc(getEq())))
    n += 1