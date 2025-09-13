CFLAGS   = -Wall -Wextra -g -rdynamic

all::
	$(CC) $(CFLAGS) anti-ptrace.c -o anti-ptrace
	$(CC) $(CFLAGS) breakpoint_detection.c -o breakpoint_detection
	$(CC) $(CFLAGS) pc_manipulation.c -o pc_manipulation

	cp /lib/x86_64-linux-gnu/libcrypto.so.3 .
	chmod +x libcrypto.so.3
	upx ./libcrypto.so.3

test::
	./test.wsh ./anti-ptrace
	./test.wsh ./breakpoint_detection
	./test.wsh ./pc_manipulation
	./upx-test.wsh

clean::
	rm -f anti-ptrace breakpoint_detection pc_manipulation libcrypto.so

