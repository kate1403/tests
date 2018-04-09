/**
 * rt.c -- реализует функцию очистки последней строки
 *
 * Copyright (c) 2017, Mihail Alekseev <maleksee@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Удаляет последнюю строку
 * 
 * @param txt текст
 * @returns none
 */
void rt(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }    
    
    /* Если список изначально пуст, делать ничего не надо */
    if (txt->length == 0) {
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с последнего элемента списка */
    node *current = txt->end;

    if (txt->length != 1) {
	/* Устанавливаем указатель на новую последнюю строку */
	txt->end = txt->end->previous;

	/* Освобождаем память, выделенную под текущий элемент */
	free(current);

	/* Реинициализируем текст */
	txt->length--;
	txt->end->next = NULL;
	txt->cursor->line = txt->end;
	txt->cursor->position = strlen(txt->end->contents) - 1;
    }
    else {
	/* Освобождаем память, выделенную под текущий элемент */
	free(current);
	
	/* Реинициализируем текст */
	txt->length = 0;
	txt->begin = NULL;
	txt->end = NULL;
	txt->cursor->line = NULL;
	txt->cursor->position = 0;
    }
}
