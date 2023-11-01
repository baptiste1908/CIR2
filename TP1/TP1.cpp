// TP1.cpp : définit le point d'entrée de l'application.
//

#include<stdlib.h>
#include<stdio.h>

#include "TP1.h"

using namespace std;


// Les minuscule et les majuscules se suivent !!

char* minuscule(char Upper[20]) {
	for (int i = 0; i < strlen(Upper); i++) {
		Upper[i] = tolower(Upper[i]);
	}
	printf("La chaine de caractere est : %s", Upper);
	return Upper;
}

char* minuscule2(char Upper[20])
{
	for (unsigned int i = 0; i < strlen(Upper); i++)
	{
		Upper[i] = tolower(Upper[i]);
	}
	return Upper;
}


int AvecFor(int n) {
	int factorielle = 1;
	for (int i = 2; i <= n; i++) {
		factorielle = factorielle * i;
	}
	return factorielle;
}

int AvecWhile(int n) {
	int factorielle = 1;
	int compteur = 1;
	
	while (compteur < n) {
		
		compteur++;
		factorielle = factorielle * compteur;
	} 
	return factorielle;
}

int Récursif(int n, int factorielle)
{
	if (n == 1)
	{
		return factorielle;
	}
	else
	{
		factorielle = factorielle * n;

		return Récursif(n - 1, factorielle);
	}
}


void tri(int tableau[10]) {

	for (int i = 0; i < 10; i++) {
		for (int i = 0; i < 10 - 1; i++) {
			if (tableau[i] > tableau[i + 1]) {
				int tmp = tableau[i];
				tableau[i] = tableau[i + 1];
				tableau[i + 1] = tmp;
			}
		}
	}
}















int main()
{
	// Exercice 1
	printf("Hello World\n");

	//Exercice 2
	double a, b, c;
	double r1, r2;

	printf("Veuillez entrer les inconnues de l'équation ax^2 + bx + c : \n");
	printf("a : ");
	scanf_s("%lf", &a); 
	printf("b : ");
	scanf_s("%lf", &b);
	printf("c : ");
	scanf_s("%lf", &c);

	double delta = b * b - 4 * a * c;

	if (delta > 0) {
		r1 = -b + sqrt(delta) / (2 * a);
		r2 = -b - sqrt(delta) / (2 * a);
		printf(" Les racines sont %lf et %lf", r1, r2);
	}
	if (delta < 0) {
		printf("Pas de solutions reels !");
	}
	if (delta == 0) {
		r1 = -b / (2 * a);
		printf("La seul solution est %lf", r1);
	}

	printf("\n");

	//Exercice 3


	char Upper[20] = { 0 };
	printf("Veuillez entrer votre chaine de caractères EN MAJUSCULE ci-dessous : \n");
	scanf_s("%s", Upper, 19);
	minuscule(Upper);

	printf("\n");

	// Exercice 4  : Les boucles

	int n = 0;
	printf("Entrer un nombre : ");
	scanf_s("%d", &n);
	printf("%d\n", AvecFor(n));
	printf("%d\n", AvecWhile(n));
	printf("%d\n", Récursif(n, 1));

	// Exercice 5 : Le pendu 

	char Mot[100];
	char Hidden[100];
	printf("Veuillez entrer le mot a deviner : \n");
	scanf_s("%100s", Mot, 100);
	if (strlen(Mot) < 3)
	{
		printf("Veuillez choisir un mot de plus de 2 lettres, Merci!\n");
		scanf_s("%100s", Mot, 100);
	}
	minuscule2(Mot);
	strcpy_s(Hidden, 100, Mot);
	int size = strlen(Hidden);
	for (int i = 1; i < size - 1; i++)
	{
		Hidden[i] = '_';
	}
	int fin = 10;
	int end = 0;
	int tente = 0;
	int verif = 0;
	char Lettre[2];
	while (fin > 0 && end == 0)
	{
		printf("Il vous reste : %d tentatives\n", fin);
		printf("%s\n", Hidden);
		printf("Entrez un caractere : ");
		scanf_s("%1s", Lettre, 2);
		minuscule2(Lettre);
		for (int i = 1; i < size - 1; i++)
		{
			if (Lettre[0] == Mot[i])
			{
				Hidden[i] = Lettre[0];
				tente++;
			}
		}
		if (tente != 0)
		{
			fin++;
		}
		tente = 0;
		fin--;
		verif = 0;
		for (int i = 0; i < size; i++)
		{
			if (Hidden[i] == Mot[i])
			{
				verif++;
			}
		}
		if (verif == size)
		{
			end = 1;
		}
	}
	if (end == 1)
	{
		printf("Vous avez trouve le mot %s. Bravo, vous avez gagne!\n", Hidden);
	}
	else
	{
		printf("Vous avez perdu, le mot etait : %s\n", Mot);
	}


	

	// Exercice 6 : Tableau 2 entrees, ordre croissant 

	int tableau[10] = { 0 };
	int val = 0;

	printf("Entrez les valeurs a rentrer :\n");

	for (int i = 1; i <= 10; i++) {
		printf("Entrer la valeurs numéro %d\n", i);
		scanf_s("%d", &val);
		tableau[i - 1] = val;
	}

	tri(tableau);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", tableau[i]);
	}



	EXIT_SUCCESS;
}

