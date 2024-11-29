# Set GCOV_PREFIX to the current directory for dynamic coverage paths
GCOV_PREFIX=$(CURDIR)
GCOV_PREFIX_STRIP=$(shell echo $(CURDIR) | tr -cd '/' | wc -c)

# Compiler flags
CFLAGS = --coverage
LDFLAGS = --coverage

# Default target
all: budget_system budget_test

# Build the budget system executable
budget_system: main.c credit.c debit.c help.c login.c new_account.c file_management.c \
                credit.h debit.h help.h login.h new_account.h file_management.h 
	gcc -o budget_system main.c credit.c debit.c help.c login.c new_account.c user_account.c

# Build the budget test executable with coverage enabled
budget_test: main.c credit.c debit.c help.c login.c new_account.c file_management.c \
             credit.h debit.h help.h login.h new_account.h file_management.h 
	gcc -o budget_test $(CFLAGS) main.c credit.c debit.c help.c login.c new_account.c user_account.c $(LDFLAGS)

# Clean build artifacts and coverage files
clean:
	rm -f budget_system budget_test *.gcda *.gcno *.gcov
