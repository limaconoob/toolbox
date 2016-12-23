from sys import argv
from os.path import exists

def main(av):
	if len(av) != 2 or not exists(av[1]):
		print ("Error !")
	else:
		with open(av[1]) as f:
			bonjour = f.read()
		bonjour = bonjour.split()
		x_max = len(bonjour[0])
		for line in bonjour:
			if len(line) != x_max:
				print ("Error !")
				exit ()
			x = 0
			while x < x_max:
				if line[x] != '.' and line[x] != 'X':
					print ("Error !")
					exit ()
				x += 1
		y = 0
		y_max = len(bonjour)
		while y < y_max:
			mines = 0
			x = 0
			while x < x_max:
			#	print (x, bonjour[y][x])
				if bonjour[y][x] == '.':
					if x and bonjour[y][x - 1] == 'X':
						mines += 1
					if x + 1 < x_max and bonjour[y][x + 1] == 'X':
						mines += 1
					if y and bonjour[y - 1][x] == 'X':
						mines += 1
					if y + 1 < y_max and bonjour[y + 1][x] == 'X':
						mines += 1
					if x and y and bonjour[y - 1][x - 1] == 'X':
						mines += 1
					if x + 1 < x_max and y + 1 < y_max and bonjour[y + 1][x + 1] == 'X':
						mines += 1
					if x + 1 < x_max and y and bonjour[y - 1][x + 1] == 'X':
						mines += 1
					if y + 1 < y_max and x and bonjour[y + 1][x - 1] == 'X':
						mines += 1
					print (mines),
					mines = 0
				else:
					print ("X"),
				x += 1
			y += 1
			print ("")

main(argv)
