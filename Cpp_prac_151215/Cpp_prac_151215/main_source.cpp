#include <stdio.h>
#include "Eigen/Dense"
#include <Windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX_NUM_ACCOUNT 10

//typedef struct account {
//	int id;
//	char name[10];
//	int balance;
//}Account;

class Account {
public:
	int id;
	char name[10];
	int balance;
};

void create(Account* acc[], int &num_acc, int id, char name[], int balance);
void deposit(Account* acc[], int num_acc, int id, int deposit);
void withdraw(Account* acc[], int num_acc, int id, int withdraw);
void showall(Account* acc[], int num_acc);

int choice;

void main() {
	int num_acc = 1;
	Account* acc[MAX_NUM_ACCOUNT+1];

	int id;
	char name[10];
	int money;

	while (1) {
		printf("-----Menu-----\n");
		printf("1. ���°���\n");
		printf("2. �� ��\n");
		printf("3. �� ��\n");
		printf("4. �������� ��ü ���\n");
		printf("5. ���α׷� ����\n");
		printf("����: \n");
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "[���°���]" << endl;
			cout << "����ID: ";
			cin >> id;
			cout << "�� ��: ";
			cin >> name;
			cout << "�Աݾ�: ";
			cin >> money;
			create(acc, num_acc, id, name, money);
			cout << endl;
			break;
		case 2:
			cout << "[�� ��]" << endl;
			cout << "����ID: ";
			cin >> id;
			cout << "�Աݾ�: ";
			cin >> money;
			deposit(acc, num_acc, id, money);
			cout << endl;
			break;
		case 3:
			cout << "[�� ��]" << endl;
			cout << "����ID: ";
			cin >> id;
			cout << "��ݾ�: ";
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
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���\n");
			break;
		}
	}
	
	//create(acc, num_acc, 115, "�̿켮", 15000);
	//deposit(acc, num_acc, 115, 15000);
	//withdraw(acc, num_acc, 115, 10000);
	//showall(acc, num_acc);
	
	for (int i = 1; i < num_acc; i++) {
		free(acc[i]);
	}

	Sleep(30000);
}

void create(Account* acc[], int &num_acc, int id, char name[], int balance) {
	acc[num_acc] = (Account*)malloc(sizeof(Account));

	acc[num_acc]->id = id;
	strcpy(acc[num_acc]->name, name);
	acc[num_acc]->balance = balance;

	num_acc++;
}

void deposit(Account* acc[], int num_acc, int id, int deposit) {
	for (int i = 1; i <= num_acc-1; i++) {
		if (acc[i]->id == id) {
			acc[i]->balance = acc[i]->balance + deposit;
		}
	}
}

void withdraw(Account* acc[], int num_acc, int id, int withdraw) {
	for (int i = 1; i <= num_acc - 1; i++) {
		if (acc[i]->id == id) {
			acc[i]->balance = acc[i]->balance - withdraw;
		}
	}
}

void showall(Account* acc[], int num_acc) {
	for (int i = 1; i <= num_acc-1; i++) {
		printf("����ID = %d\n", acc[i]->balance);
		printf("�� �� = %d\n", acc[i]->id);
		printf("�� �� = %s\n", acc[i]->name);
		
	}
}