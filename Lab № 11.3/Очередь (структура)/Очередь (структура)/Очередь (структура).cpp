﻿#include <iostream>
using namespace std;

/*
	Очередь - список, но работающий по принципу FIFO (first in - first out)
	Первый элемент очереди можно удалить, последний - добавить
	Работать можно только с первым и последним элементом
*/

struct queue							// Структура "Очередь"
{
	int data;							// Информационное поле (хранит элемент очереди)
	queue* next;						// Адресное поле (хранит указатель на следующий элемент очереди)
};

queue* FormQueue(int Size)						// Функция формирования очереди
{
	int i;
	cout << "Введите элементы очереди: ";
	queue* p, *first;
	first = NULL;								// Пока нет элементов, они равны нулю
	p = new queue;                              // Выделение памяти под первый элемент
	cin >> p->data;								// Запись первого элемента
	first = p;                                  // Указывает на первый элемент
	for (i = 2; i <= Size; i++)
	{
		queue* q = new queue;					// Выделение памяти под новый элемент
		p->next = q;							// Создание указателя на следующий элемент
		p = p->next;							// Переход указателем на следующий элемент
		cin >> p->data;							// Запись нового элемента
		p->next = NULL;							// Указатель на следующий элемент равен нулю, т. к. был записан последний элемент
	}
	return first;								// Возвращаем указатель на первый элемент, т. к. с него начинается обращение
}

queue* GetLastPointer(queue* first)                  // Функция нахождения указателя на конец очереди
{
	queue* p = first;
	queue* last = NULL;
	while (p != NULL)
	{
		last = p;
		p = p->next;                                 // Переход указателем на следующий элемент
	}
	return last;
}

void PrintQueue(queue* first)						 // Функция вывода очереди
{
	if (first != NULL)
	{
		cout << "Вывожу очередь...\n";
		queue* p = first;                            // Указатель на первый элемент списка
		while (p != NULL)
		{
			cout << p->data << " ";                  // Вывод значения элемента списка
			p = p->next;                             // Переход указателем на следующий элемент
		}
		cout << endl;
	}
	else
	{
		cout << "Очередь пуста\n";
	}
}

int SizeofQueue(queue* first)                         // Функция вычисления размера очереди
{
	int Counter = 0;                                  // Счётчик
	queue* p = first;
	while (p != NULL)
	{
		Counter++;
		p = p->next;
	}
	return Counter;
}

queue* DeleteElementsInQueue(queue* first, queue* last)	// Функция изменеия очереди
{
	cout << "Произвожу удаление чётных элементов...\n";
	queue* p = first;
	queue* fst = first;
	bool f = false;										// Флажок, чтобы зайти в цикл
	int Counter = 0;									// Количество проходов по очереди
	int Size = SizeofQueue(first);						// Вычисление размера очереди
	while (Counter < Size)								// Пока не прошлись полностью по очереди
	{
		Counter++;
		if (p->data % 2 != 0)							// Если элемент нечëтный, то пропускаем
		{
			f = true;									// Как зашли в цикл, значение флажка неважно
			p = first;									// Первый элемент очереди
			queue* q = new queue;						// Выделение памяти под новый элемент очереди
			queue* pl = last;							// Указатель на последний элемент очереди
			pl->next = q;
			pl = pl->next;
			q->data = p->data;							// Запись первого элемента из 1-ой очереди во 2-ую
			last = q;									// Новый последний элемент (бывший первый)
			q->next = NULL;								// У последнего элемента указатель нулевой
			queue* pf = p->next;						// Указатель на следующий первый элемент
			p->next = pf;
			delete p;
			p = pf;										// Перенос указателя на следующий элемент
			first = p;									// Новый первый элемент (бывший второй)
		}
		else
		{
			f = true;									// Как зашли в цикл, значение флажка неважно
			p = first;									// Первый элемент очереди
			queue* padd = p->next;						// Указатель на следующий элемент
			delete p;									// Удаление элемента
			p = padd;									// На месте удалённого элемента находится элемент, стоящий за ним
			first = p;									// Новый первый элемент (бывший второй)
		}
	}
	return first;
}

int main()
{
	system("chcp 1251>nul");
	cout << "Введите количество элементов в очереди: ";
	int N;
	cin >> N;
	while (N < 3)
	{
		cout << "Число элементов не может быть меньше трёх. Введите новое число элементов: ";
		cin>> N;
	}
	queue* first, *last;								// Указатели на первый и последний элементы очереди
	first = FormQueue(N);								// Получение указателя на первый элемент
	last = GetLastPointer(first);						// Получение указателя на последний элемент
	PrintQueue(first);									// Вывод списка на консоль
	first = DeleteElementsInQueue(first, last);
	PrintQueue(first);
}