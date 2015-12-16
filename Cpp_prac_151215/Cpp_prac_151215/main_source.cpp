#include <stdio.h>
#include "Eigen/Dense"
#include <Windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX_NUM_ACCOUNT 10
#define MAX_CHAR_SIZE 10

//typedef struct account {
//	int id;
//	char name[10];
//	int balance;
//}Account;

class Account {

private:
	int id;
	char* name;
	int balance;
public:

	int getid() {
		return id;
	}
	void putid(int id) {
		this->id = id;
	}

	char* getname() {
		return name;
	}

	void putname(char* name) {
		this->name = new char[MAX_CHAR_SIZE + 1];
		strcpy(this->name, name);
	}

	int getbalance() {
		return balance;
	}

	void putbalance(int balance) {
		this->balance = balance;
	}

	Account::Account() {
		id = 0;
		balance = 0;
	};
	Account::~Account() {
		delete(this->name);
	}
};

const int name_len = MAX_CHAR_SIZE;

void create(Account* acc[], int &num_acc, int id, char name[], int name_len, int balance);
void deposit(Account* acc[], int num_acc, int id, int deposit);
void withdraw(Account* acc[], int num_acc, int id, int withdraw);
void showall(Account* acc[], int num_acc);

int num_acc = 1;
int choice;

void main() {

	Account* acc[MAX_NUM_ACCOUNT+1];

	int id;
	char name[10];
	int money;

	while (1) {
		printf("-----Menu-----\n");
		printf("1. 계좌개설\n");
		printf("2. 입 금\n");
		printf("3. 출 금\n");
		printf("4. 계좌정보 전체 출력\n");
		printf("5. 프로그램 종료\n");
		printf("선택: \n");
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "[계좌개설]" << endl;
			cout << "계좌ID: ";
			cin >> id;
			cout << "이 름: ";
			cin >> name;
			cout << "입금액: ";
			cin >> money;
			create(acc, num_acc, id, name, name_len, money);
			cout << endl;
			break;
		case 2:
			cout << "[입 금]" << endl;
			cout << "계좌ID: ";
			cin >> id;
			cout << "입금액: ";
			cin >> money;
			deposit(acc, num_acc, id, money);
			cout << endl;
			break;
		case 3:
			cout << "[출 금]" << endl;
			cout << "계좌ID: ";
			cin >> id;
			cout << "출금액: ";
			cin >> money;
			withdraw(acc, num_acc, id, money);
			cout << endl;
			break;
		case 4:
			showall(acc, num_acc);
			cout << endl;
			break;
		case 5:
			return;
		default:
			printf("잘못 입력하셨습니다. 다시 입력해주세요\n");
			break;
		}
	}

	for (int i = 1; i < num_acc; i++) {
		free(acc[i]);
	}

	Sleep(30000);
}

void create(Account* acc[], int &num_acc, int id, char name[], int name_len, int balance) {
	
	acc[num_acc] = (Account*)malloc(sizeof(Account));
	//acc[num_acc]->name = (char*)malloc(sizeof(char)*MAX_CHAR_SIZE);

	acc[num_acc]->putid(id);
	acc[num_acc]->putname(name);
	//strcpy(acc[num_acc]->name, name);
	acc[num_acc]->putbalance(balance);

	num_acc++;
}

void deposit(Account* acc[], int num_acc, int id, int deposit) {
	for (int i = 1; i <= num_acc-1; i++) {
		if (acc[i]->getid() == id) {
			acc[i]->putbalance(acc[i]->getbalance() + deposit);
		}
	}
}

void withdraw(Account* acc[], int num_acc, int id, int withdraw) {
	for (int i = 1; i <= num_acc - 1; i++) {
		if (acc[i]->getid() == id) {
			acc[i]->putbalance(acc[i]->getbalance() - withdraw);
		}
	}
}

void showall(Account* acc[], int num_acc) {
	for (int i = 1; i <= num_acc-1; i++) {
		printf("계좌ID = %d\n", acc[i]->getid());
		printf("이 름 = %s\n", acc[i]->getname());
		printf("잔 액 = %d\n", acc[i]->getbalance());
	}
}
