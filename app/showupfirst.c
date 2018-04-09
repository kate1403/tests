/**
 * showupfirst.c -- реализует команду вывода хранимого текста на экран, выводя слова с заглавных букв                                                                            
 *                                                                                                                                  
 * Copyright (c) 2017, Denis Korolevskiy <korolevs@petrsu.ru>                                                                                           
 *                                                                     
 * This code is licensed under a MIT-style license.                                                                                                                  
 */


#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_upfirst(int, char *);


/* Вызов основной функции для каждой строки загруженного файла  */
void showupfirst(text txt)
{
    process_forward(txt, show_upfirst);
}


/* Выводит на экран строку, капитализируя символы стоящие после пробела  */
static void show_upfirst(int index, char *contents){
    assert(contents != NULL);
    UNUSED(index);
    int i, len;
    len = strlen(contents);

    /* Выводим первый символ */
    if((contents[0] >= 'a') && (contents[0] <= 'z'))
	printf("%c", contents[0] - 'a'+ 'A');
	else printf("%c", contents[0]);

    /* Выводим остальные символы, капитализируем если предыдущий - пробел  */
    for(i = 1; i < len; i++)
	if((contents[i] >= 'a')
	   && (contents[i] <= 'z') && (contents[i-1] == ' '))
	printf("%c", contents[i] - 'a'+ 'A');
	else printf("%c", contents[i]);
}
