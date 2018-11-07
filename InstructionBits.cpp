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
    S = 29, // See EDSAC instruction set document - ambiguity about S / A and 11100. Set to 29 temporarily. 
    U = 7,
    G = 27,
    H = 21,
    V = 32,
    L = 25,
    Z = 13,
    //Operators below this point have unknown instructions. I haven't been able to find their bit pattern.
    // They exist purely not to break the definitions of operator meanings.
    N,
    C,
    R,
    I,
    F,
    X,
    Y
};