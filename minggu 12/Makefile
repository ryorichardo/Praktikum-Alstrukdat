CC = gcc
CFLAGS = -c -Wall
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit
COV_LIBS = -lgcov -coverage
SRC_DIR= src
TST_DIR= test
SRC_FILES = $(addprefix $(SRC_DIR)/, *.c) 
TST_FILES = $(addprefix $(TST_DIR)/, *.c)
GCOV = gcovr 
GCONV_FLAGS = -s -d


all: coverage

bintree.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/, bintree.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_FILES) 

check_bintree.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS)  $(TST_FILES) 

check_bintree_test: bintree.o check_bintree.o
	$(CC) bintree.o check_bintree.o $(TST_LIBS) $(COV_LIBS) -o check_bintree_test

test: check_bintree_test
	./check_bintree_test

coverage: test
	$(GCOV) $(GCONV_FLAGS)

coverage_report.html: test
	$(GCOV) $(GCONV_FLAGS) -o coverage_report.html

.PHONY: clean all

clean:
	-rm *.o *.html *.gcda *.gcno check_bintree_test