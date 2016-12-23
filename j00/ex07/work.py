from sys import argv
import string

def workError(bonjour):
	i = 1
	max = len(bonjour)
	if bonjour[0] == "+" or bonjour[0] == "->" or bonjour[max - 1] == "+" or bonjour[max - 1] == "->":
		print ("Error !")
		exit ()
	fleche = 0
	while i < max:
		if not fleche and bonjour[i] == "->":
			fleche = 1
		elif fleche and bonjour[i] == "->":
			print ("Error !")
			exit ()
		if bonjour[i] != "+" and bonjour[i] != "->":
			print ("Error !")
			exit ()
		i += 2
	i = 0
	while i < max:
		if not bonjour[i].isalnum():
			print ("Error !")
			exit ()
		i += 2


def main(av):
	if len(av) != 2:
		print ("Error !")
		exit ()
	bonjour = av[1].split()
	workError(bonjour)
	
	tmp = ""
	tmp2 = ""
	flag = 0
	for line in bonjour:
		if not flag and line != "+" and line != "->":
			tmp = tmp + " " + line
		elif flag and line != "+":
			tmp2 = tmp2 + " " + line
		elif line == "->":
			flag = 1

	print (tmp)
	print (tmp2)

	# UNDERSPLIT LES NOMBRES

	max = len(tmp)
	max2 = len(tmp2)
	i = 0
	while i < max:
		a = 0
		while a < max2:
			if tmp2[a] == tmp[i]:
				break
			elif a + 1 == max2:
				print ("Error !")
				exit ()
			a += 1
		i += 1
	a = 0
	while a < max2:
		i = 0
		while i < max:
			if tmp[i] == tmp2[a]:
				break
			elif i + 1 == max:
				print ("Error !")
				exit ()
			i += 1
		a += 1

	print ("Done.")

main(argv)
