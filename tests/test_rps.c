#include <assert.h>
#include <stdio.h>

void foo_test(void) {
    // arrange
    int x, y;
    
    // act
    x = 1;
    y = 0;
    
    // assert
    assert(x == y);
}

int main(int argc, char* argv[]) {
    foo_test();
    printf("ALL tests passed!\n");
    
    return 0;
}
