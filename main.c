#include <stdio.h>
#include <string.h>

struct Expense
{
	char name[30];
	int amount;
};

struct Expense expenses[] = {};
int income = 30;
int n = 0;

void print_expenses()
{
	if(n < 1)
	{
		return;
	}

	for(int i = 0; i < n; i++)
	{
		printf("%d. Name: %s, Amount: %d\n", i + 1, expenses[i].name, expenses[i].amount);
	}
}

void calculate_total()
{
	if(n < 1) 
        {
                return;
        }

	int sum = 0;

	for(int i = 0; i < n; i++)
        {
        	sum += expenses[i].amount;
	}

	if((income - sum) < 0)
	{
		printf("Total: 0\n");
	}
	else
	{
		printf("Total: %d\n", income - sum);
	}
}

void add_income()
{
	int amount = 0;
	printf("Enter the amount of income you need to add: ");
	scanf("%d", &amount);
	income += amount;
	printf("Successfully added amount (%d) to income (%d)!\n", amount, income - amount);
}

void add_expense()
{
	int exp = 0;
	char name[30] = "";
	printf("Enter the name of the expense: ");
	scanf("%s", name);
	printf("Enter the aomunt of the expense: ");
	scanf("%d", &exp);

	struct Expense ex = { "", exp };
	memcpy(ex.name, name, sizeof(name));
	expenses[n] = ex;
	n += 1;
	printf("Successfull added expense!\n");
}

void take_input()
{
	int input = 0;
	scanf("%d", &input);

	switch(input)
	{
		case 1:
			print_expenses();
			take_input();
			break;
		case 2:
			calculate_total();
			take_input();
			break;
		case 3:
			add_income();
			take_input();
			break;
		case 4:
			add_expense();
			take_input();
                        break;
		default:
			printf("Exiting...");
			break;
	}
}

int main()
{
	printf("In this expense app, your default income is 30 bucks. Use the following instructions\n");
	printf("1. Print expenses\n2. Calculate Total expenses\n3. Add income\n4. adding expense\n5. exit\n");
	take_input();

	return 0;
}
