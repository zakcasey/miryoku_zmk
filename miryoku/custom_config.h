// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define MIRYOKU_CLIPBOARD_MAC

// Hyper = Cmd+Ctrl+Alt+Shift (used by Raycast hotkeys to avoid collisions)
#define HYPER(K) &kp LC(LS(LA(LG(K))))

// Layer list - rename Mouse -> Raycast and Media -> Mac for the OLED display.
// TAP, EXTRA, and BUTTON entries are kept so that &u_to_U_TAP / &u_to_U_EXTRA /
// &u_to_U_BUTTON references in other layers still compile, but their bindings
// are neutered below (see MIRYOKU_DEAD_LAYER).
#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Raycast") \
MIRYOKU_X(MEDIA,  "Mac") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

#define U_BASE   0
#define U_EXTRA  1
#define U_TAP    2
#define U_BUTTON 3
#define U_NAV    4
#define U_MOUSE  5
#define U_MEDIA  6
#define U_NUM    7
#define U_SYM    8
#define U_FUN    9

// Base: drop the BUTTON layer-tap on the outer pinkies (Z and /), so the BUTTON
// layer can no longer be activated during normal typing.
#define MIRYOKU_LAYER_BASE \
&kp Q,             &kp W,             &kp F,             &kp P,             &kp B,             &kp J,             &kp L,             &kp U,             &kp Y,             &kp SQT,           \
U_MT(LCTRL, A),    U_MT(LALT, R),     U_MT(LGUI, S),     U_MT(LSHFT, T),    &kp G,             &kp M,             U_MT(LSHFT, N),    U_MT(LGUI, E),     U_MT(LALT, I),     U_MT(LCTRL, O),    \
&kp Z,             U_MT(RALT, X),     &kp C,             &kp D,             &kp V,             &kp K,             &kp H,             &kp COMMA,         U_MT(RALT, DOT),   &kp SLASH,         \
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, SPACE),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

// Dead-layer template for TAP/EXTRA/BUTTON. All keys are inert except position 3
// (top row, 4th column) which double-taps back to BASE - the same escape pattern
// used by NAV/NUM/SYM/FUN. These layers are unreachable through normal typing
// (BASE no longer holds BUTTON, and TAP/EXTRA were only ever reached via the
// remote top-corner u_to_U_* keys on secondary layers).
#define MIRYOKU_DEAD_LAYER \
U_NA,              U_NA,              U_NA,              &u_to_U_BASE,      U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              \
U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              \
U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_TAP    MIRYOKU_DEAD_LAYER
#define MIRYOKU_LAYER_EXTRA  MIRYOKU_DEAD_LAYER
#define MIRYOKU_LAYER_BUTTON MIRYOKU_DEAD_LAYER

// Raycast layer (held by Tab, occupies the MOUSE slot).
// Each alpha sends Hyper+<letter>; bind these in Raycast (e.g. Hyper+S -> Slack).
// Letter positions mirror the Colemak-DH base layer so muscle memory carries over.
#define MIRYOKU_LAYER_MOUSE \
HYPER(Q),          HYPER(W),          HYPER(F),          HYPER(P),          HYPER(B),          HYPER(J),          HYPER(L),          HYPER(U),          HYPER(Y),          HYPER(SQT),        \
HYPER(A),          HYPER(R),          HYPER(S),          HYPER(T),          HYPER(G),          HYPER(M),          HYPER(N),          HYPER(E),          HYPER(I),          HYPER(O),          \
HYPER(Z),          HYPER(X),          HYPER(C),          HYPER(D),          HYPER(V),          HYPER(K),          HYPER(H),          HYPER(COMMA),      HYPER(DOT),        HYPER(SLASH),      \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NP,              U_NP

// Mac layer (held by Esc, occupies the MEDIA slot).
// S = screenshot, capture selected portion (Cmd+Shift+4)
// N = previous Space / "swipe left between apps" (Ctrl+Left)
// O = next Space / "swipe right between apps" (Ctrl+Right)
// E = volume down, I = volume up (unchanged from default Miryoku Media layout)
// Right-side BT/output/play controls and left-side mods retained.
#define MIRYOKU_LAYER_MEDIA \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RGB_TOG,         U_RGB_EFF,         U_RGB_HUI,         U_RGB_SAI,         U_RGB_BRI,         \
&kp LGUI,          &kp LALT,          &kp LS(LG(N4)),    &kp LSHFT,         U_NA,              U_EP_TOG,          &kp LC(LEFT),      &kp C_VOL_DN,      &kp C_VOL_UP,      &kp LC(RIGHT),     \
U_NA,              &kp RALT,          &u_to_U_FUN,       &u_to_U_MEDIA,     U_NA,              &u_out_tog,        &u_bt_sel_0,       &u_bt_sel_1,       &u_bt_sel_2,       &u_bt_sel_3,       \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp C_STOP,        &kp C_PP,          &kp C_MUTE,        U_NP,              U_NP

// Sym: replace the previous { (LS(LBRC)) at the P position with the GBP sign.
// Assumes macOS US English layout where Option+3 emits the pound sign.
// If you switch macOS to British layout, change LA(N3) to LS(N3).
#define MIRYOKU_LAYER_SYM \
&kp LBRC,          &kp AMPS,          &kp ASTRK,         &kp LA(N3),        &kp RBRC,          U_NA,              &u_to_U_BASE,      &u_to_U_EXTRA,     &u_to_U_TAP,       U_BOOT,            \
&kp COLON,         &kp DLLR,          &kp PRCNT,         &kp CARET,         &kp PLUS,          U_NA,              &kp LSHFT,         &kp LCTRL,         &kp LALT,          &kp LGUI,          \
&kp TILDE,         &kp EXCL,          &kp AT,            &kp HASH,          &kp PIPE,          U_NA,              &u_to_U_SYM,       &u_to_U_MOUSE,     &kp RALT,          U_NA,              \
U_NP,              U_NP,              &kp LPAR,          &kp RPAR,          &kp UNDER,         U_NA,              U_NA,              U_NA,              U_NP,              U_NP
