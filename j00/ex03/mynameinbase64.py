from sys import argv
import base64

def main(av):
	if len(av) != 2:
		print ("RVJST1IgIQ==")
	else:
		bonjour = av[1].lower()
		coucou = base64.b64encode(bonjour)
		print (coucou)

main(argv)
