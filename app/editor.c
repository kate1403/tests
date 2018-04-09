/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed> ");
        
        /* Получаем команду */
        char *red = fgets(cmdline, MAXLINE, stdin);
        assert(red!=cmdline);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }
	
        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }
            /* Сохраняем в файл, заданный параметром */
	    if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
	    if(tracer(txt, 0) != NULL)
		show(txt);
	    else
		fprintf(stderr, "No file\n");
            continue;
        }


        /* Удалить строку*/
	if (strcmp(cmd, "deleteline")== 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "No arguments\n");
            } else {
		int num;
		sscanf(arg, "%d", &num);
		if(delete_line(txt, num))
		    fprintf(stderr, "Out of lines\n");
	    }
            continue;
        }

        /* Вставляем курсор в текст */
        if (strcmp(cmd, "ctp") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "No arguments\n");
            } else {
		int line, pos;
		sscanf(arg, "%d", &line);
	       	if((arg = strtok(NULL, " \n")) == NULL)
		    fprintf(stderr, "No 2nd argument\n");
		else{
		    sscanf(arg, "%d", &pos);
		    switch(c_to_pos(txt, line, pos)){
		    case 1:
			fprintf(stderr, "Out of lines\n");
			break;
		    case 2:
			fprintf(stderr, "Out of length\n");
			break;
		    case 3:
			fprintf(stderr, "No file\n");
			break;
		    }
		}
	    }
            continue;
        }
	

//        /* переместить курсор в заданную позицию текущей строки*/
//	if (strcmp(cmd, "mp") == 0) {
//            if ((arg = strtok(NULL, " \n")) == NULL) {
//                fprintf(stderr, "No arguments\n");
//            } else {
//		int cpos;
//		sscanf(arg, "%d", &cpos);
//		switch(r_in_cur(txt, cpos)){
//		    case 1:
//			fprintf(stderr, "Out of lines\n");
//			break;
//		    case 2:
//			fprintf(stderr, "Out of length\n");
//			break;
//		    case 3:
//			fprintf(stderr, "No file\n");
//			break;
//		    }
//	    }
//            continue;
//        }

	/* Выводим длину строк */
	if (strcmp(cmd, "showlengths") == 0) {
            if(tracer(txt, 0) != NULL)
                showlengths(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

	/* Удалить строку перед текущей */
	if(strcmp(cmd, "rp") == 0){
		if(tracer(txt, 0) != NULL)
			rp(txt);
		else
			fprintf(stderr, "No file\n");
		continue;
	}
	
        /* Переносим курсор в начало следующего слова */
        if (strcmp(cmd, "mnwbf") == 0) {
            if(tracer(txt, 0) != NULL)
                mnwbf(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }

	
	/* Вывод строк с цифрами */
	if (strcmp(cmd, "showdigits") == 0) {
	    if(tracer(txt, 0) != NULL)
		showdigits(txt);
	    else
		fprintf(stderr, "No file\n");
	    continue;
	}
	/* Удаление первой строки */
	if (strcmp(cmd, "rh") == 0)
	{
	    if(tracer(txt, 0) != NULL)
		rh(txt);
	    else
		fprintf(stderr, "No file\n");
	    continue;
	}


        /* Переместить строку в конец файла */
        if(strcmp(cmd, "ce") == 0){
                if(tracer(txt, 0) != NULL)
                        rp(txt);
                else
                        fprintf(stderr, "No file\n");
                continue;
        }

	/* Меняем строки местами в порядке 2-1 4-3 */

	if (strcmp(cmd, "showevenbeforodd") == 0) {
	    if(tracer(txt, 0) != NULL)
		showevenbeforodd(txt);
	    else
		fprintf(stderr, "No file\n");
            continue;
	}




	
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
