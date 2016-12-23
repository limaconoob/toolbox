NAME = start.a
OBJ = ./test.o

all: $(NAME)

$(NAME):
	/tmp/coucou/stack/stack-1.3.0-osx-x86_64/stack ghc test.hs
	ar rc $(NAME) $(OBJ)

clean:
	@rm test.hi test.o 
	@rm a.out
	@rm test
	@rm start.a
