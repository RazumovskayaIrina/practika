#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>;
#include <fstream>;
#include <iomanip>;
#include <windows.h>;
#include <conio.h>;
using namespace std;
const int dl = 30;
const char F[] = "text1.cpp";
struct bibl { 
	char ud[dl]; 
	char fm[dl]; 
	char en[5]; 
	char na[dl]; 
	int go; 
	int kl; 
	bibl *l;
	bibl *r; };

void prob(char *ss);
void pod(char *ss);
int input(bibl &buf);
void input(bibl *&nach, bibl x);
void menu();
void output();
void output(bibl *nach, bool &e, int menu);
void output(bibl *nach, bool &e, char *ss);
void output(bibl *nach, ofstream &y);
bibl* _delete(bibl *nach, char *ss);
void _delete(bibl *&nach);
