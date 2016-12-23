def revsplit(av="Il y a une erreur !"):
	if not av:
		print ("")
	else:
		bonjour = av.split()
		print(" ".join(bonjour[::-1]))

revsplit("1 2 3")
revsplit()
