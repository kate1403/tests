/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    /* Вставляет курсор в текст */
    print_cursor(txt);
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line);
    /* Удаляет курсор из текста */
    remove_cursor(txt);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемый параметр */
    UNUSED(index);
    /* Выводим строку на экран */
    printf("%s", contents);
}

/**
 * Обработка строк с цифрами 
 */
static void showlineswithdigits(int index, char *contents)
{
    assert(contents!=NULL);
    UNUSED(index);
    int i, f;
    i=0, f = 0;
    /* Пока строка не закончится, проверять символы */
    while (contents[i]!='\0'){
	/* Если символ цифра, то вывести строку */
	if((0<=contents[i]-48)&&(contents[i]-48<=9)){
	    f = 1;
	    break;
	}
	i++;
    }
    if(f)
	printf("%s",contents);
}

/**
 * Вывод строк с цифрами 
 */
void showdigits(text txt)
{
    /* Вставляет курсор в текст */
    print_cursor(txt);
    /* Применяем функцию showlineswithdigits к каждой строке текста */
    process_forward(txt, showlineswithdigits);

    /* Удаляет курсор из текста */
    remove_cursor(txt);
}
