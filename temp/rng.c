//
//  rng.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "rng.h"

#include <stdlib.h>
#include <time.h>

void rng_seedRand(void) {
    srand((unsigned int)time(NULL));
}

bool rng_flipCoin(void) {
    return rand() % 2 == 1 ? true : false;
}
