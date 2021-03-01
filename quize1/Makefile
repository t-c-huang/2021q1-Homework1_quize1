CC = gcc
CFLAGS = -O1 -g -Wall -Werror -Idudect -I.

#qsort_non_recursive.o qsort_linux.o
linked_list: linked_list.o qsort_quize1.o random.o 
	gcc linked_list.c qsort_quize1.c random.c -o linked_list  #qsort_non_recursive.c  qsort_linux.c
	./linked_list

linked_list.o: linked_list.c
	gcc linked_list.c -c

qsort_quize1.o: qsort_quize1.c
	gcc qsort_quize1.c -c

random.o: random.c
	gcc random.c -c

# qsort_non_recursive.c: qsort_non_recursive.o
# 	gcc qsort_non_recursive.o -c

# qsort_linux.c: qsort_linux.o
# 	gcc qsort_linux.o -c

test:
	./linked_list

clean:
	rm -rf *.o


# #GIT_HOOKS := .git/hooks/applied
# DUT_DIR := dudect
# #all: $(GIT_HOOKS) qtest

# tid := 0

# # Control test case option of valgrind
# # ifeq ("$(tid)","0")
# #     TCASE :=
# # else
# #     TCASE := -t $(tid)
# # endif

# # Control the build verbosity
# ifeq ("$(VERBOSE)","1")
#     Q :=
#     VECHO = @true
# else
#     Q := @
#     VECHO = @printf
# endif

# # Enable sanitizer(s) or not
# ifeq ("$(SANITIZER)","1")
#     # https://github.com/google/sanitizers/wiki/AddressSanitizerFlags
#     CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-common
#     LDFLAGS += -fsanitize=address
# endif

# # $(GIT_HOOKS):
# # 	@scripts/install-git-hooks
# # 	@echo

# OBJS := linked_list.o qsprt_quize1.o

# deps := $(OBJS:%.o=.%.o.d)


%.o: %.c
	@mkdir -p .$(DUT_DIR)
	$(VECHO) "  CC\t$@\n"
	$(Q)$(CC) -o $@ $(CFLAGS) -c -MMD -MF .$@.d $<


# # valgrind_existence:
# # 	@which valgrind 2>&1 > /dev/null || (echo "FATAL: valgrind not found"; exit 1)

# # valgrind: valgrind_existence
# # 	# Explicitly disable sanitizer(s)
# # 	$(MAKE) clean SANITIZER=0 qtest
# # 	$(eval patched_file := $(shell mktemp /tmp/qtest.XXXXXX))
# # 	cp qtest $(patched_file)
# # 	chmod u+x $(patched_file)
# # 	sed -i "s/alarm/isnan/g" $(patched_file)
# # 	scripts/driver.py -p $(patched_file) --valgrind $(TCASE)
# # 	@echo
# # 	@echo "Test with specific case by running command:" 
# # 	@echo "scripts/driver.py -p $(patched_file) --valgrind -t <tid>"

# clean:
# 	rm -f $(OBJS) $(deps) *~ qtest /tmp/qtest.*
# 	rm -rf .$(DUT_DIR)
# 	rm -rf *.dSYM
# 	(cd traces; rm -f *~)

# -include $(deps)
