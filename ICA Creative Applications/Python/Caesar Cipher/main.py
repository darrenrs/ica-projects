alpha = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')

def cipher(t, o):
  return ''.join([getIdx(i, o) for i in t])

def getIdx(n, o):
  if n in alpha:
    return alpha[(alpha.index(n) + o) % 25]
  elif n.upper() in alpha:
    return alpha[(alpha.index(n.upper()) + o) % 25].lower()
  else:
    return n

if __name__ == '__main__':
  valid = False

  while True:
    valid = False
    t = input("Please enter your text\n> ")
    print('\u0000')
    while not valid:
      o = input("Please enter the offset\n> ")
      try:
        int(o)
      except:
        print("Invalid offset")
      else:
        valid = True
  
    print( cipher(t, int(o)) )
    print('\u0000')