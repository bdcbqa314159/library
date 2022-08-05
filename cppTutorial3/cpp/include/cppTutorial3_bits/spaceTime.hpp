#ifndef SPACETIME_H
#define SPACETIME_H

void ticking();

/*
MEGA IMPORTANT: nested loop with O(N) time complexity:


int j = 0;
for (int i = 0; i<n; i+=j){
    for (j = i+1; j<=k; j++){
        // Constant work....
    }
}

WHY? first loop : roughly n/k times
and second loop: roughly k times.
*/

#endif