/**
 * show.c -- реализует команду вывода хранимого текста на экран с порядковой нумирацией
 *
 * Copyright (c) 2017, Artur Harkovchuk <harkovch@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_num(int index, char *contents);

/**
 * Выводит содержимое указанного файла на экран с порядковой нумерацией
 */
void shownum(text txt)
{
    /* Вставляет курсор в текст */
    print_cursor(txt);
    /* Применяем функцию show_num к каждой строке текста */
    process_forward(txt, show_num);
    /* Удаляет курсор из текста */
    remove_cursor(txt);
}

/**
 * Выводит содержимое указанного файла на экран с порядковой нумерацией
 */
static void show_num(int index, char *contents)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемый параметр */
    UNUSED(index);
	/*Выводит номер строки на экран*/
	printf("%d)", index);


    /* Выводим строку на экран */
    printf("%s", contents);
}

