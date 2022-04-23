aladtest: aladtest.o aladdin_subr.o
	$(F77) -o $@ $^
aladtest.o: ALPCOM.FOR
aladdin_subr.o: aladdin_subr.f
aladdin_subr.f: ALPCOM.FOR ALCOM.FOR