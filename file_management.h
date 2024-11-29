
void create_user_history_file(const char *username); 
int find_user_file(const char *username, const char *folder_name); 
void get_user_password(const char *username, char *password_buffer, size_t buffer_size);
void add_user_info_to_history_log(const char *folder_name, const char *username, const char *name, const char *password, const char *birthday, const char *email, const char *phone_number, double budget); 
void add_transaction_to_user_file(const char *folder_name, const char *username, const char *type, double amount, double *remaining_budget, const char *date, double balance, const char *description);
void get_recent_credit_balance(const char *folder_name, const char *username, double *credit_balance);
void get_recent_debit_balance(const char *folder_name, const char *username, double *debit_balance);
double get_budget_from_user_file(const char *username); 
void update_budget(const char *username, double new_budget);