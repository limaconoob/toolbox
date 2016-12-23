import hashlib
from sys import argv

def main(av):
	if len(av) == 1:
		print ("0")
	elif len(av) == 2:
		m = hashlib.md5(av[1])
		k = m.hexdigest()
		i = 0
		while not k.startswith("00000"):
			coucou = av[1] + str(i)
			coucou = hashlib.md5(coucou)
			k = coucou.hexdigest()
			i += 1
		i -= 1
		print (i)

main(argv)
