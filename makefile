budget_system: main.c credit.c debit.c help.c login.c new_account.c user_account.c credit.h debit.h help.h login.h new_account.h user_account.h 
	gcc -o budget_system main.c credit.c debit.c help.c login.c new_account.c user_account.c 

test: main.c credit.c debit.c help.c login.c new_account.c user_account.c credit.h debit.h help.h login.h new_account.h user_account.h 
	gcc -o test --coverage main.c credit.c debit.c help.c login.c new_account.c user_account.c 

clean:
	rm -f budget_system *.gcda *.gcno *.gcov