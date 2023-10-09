# -*- MakeFile -*-
# Make file for the memo program.
# target: dependencies
#	action


memo: memo.o libmemo.o
	gcc memo.o libmemo.o -o memo -I.

memo.o: memo.c
	gcc -c memo.c -I.

libmemo.o:libmemo.c
	gcc -c libmemo.c -I.
clean:
	rm -r *.o memo 