import hashlib
from sys import argv

def main(av):
	if len(av) < 3:
		print ("Error !")
	else:
		bonjour = open(av[1])
		bonjour = bonjour.read()
		bonjour = bonjour.split()
		while i in av[2:]:
			m = hashlib.md5(av[i])
			k = m.hexdigest()
			for line in bonjour:
				if line == k:
					break
			print (av[i]),
			if line == k:
				print ("is valid")
			else:
				print ("is invalid")
			i = i + 1

main(argv)
