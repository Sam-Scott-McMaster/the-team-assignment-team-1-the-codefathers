
void create_user_history_file(const char *username); 
int find_user_file(const char *username, const char *folder_name); 
void add_info_to_user_file(const char *folder_name, const char *username, const char *info);
void add_transaction_to_user_file(const char *folder_name, const char *username, const char *type, float amount, const char *date, float balance, const char *description);
void get_recent_credit_balance(const char *folder_name, const char *username, float *credit_balance);
void get_recent_debit_balance(const char *folder_name, const char *username, float *debit_balance);
void set_budget_to_user_file(const char *username, double budget);
double get_budget_from_user_file(const char *username);
void update_budget(const char *username, double new_budget);