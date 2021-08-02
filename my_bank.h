#ifndef _MY_BANK_GP
#define _MY_BANK_GP

typedef struct _mb_thread_st{
	pthread_t tid;
}mb_thread_st;


class mb_address {
	public:
		char mb_name[64];
		char mb_gender[6];
		char mb_address_1[100];
		char mb_address_2[100];
	private:
		long mb_pin;
		
		void read_user_data();
};

class mb_bank_data{
	public:
		long mb_slno;
		void set_data();
		void display_data();
	protected:
		long mb_customer_id;
	private:
		long mb_balance;
		char join_data[12];
};

class mb_savings_account : public mb_bank_data, public mb_address {
	public:
		long acc_num;
	public:
		void set_account_details();
};

class mb_current_account : public mb_bank_data, public mb_address {
	public:
		long long acc_num;
};

#endif
