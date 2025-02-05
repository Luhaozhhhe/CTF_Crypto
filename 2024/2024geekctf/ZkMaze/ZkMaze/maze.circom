pragma circom 2.0.0;
include "circomlib/circuits/sign.circom";


template IsEqualN(n) {
    signal input in[n];
    signal input to;
    signal output out[n];
    component iseq[n] ;
    for (var i = 0; i < n; i++) {
        iseq[i] = IsEqual();
        in[i] ==> iseq[i].in[0];
        to ==> iseq[i].in[1];
        iseq[i].out ==> out[i];
    }
}

template CheckNotBarrier(n) {
    signal input maze[n][n];
    signal input col;
    signal input row;
    signal tmp[n][n];
    signal tmp1[n][n];
    component iseq = IsEqualN(n * n);
    // check maze[row][col] not equal to 1
    var sum = 0;
    for (var i = 0; i < n; i++) {
        for (var j = 0; j < n; j++) {
            iseq.in[i * n + j] <== i * n + j;
        }
    }
    row * n + col ==> iseq.to;
    for (var i = 0; i < n; i++) {
        for (var j = 0; j < n; j++) {
            tmp[i][j] <== iseq.out[i * n + j] * maze[i][j];
            sum += tmp[i][j];
        }
    }
    sum === 0;
}

template getMove(start) {
    signal input move;
    signal tmp;
    signal tmp1;
    signal output out;
    component GreaterThanStart = GreaterEqThan(252); // move >= start
    move ==> GreaterThanStart.in[0];
    start     ==> GreaterThanStart.in[1];
    component LessThanEnd = LessThan(252); // move < start + 4
    move ==> LessThanEnd.in[0];
    start + 2    ==> LessThanEnd.in[1];
    tmp <== 2 * (move - start) - 1;

    tmp1 <== tmp * GreaterThanStart.out;
    out <== tmp1 * LessThanEnd.out;
}

template checkInMaze(n) {
    signal input pos_x;
    signal input pos_y;
    signal output out;
    signal tmp_x;
    signal tmp_y;
    tmp_x <-- pos_x >= 0 && pos_x < n;
    tmp_x * (tmp_x - 1) === 0;    
    tmp_y <-- pos_y >= 0 && pos_y < n;
    tmp_y * (tmp_y - 1) === 0;
    out <== tmp_x * tmp_y;
}

template solve(n, step) {
    var HOLD  = 6;
    var LEFT  = 0;
    var RIGHT = 1;
    var DOWN  = 2;
    var UP    = 3;
    signal input goal;
    signal input answer[step];
    signal input maze[n][n];
    signal pos_x[step + 1];
    signal pos_y[step + 1];
    pos_x[0] <== 0;
    pos_y[0] <== 0;
    component move_x[step];
    component move_y[step];
    component check[step];
    component checkMaze[step];
    for (var i = 0; i < step; i++) {
        assert(answer[i] == HOLD || answer[i] == LEFT || answer[i] == RIGHT || answer[i] == UP || answer[i] == DOWN);
        move_x[i] = getMove(0);
        move_y[i] = getMove(2);
        answer[i] ==> move_x[i].move;
        answer[i] ==> move_y[i].move;
        pos_x[i + 1] <== pos_x[i] + move_x[i].out;
        pos_y[i + 1] <== pos_y[i] + move_y[i].out;
        check[i] = checkInMaze(n);
        check[i].pos_x <== pos_x[i + 1];
        check[i].pos_y <== pos_y[i + 1];
        check[i].out === 1;
        checkMaze[i] = CheckNotBarrier(n);
        checkMaze[i].maze <== maze;
        checkMaze[i].col <== pos_x[i + 1];
        checkMaze[i].row <== pos_y[i + 1];
    }
    goal === pos_x[step] + pos_y[step] * n;
}

component main {public [goal, maze]} = solve(5, 15);