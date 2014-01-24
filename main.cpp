/* 
 * File:   main.cpp
 * Author: meckya
 *
 * Created on 9. Januar 2014, 11:23
 */

#include <cstdlib>
#include "BinaryWriter.h"
#include "BinaryLoader.h"
#include "Bag.h"
#include <stdio.h>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    /*
    Bag<int> b(3);
    b.add(10);
    b.add(20);
    b.add(30);
    printf("size: %d - capacity %d\n",b.size(),b.capacity());
    int c = b.get(1);
    printf("c: %d\n",c);
    b.add(40);
    b.add(50);
    printf("size: %d - capacity %d\n",b.size(),b.capacity());
    b.remove(1);
    Bag<int> nb(3);
    nb.addAll(b);
    if ( nb.contains(40) ) {
        printf("found 40!!\n");
    }
    printf("nb - size: %d - capacity %d\n",nb.size(),nb.capacity());
     */
    int result = Catch::Session().run( argc, argv );
    /*
    BinaryWriter s;
    int signature[] = {4,19,2,4};
    if ( s.open("TestMe.bin",signature,4) == IO_OK ) {
        for ( int i = 0; i < 3; ++i ) {
            if ( s.startChunk(i,i + 1) == IO_OK ) {
                s.write(i * 10 + 1);
                s.write(i * 10 + 2);
                s.write(i * 10 + 3);
                s.closeChunk();
            }
        }
        s.close();
    }
    BinaryLoader loader;
    int value;
    if ( loader.open("TestMe.bin",signature,4) == IO_OK ) {
        printf("chunks %d\n",loader.numChunks());
        loader.reset();
        while ( loader.openChunk() == IO_OK ) {
            printf("id %d\n",loader.getChunkID());
            if ( loader.getChunkID() == 1 ) {
                for ( int i = 0; i < 3; ++i ) {            
                  loader.read(&value);
                  printf("%d\n",value);
                }
            }
            loader.closeChunk();
        }
        //else {
            //printf("Error opening chunk - code %d\n",loader.getStatusCode());
        //}
        loader.close();
    }
    else {
        printf("invalid file\n");
    }
     */
    return 0;
}

