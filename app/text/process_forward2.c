/**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include "_text.h"
/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */ 
void process_forward2(text txt, void (*process)(int index, char *contents)) {
	
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    int index = 0;
    
    /* К каждой строке текста применяем обработчик */
	char* str2;
	while(current){
		if(index % 2 == 0){
			str2 = current -> contents;
			if(current->next == NULL)
				printf("%s", str2);
			current = current->next;
			index++;
		}
		else
		{
			process(index, current->contents);
			current = current->next;
			index++;
			printf("%s", str2);
		}
	}

}
