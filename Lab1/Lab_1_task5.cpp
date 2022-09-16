#include "stdafx.h"
#include "locale.h"
#include <iostream>
#include <string>
using namespace std;
    int size = 3;
	int search=0;
	int i,metka;
	struct student
	{
		char famil[200];
		char name[200], facult[200];
		int Nomzach;
	} stud[3];
int   main()
{
	setlocale(LC_ALL, "Russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	for (i = 0; i < size; i++) {
        printf("Введите фамилию студента ");
        scanf("%s", &stud[i].famil);

        printf("Введите имя студента ");
        scanf("%s", &stud[i].name);

        printf("Введите название факультета студента %s %s ",stud[i].famil,stud[i].name);
        scanf("%s", &stud[i].facult);

        printf("Введите номер зачётной книжки студента %s %s ",stud[i].famil,stud[i].name);
        scanf("%d", &stud[i].Nomzach);
		printf("\n");
	}
	for(i=0;i<size;i++)
		{
			printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n",stud[i].famil,stud[i].name,
					stud[i].facult,stud[i].Nomzach);
		}
	printf("Вы хотите начать поиск по заданным параметрам? 1/0 ");
	scanf("%d",&metka);
	if (metka == 1){
	cout << "Выберите поиск по нужному критерию: "<< std::endl;
	cout << "1.Фамилия "<< std::endl;
	cout << "2.Имя "<< std::endl;
	cout << "3.Факультет "<< std::endl;
	
	
	do {
        std::cin >> search;
    } while ((search < 1) && (search > 4));
	
	switch (search){
	
	case 1:
		{
	string userFam;
    cout << "Введите фамилию для поиска: ";
	cin.sync();
    getline(std::cin, userFam);
	cout << "Результаты поиска \"" << userFam << "\": " << std::endl;
	for (int i = 0; i < size; i++) {
		if (stud[i].famil == userFam){
        cout << "2.Имя "<< stud[i].name << std::endl;
	    cout << "3.Факультет "<< stud[i].facult << std::endl;
	    cout << "4.Номер зачётной книжки "<< stud[i].Nomzach << std::endl;
		}
	}
	break;
		}
	case 2:
		{
	string userFam;
    cout << "Введите имя для поиска: ";
	cin.sync();
    getline(std::cin, userFam);
	cout << "Результаты поиска \"" << userFam << "\": " << std::endl;
	for (int i = 0; i < size; i++) {
		if (stud[i].name == userFam){
        cout << "1.Фамилия "<< stud[i].famil << std::endl;
	    cout << "3.Факультет "<< stud[i].facult << std::endl;
	    cout << "4.Номер зачётной книжки "<< stud[i].Nomzach << std::endl;
		}
	}
	break;
	}
		case 3:
		{
	string userFam;
    cout << "Введите Факультет для поиска: ";
	cin.sync();
    getline(std::cin, userFam);
	std::cout << "Результаты поиска \"" << userFam << "\": " << std::endl;
	for (int i = 0; i < size; i++) {
		if (stud[i].facult == userFam){
        cout << "1.Фамилия "<< stud[i].famil << std::endl;
	    cout << "2.Имя "<< stud[i].name << std::endl;
	    cout << "4.Номер зачётной книжки "<< stud[i].Nomzach << std::endl;
		}
	}
	break;
	}
		
	}
	}
	else
		return 0;
	getchar();
	return 0;
}

	


