/**
 * tracer.c -- возвращает ссылку на строку по индексу
 *
 * Copyright (c) 2017, Vladislav Klimenko <klimenko@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Возвращает ссылку на строку
 * 
 * @param txt текст
 * @param index индекс строки
 * @returns ref ссылка на строку
 */

node *tracer(text txt, int index){
    /* Обращение к отрицательной строке */
    if(index < 0) return NULL;
    int i;
    /* Выход за пределы строк */
    if((int)txt -> length <= index) return NULL;
    struct _node *ref = txt -> begin;
    for(i = 0; i < index; i++)
       ref = ref -> next;
    return ref;
}
/**
 * Возвращает индекс строки курсора
 * @param txt
 * @return index
 *
 */
int currentline(text txt){
    int i = 0;
    node *line = txt -> begin;
    while(line != NULL)
	if(txt -> cursor -> line == line)
	    return i;
	else {
	    line = line -> next;
	    i++;
	}
    return -1;
}

/* Удаляет строку перед текущей */
void rp(text txt){
	delete_line(txt, currentline(txt)-1);
}
/**
 * Удаляет первую строку
 * @param txt
 * @return none
 *
 */
void rh(text txt)
{
    /* Если в файле только одна строка, то удалить его полностью */
    if(txt->length == 1)
	remove_all(txt);
    /* Ставим курсор во вторую строку, если курсор в первой строке */
    if(txt->cursor->line == txt->begin){
	txt->cursor->position=0;
	txt->cursor->line = txt->begin->next;
    }
    /* Удаляем первую строку из памяти и переносим указатели */
    txt->begin = txt->begin->next;
    free(txt->begin->previous);
    txt->begin->previous = NULL;
    txt->length--;

}

/*Перемещает строку в конец файла*/
void ce(text txt){
    int line = currentline(txt);
    append_line(txt,txt->cursor->line->contents); 
	delete_line(txt, line);
}
