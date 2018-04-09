#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>
#include <fcntl.h>

extern "C" {
#include "common.h"
#include "text/text.h"
#define OUTPUT 1
}

//TEST(fibonachiTest, num0) {
//    ASSERT_EQ(fibonachi(0), 0);
//    ASSERT_EQ(fibonachi(1), 1);
//    ASSERT_EQ(fibonachi(2), 2);
//}

//TEST(fibonachiTest, greather2) {
//    ASSERT_EQ(fibonachi(5), 5);
//    ASSERT_EQ(fibonachi(10), 55);
//}

//TEST(fibonachiTest, negative) {
//    ASSERT_EQ(fibonachi(-1), 0);
//}

TEST(showlengthsTest, num0){
    text txt = create_text();
    showlengths(txt);
    ASSERT_TRUE(true);
}

TEST(showlengthsTest, params) {
    char* filename = (char*)malloc(1024);
    sprintf(filename, "%s/params.input", "INPUTDIR");
    text txt = create_text();
    load(txt, filename);
    showlengths(txt);
}

TEST(show_lengthsTest, params1) {
    char* filename = (char*)malloc(1024);
    sprintf(filename, "%s/params.input", "INPUTDIR");
    int outFd = open("testOutputFile", O_WRONLY|O_CREAT);
    int oldOutput = dup(OUTPUT);
    dup2(outFd, OUTPUT);
    show_lengths(1,filename);
    close(outFd);
    dup2(oldOutput, OUTPUT);
    char* buffer1 = (char*) malloc(1024);
    int fd1 = open("testOutputFile", O_WRONLY|O_CREAT);
    int read1 = read(fd1, buffer1, 1000);
    char* buffer2 = (char*) malloc(1024);
    int fd2 = open("results", O_WRONLY|O_CREAT);
    int read2 = read(fd2, buffer2, 1000);
    ASSERT_EQ(read1, read2);
}

#endif // FIBONACHI_H
