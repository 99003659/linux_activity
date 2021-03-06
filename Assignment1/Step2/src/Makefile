CFLAGS = -I../inc

libstr: mystring.o
	ar rc libmystring.a $^

libutil: myutils.o
	ar rc libmyutils.a $^

libbitop: bit_set_reset.o
	ar rc libbitop.a $^

clean:
	rm -rf *.o *.a