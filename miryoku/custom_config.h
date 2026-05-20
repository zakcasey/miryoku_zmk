// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define MIRYOKU_CLIPBOARD_MAC

// Hyper = Cmd+Ctrl+Alt+Shift (used by Raycast hotkeys to avoid collisions)
#define HYPER(K) &kp LC(LS(LA(LG(K))))

// Repurpose the Mouse layer as a Raycast trigger layer.
// Held by Tab on the left thumb (U_LT(U_MOUSE, TAB) in the base layer).
// Each alpha sends Hyper+<letter>; bind these in Raycast (e.g. Hyper+S -> Slack).
// Letter positions mirror the Colemak-DH base layer so muscle memory carries over.
#define MIRYOKU_LAYER_MOUSE \
HYPER(Q),  HYPER(W),  HYPER(F),  HYPER(P),  HYPER(B),       HYPER(J),  HYPER(L),  HYPER(U),     HYPER(Y),   HYPER(SQT),   \
HYPER(A),  HYPER(R),  HYPER(S),  HYPER(T),  HYPER(G),       HYPER(M),  HYPER(N),  HYPER(E),     HYPER(I),   HYPER(O),     \
HYPER(Z),  HYPER(X),  HYPER(C),  HYPER(D),  HYPER(V),       HYPER(K),  HYPER(H),  HYPER(COMMA), HYPER(DOT), HYPER(SLASH), \
U_NP,      U_NP,      U_NA,      U_NA,      U_NA,           U_NA,      U_NA,      U_NA,         U_NP,       U_NP
