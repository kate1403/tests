/**
 * showlengths.c -- реализует команду вывода столбца длин строк текста
 *
 * Copyright (c) 2017, Ekaterina Zhdanovich <zhdanovi@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

void show_lengths(int index, char *contents);

/**
 * Выводит содержимое указанного файла на экран с порядковой нумерацией
 */
void showlengths(text txt)
{
    /* Применяем функцию show_lengths к каждой строке текста */
    process_forward(txt, show_lengths);
}

/**
 * Выводит содержимое указанного файла на экран с порядковой нумерацией
 */
void show_lengths(int index, char *contents)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемый параметр */
    UNUSED(index);
    //    /*Выводит номер строки на экран*/
      //  printf("%d)", index);


    /* Выводим длину строки на экран */
    printf("%d\n", (int)strlen(contents)-1);
}

