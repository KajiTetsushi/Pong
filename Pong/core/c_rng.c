//
//  c_rng.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/28/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "c_rng.h"

void c_rng_seedRand(void) {
    srand((unsigned int)time(NULL));
}

bool c_rng_flipCoin(void) {
    return rand() % 2 == 1 ? true : false;
}
