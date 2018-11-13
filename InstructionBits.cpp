enum Operators {
    A = 28,
    T = 5,
    E = 3,
    P = 0,
    Q = 1,
    HASH = 11,
    EXCLAMATION = 20,
    AMPERSAND = 24,
    AT = 18,
    O = 9,
    S = 12, 
    U = 7,
    G = 27,
    H = 21,
    L = 25,
    Z = 13,
    V = 31,
    //Operators below this point have unknown instructions. I haven't been able to find their bit pattern.
    // They exist purely not to break the definitions of operator meanings.
    N = 22, // Meaning - ABC -= w[n] * RS
    C = 30, // ABC += w[n] & RS
    R = 4,  // Shift ABC right arithmetically by the number of places corresponding to the
        //position of the least signicant one in the shift instruction. For example,
        //R0L, R1S, R16S and R0S shift by 1, 2, 6 and 15 places, respectively.
    I = 8, // Place the next paper tape character in the least signicant 5 bits ofm[n]:
    F = 17, // Verify the last character output.
    X = 26, // character output 
    Y = 6,
    K = 14  // Add a one to bit position 35 of ABC, counting the sign bit as bit zero. This
        //effectively rounds ABC up to 34 fractional bits.
};