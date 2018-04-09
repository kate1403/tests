/**
 * showrev.c -- реализует команду вывода хранимого текста на экран в обратном   * порядке
 *
 * Copyright (c) 2017, Mihail Alekseev <maleksee@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents);

/**
 * Выводит содержимое указанного файла на экран в обратном порядке
 */
void showrev(text txt)
{
    /* Вставляет курсор в текст */
    print_cursor(txt);
    /* Применяем функцию show_line к каждой строке текста */
    process_backward(txt, show_line);
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
