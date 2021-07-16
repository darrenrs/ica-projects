def _():
  for i in range(8):
    print('{:02d} {}'.format(i, i**2))

def _args(**kwargs):
  for i, x in kwargs.items():
    print('{}: {}'.format(i, x))

if __name__ == '__main__':
  _args(name="Darren", iq=136, age=15)
  _()