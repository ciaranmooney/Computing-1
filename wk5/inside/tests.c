// Ciarán Mooney
// 30/12/2012 (British FOrmat)
// Triangle tests for inside.c

//assert(inTriangle(ax,ay,bx,by,cx,cy,px,py) => TRUE);
assert(inTriangle(1, 1, 4, 1, 2.5, 4, 2.5, 2) => TRUE);
assert(inTriangle(1, 1, 4, 1, 2.5, 4, 5, 3)   => FALSE);
assert(inTriangle(1, 1, 4, 1, 1, 4, 2, 2) => TRUE);
assert(inTriangle(1, 1, 4, 1, 1, 4, 3, 3) => FALSE);
assert(inTriangle(1, 1, 4, 1, 1, 4, 2, 1) => TRUE);
assert(inTriangle(1, 1, 4, 1, 1, 4, 1, 2) => TRUE);
