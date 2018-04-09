/**
 * j.c -- объединяет сткроку с курсором со следующей строкой
 *
 * Copyright (c) 2017, Kseniya Kuznetsova <kkuzneco@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void j (text txt){
    int i = 0, k=0;
    node *line = txt->cursor->line;
    if (txt -> cursor -> line == txt -> end)
	printf("Can not be combined: the cursor is in the last line\n");
    else{
	while (line->contents[i]!='\n')
	    i++;
	line->contents[i] = ' ';
	while (txt-> cursor -> line -> next -> contents[k]!='\n'){
	    line -> contents[i+1+k] = txt-> cursor -> line -> next -> contents[k];
	    k++;
	}
	line -> contents[i+1+k] = '\n';
	delete_line(txt, currentline(txt)+1);
    }
}




