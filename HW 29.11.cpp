#include <iostream>
#include <ctime>
using namespace std;

struct Device {
	string name;
	string tipedevice;
	string model;
	string brand;
	double price;
};

struct DateTime {
	int day;
	int month;
	int year;
	int daybuy;
	int monthbuy;
	int yearbuy;
	int daygua;
	int monthgua;
	int yeargua;
};

void WhatDevice(Device& d) {
	cout << "Введите название товара -> ";
	cin >> d.name;
	cout << "Введите тип устройства -> ";
	cin >> d.tipedevice;
	cout << "Введите модель товара -> ";
	cin >> d.model;
	cout << "Введите брэнд товара -> ";
	cin >> d.brand;
	cout << "Введите цену товара -> ";
	cin >> d.price;
	if (d.price < 0) {
		cout << "Неверно введена цена";
		throw "НЕПРАВИЛЬНЫЙ ПРАЙС!!!";
	}

 }

void Random(DateTime& b) {
	cout << "Введите сегодняшний день -> ";
	cin >> b.day;
	if (b.day < 0 || b.day > 31) {
		cout << "Неверно введен день";
		throw "НЕПРАВИЛЬНЫЙ ДЕНЬ!!!";
	}
	cout << "Введите месяц -> ";
	cin >> b.month;
	if (b.month < 0 || b.month > 12) {
		cout << "Неверно введен месяц";
		throw "НЕПРАВИЛЬНЫЙ МЕСЯЦ!!!";
	}
	cout << "Введите год -> ";
	cin >> b.year;
	if (b.year < 0 || b.year > 2100) {
		cout << "Неверно введен год";
		throw "НЕПРАВИЛЬНЫЙ ГОД!!!";
	}
	
	b.daygua = rand() % 28 + 1;
	b.monthgua = rand() % 12 + 1;
	b.yeargua = rand() % 5 + 2021;
	b.daybuy = rand() % 28 + 1;
	b.monthbuy = rand() % 12 + 1;
	b.yearbuy = rand() % 3 + 2020;
}

void PrintDevice(const Device& d) {
	cout << d.name << "\n";
	cout << d.model << "\n";
	cout << d.tipedevice << "\n";
	cout << d.brand << "\n";
	cout << d.price << "\n";
}

void PrintDate(const DateTime& b) {
	cout << "Покупка совершенна: " << b.daybuy << "." << b.monthbuy << "." << b.yearbuy << "\n";
	cout << "Гарантия до: " << b.daygua << "." << b.monthgua << "." << b.yeargua << "\n";

}

void Guarantee(DateTime& b) {
	if (b.year > b.yeargua) {
		cout << "Гарантия завершенна";
	}
	else if (b.year < b.yeargua) {
		cout << "Гарантия действительна";
	}
	else if (b.year == b.yeargua || b.month < b.monthgua || b.day < b.month) {
		cout << "Гарантия завершенна";
	}
	else if (b.year == b.yeargua || b.month > b.monthgua || b.day > b.month) {
		cout << "Гарантия активна";
	}
	else if (b.year == b.yeargua || b.month == b.monthgua || b.day < b.month) {
		cout << "Гарантия завершенна";
	}
	else if (b.year == b.yeargua || b.month == b.monthgua || b.day > b.month) {
		cout << "Гарантия активна";
	}
	else {
		cout << "Сегодня последний день гарантии!";
	}
}int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	Device v;
	DateTime f;
	Random(f);
	PrintDevice(v);
	PrintDate(f);
	Guarantee(f);
}