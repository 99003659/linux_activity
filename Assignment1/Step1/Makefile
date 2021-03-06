PROJECT_NAME = ASSIGNMENT1

SRC = src/mystring.c\
src/myutils.c\
src/bit_set_reset.c\
test.c

INC = -Iinc

$(PROJECT_NAME).out : $(SRC)
	gcc $^ -o $@ $(INC)

run : $(PROJECT_NAME).out
	./$^

clean:
	rm -rf *.o *.out