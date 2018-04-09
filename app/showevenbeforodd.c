/**
 * showevenbeforodd.c -- для вывода текста в следующем порядке 
следования строк: 2, 1, 4, 3, ... 
 * 
 * Copyright (c) 2017, Vlad Markov <markov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
 
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#define MAXLINE 255

static void show_line(int index, char *contents);

/**
 * Выводит содержимое указанного файла на экран
 */
void showevenbeforodd(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward2(txt, show_line);
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

