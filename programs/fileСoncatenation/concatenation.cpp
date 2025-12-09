#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "concatenation.h"
void play (int size, char **strok)
{
	setlocale (LC_ALL, "Rus");
	char strokbuff[1024] = { 0 };
	char **buffmass = NULL;
	char **buffFILE = NULL;
	int highsize = 0;// длина файлов
	int number = 0;
	number = size / 2;//после того как мы разобрали основной массив на ключевые слова мы оставим number
	//printf("Записать программу конкатенации произвольного количества файлов,\nзапускаемую из командной строки так: cat.exe fileout = file1 + file2 + file3 …\nПрограмма должна предварительно проверить корректность строки и существование файлов,\nи только потом провести все действия.\n");
	init (size, strok);//проверяем на совпадение с ключивыми словами
	buffmass = separation (size, strok, buffmass);//хочу разбить строку на нужные мне слова
	testexistence (number, buffmass);//проверка на существование данных файлов
	highsize = high (number, buffmass, strokbuff, highsize);// количество строк во всех файлах
	buffFILE = memory (number, buffmass, buffFILE, highsize, strokbuff);
	buffFILE = init_memory (number, buffmass, buffFILE, strokbuff);
	CPYmemory(buffmass, buffFILE, highsize);
	buffFILE = del (highsize, buffFILE);
	buffmass = del (number, buffmass);//освобождаем память массива с ключивыми словами
	getchar ();
}
void init (int size, char **strok)// проверка на ключивые словав
{
	arg init;
	init.fileout = "fileout";
	init.equil = "=";
	init.plas = "+";
	init.file = "file";
	comparefileout (strok[1], &init);
	compareEQUIL (strok[2], &init);
	int i = 0;
	for ( i = 3; i < size; i++ )
	{
		if ( i % 2 == 1 )
		{
			compareFILE (strok[i], &init);
		}
		if ( i % 2 == 0 )
		{
			comparePLAS (strok[i], &init);
		}
	}
	printf ("Ok Вы ввели все верно такие файлы существуют\n");
}
void comparefileout (char *mass, arg* p)//сравним первое слово
{
	if ( strcmp (mass, p->fileout) != 0 )
	{
		ERROR ();
	}
	FILE *fp;
	remove("fileout.txt");
	fopen_s(&fp, "fileout.txt", "wb");
	fclose(fp);
}
void compareEQUIL (char *mass, arg* p)//сравнение на равно
{
	if ( strcmp (mass, p->equil) != 0 )
	{
		ERROR ();
	}
}
void comparePLAS (char *mass, arg* p)//сравнить слово и плюсы
{
	if ( (strcmp (mass, p->plas) != 0) )
	{
		ERROR ();
	}
}
void compareFILE (char *mass, arg* p)// на file и его цифры
{
	int i = 0;
	for ( i = 0; i < strlen (mass); i++ )
	{
		if ( mass[i] == p->file[i] )
		{
			continue;
		}
		if ( p->file[i + 1] == NULL )
		{
			break;
		}
		if ( mass[i] != p->file[i] )
		{
			ERROR ();
		}
	}
	for ( int j = i; j < strlen (mass); j++ )
	{
		if ( (mass[j] >= '0') && (mass[j] <= '9') )
		{
			continue;
		}
		else
		{
			ERROR ();
		}
	}
}
void ERROR ()// в случае если что- то пойдет не так
{
	printf ("Выввели что то не то! Или такого файла не существет\n");
	system ("pause");
	exit (0);
}
char **separation (int size, char **strok, char **buffmass)//хочу разбить строку на нужные мне слова
{
	int i = 0;
	int k = 0;
	buffmass = ( char** ) malloc ((size / 2)*sizeof(char*));//создали память
	for ( i = 0; i < size; i++ )
	{
		if ( i % 2 == 1 )
		{
			buffmass[k] = ( char* ) malloc ((strlen (strok[i]) + 1024)* sizeof(char));
			strcpy_s (buffmass[k], (strlen (strok[i]) + 1), strok[i]);
			strcat_s (buffmass[k], (strlen (strok[i]) + 5), ".txt");
			printf ("%s\n", buffmass[k]);
			k++;
		}
	}
	return buffmass;
}
char **del (int size, char **buffmass)// освобождаем память зная размер и элемент
{
	for ( int i = 0; i < size; i++ )//
	{
		free (buffmass[i]);
	}
	free (buffmass);
	return buffmass;
}
void testexistence (int size, char **buffmass)//а теперь хочу проверить на сущесвование данных файлов
{
	FILE *fp;
	int i = 0;
	for ( i = 0; i < size; i++ )
	{
		fopen_s (&fp, buffmass[i], "r");
		if ( fp == NULL )
		{
			ERROR ();
		}
		fclose (fp);
	}
	printf ("Вы молодец, данные файлы существуют и сейчас мы их соединим в один\n");
}
//теперь создам памть для элементов в котрые мы на время будем записывать информацию
int high (int size, char **buffmass, char *strokbuff, int highsize)
{
	FILE *fp;
	int i = 0;
	for ( i = 0; i < size; i++ )
	{
		fopen_s (&fp, buffmass[i], "r");
		while ( fgets (strokbuff, 1024, fp) )
		{
			highsize++;//количество строк
		}
		fclose (fp);
	}
	//printf ("Kоличество стрк в наших файлах %d\n", high);
	return highsize;
}
char **memory (int number, char **buffmass, char **buffFILE, int highsize, char *strokbuff)
{
	buffFILE = ( char** ) malloc (highsize*sizeof(char*));//создали память
	FILE *fp;
	int k = 0;
	for ( int i = 1; i < number; i++ )
	{
		fopen_s (&fp, buffmass[i], "r");
		while ( fgets (strokbuff, 1022, fp) != '\0' )
		{
			buffFILE[k] = ( char* ) malloc ((strlen(strokbuff)+2) * sizeof(char));
			k++;
		}
		fclose (fp);
	}
	printf ("Cейчас мы копируем и начинаем объединять наши файлы\n");
	return buffFILE;
}
char **init_memory (int number, char **buffmass, char **buffFILE, char *strokbuff)
{
	FILE *fp;
	int k = 0;
	for ( int i = 1; i < number; i++ )
	{
		fopen_s (&fp, buffmass[i], "r");
		while ( fgets (strokbuff, 1022, fp ) != '\0'  )
		{
			strcpy_s (buffFILE[k], strlen (strokbuff) + 1, strokbuff);
			strcat_s (buffFILE[k], strlen (strokbuff) + 2, "\n");
			printf ("%s\n", buffFILE[k]);
			k++;
		}
		fclose (fp);
	}
	return buffFILE;
}
void CPYmemory (char **buffmass, char **buffFILE, int highsize)
{
	FILE *fp;
	int sizefile = 0;
	fopen_s (&fp, buffmass[0], "w");
	int i = 0;
	for ( i = 0; i < highsize; i++ )
	{
		fputs (buffFILE[i], fp);
		//fwrite(buffFILE[i], sizeof(char), sizeof(buffFILE[i]), fp);
	}
	fclose (fp);
	printf ("Файлы успешно записанны. можете насладиться результатом!");
}
