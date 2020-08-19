// Mapping pin <-> row/col
// 0 is top, 10 is bottom
// cols are input (left connector)
// rows are output (right connector)

static inline char get_pin_col(char col)
{
    return 33 - col;
}

static inline char get_pin_row(char row)
{
    return 23 - row;
}

/* Mapping definition */
typedef enum {
    MOD_NO = 0,
    MOD_SHIFT = 1,
    MOD_CODE = 2,
    MOD_ACUTE = 4,
    MOD_AGRAVE = 8,
    MOD_ACIRC = 16,
    MOD_DELAY = 32,
    MOD_KBD2 = 64
} Modifier;

typedef struct {
    char row;
    char col;
    char mod;
} Combi;

typedef struct {
    unsigned char latin1;
    Combi combi;

} MapElement;

const MapElement mapping[] = {
    {6, {6, 4, MOD_CODE | MOD_DELAY}},  /* Code-l CTRL-F Force */
    {7, {1, 7, MOD_CODE | MOD_DELAY}},  /* Code-b CTRL-G Bold */
    {10, {8, 4, MOD_NO | MOD_DELAY}},   /* Return CTRL-J Line Feed */
    {12, {8, 4, MOD_CODE | MOD_DELAY}}, /* Code-Return CTRL-L Page feed */
    {13, {8, 4, MOD_NO | MOD_DELAY}},   /* Return CTRL-M Carriage Return */
    {18, {2, 4, MOD_CODE | MOD_DELAY}}, /* Code-k CTRL-R Init */
    {21, {6, 3, MOD_CODE | MOD_DELAY}}, /* Code-U CTRL-U Underline */
    {23, {7, 1, MOD_CODE | MOD_DELAY}}, /* Code-= CTRL-W kbd1 */
    {24, {9, 0, MOD_CODE | MOD_DELAY}}, /* Code-= CTRL-X kbd2 */
    {32, {3, 9, MOD_NO}},       /* Space */
    {33, {0, 0, MOD_SHIFT}},    /* ! */
    {34, {0, 1, MOD_SHIFT}},    /* " */
    {35, {0, 7, MOD_NO}},       /* # */
    {36, {2, 0, MOD_SHIFT}},    /* $ */
    {37, {3, 0, MOD_SHIFT}},    /* % */
    {38, {3, 1, MOD_SHIFT}},    /* & */
    {39, {0, 7, MOD_SHIFT}},    /* ' */
    {40, {6, 0, MOD_SHIFT}},    /* ( */
    {41, {7, 0, MOD_SHIFT}},    /* ) */
    {42, {8, 2, MOD_SHIFT}},    /* * */
    {43, {8, 2, MOD_NO}},       /* + */
    {44, {2, 7, MOD_NO}},       /* , */
    {45, {6, 8, MOD_NO}},       /* - */
    {46, {6, 7, MOD_NO}},       /* . */
    {47, {6, 1, MOD_SHIFT}},    /* / */
    {48, {7, 1, MOD_NO}},       /* 0 */
    {49, {0, 0, MOD_NO}},       /* 1 */
    {50, {0, 1, MOD_NO}},       /* 2 */
    {51, {2, 1, MOD_NO}},       /* 3 */
    {52, {2, 0, MOD_NO}},       /* 4 */
    {53, {3, 0, MOD_NO}},       /* 5 */
    {54, {3, 1, MOD_NO}},       /* 6 */
    {55, {6, 1, MOD_NO}},       /* 7 */
    {56, {6, 0, MOD_NO}},       /* 8 */
    {57, {7, 0, MOD_NO}},       /* 9 */
    {58, {6, 7, MOD_SHIFT}},    /* : */
    {59, {2, 7, MOD_SHIFT}},    /* ; */
    {61, {7, 1, MOD_SHIFT}},    /* = */
    {63, {8, 1, MOD_SHIFT}},    /* ? */
    {65, {3, 4, MOD_SHIFT}},    /* A */
    {66, {1, 7, MOD_SHIFT}},    /* B */
    {67, {3, 8, MOD_SHIFT}},    /* C */
    {68, {1, 5, MOD_SHIFT}},    /* D */
    {69, {0, 3, MOD_SHIFT}},    /* E */
    {70, {1, 4, MOD_SHIFT}},    /* F */
    {71, {0, 4, MOD_SHIFT}},    /* G */
    {72, {0, 5, MOD_SHIFT}},    /* H */
    {73, {6, 2, MOD_SHIFT}},    /* I */
    {74, {2, 5, MOD_SHIFT}},    /* J */
    {75, {2, 4, MOD_SHIFT}},    /* K */
    {76, {6, 4, MOD_SHIFT}},    /* L */
    {77, {2, 8, MOD_SHIFT}},    /* M */
    {78, {1, 8, MOD_SHIFT}},    /* N */
    {79, {7, 2, MOD_SHIFT}},    /* O */
    {80, {7, 3, MOD_SHIFT}},    /* P */
    {81, {1, 2, MOD_SHIFT}},    /* Q */
    {82, {0, 2, MOD_SHIFT}},    /* R */
    {83, {3, 5, MOD_SHIFT}},    /* S */
    {84, {2, 2, MOD_SHIFT}},    /* T */
    {84, {3, 2, MOD_NO}},       /* T */
    {85, {6, 3, MOD_SHIFT}},    /* U */
    {86, {3, 7, MOD_SHIFT}},    /* V */
    {87, {1, 3, MOD_SHIFT}},    /* W */
    {88, {7, 8, MOD_SHIFT}},    /* X */
    {89, {7, 7, MOD_SHIFT}},    /* Y */
    {90, {2, 3, MOD_SHIFT}},    /* Z */
    {95, {6, 8, MOD_SHIFT}},    /* _ */
    {97, {3, 4, MOD_NO}},       /* a */
    {98, {1, 7, MOD_NO}},       /* b */
    {99, {3, 8, MOD_NO}},       /* c */
    {100, {1, 5, MOD_NO}},      /* d */
    {101, {0, 3, MOD_NO}},      /* e */
    {102, {1, 4, MOD_NO}},      /* f */
    {103, {0, 4, MOD_NO}},      /* g */
    {104, {0, 5, MOD_NO}},      /* h */
    {105, {6, 2, MOD_NO}},      /* i */
    {106, {2, 5, MOD_NO}},      /* j */
    {107, {2, 4, MOD_NO}},      /* k */
    {108, {6, 4, MOD_NO}},      /* l */
    {109, {2, 8, MOD_NO}},      /* m */
    {110, {1, 8, MOD_NO}},      /* n */
    {111, {7, 2, MOD_NO}},      /* o */
    {112, {7, 3, MOD_NO}},      /* p */
    {113, {1, 2, MOD_NO}},      /* q */
    {114, {0, 2, MOD_NO}},      /* r */
    {115, {3, 5, MOD_NO}},      /* s */
    {116, {2, 2, MOD_NO}},      /* t */
    {117, {6, 3, MOD_NO}},      /* u */
    {118, {3, 7, MOD_NO}},      /* v */
    {119, {1, 3, MOD_NO}},      /* w */
    {120, {7, 8, MOD_NO}},      /* x */
    {121, {7, 7, MOD_NO}},      /* y */
    {122, {2, 3, MOD_NO}},      /* z */
    {127, {9, 0, MOD_NO}},      /* Backspace */
    {167, {2, 1, MOD_SHIFT}},   /* § */
    {181, {3, 1, MOD_CODE}},    /* µ */
    {192, {3, 4, MOD_AGRAVE | MOD_SHIFT}},      /* À */
    {193, {3, 4, MOD_ACUTE | MOD_SHIFT}},       /* Á */
    {194, {3, 4, MOD_ACIRC | MOD_SHIFT}},       /* Â */
    {196, {8, 5, MOD_SHIFT}},   /* Ä */
    {200, {0, 3, MOD_AGRAVE | MOD_SHIFT}},      /* È */
    {201, {0, 3, MOD_ACUTE | MOD_SHIFT}},       /* É */
    {202, {0, 3, MOD_ACIRC | MOD_SHIFT}},       /* Ê */
    {204, {6, 2, MOD_AGRAVE | MOD_SHIFT}},      /* Ì */
    {205, {6, 2, MOD_ACUTE | MOD_SHIFT}},       /* Í */
    {206, {6, 2, MOD_ACIRC | MOD_SHIFT}},       /* Î */
    {210, {7, 2, MOD_AGRAVE | MOD_SHIFT}},      /* Ò */
    {211, {7, 2, MOD_ACUTE | MOD_SHIFT}},       /* Ó */
    {212, {7, 2, MOD_ACIRC | MOD_SHIFT}},       /* Ô */
    {214, {6, 5, MOD_SHIFT}},   /* Ö */
    {217, {6, 3, MOD_AGRAVE | MOD_SHIFT}},      /* Ù */
    {218, {6, 3, MOD_ACUTE | MOD_SHIFT}},       /* Ú */
    {219, {6, 3, MOD_ACIRC | MOD_SHIFT}},       /* Û */
    {220, {8, 3, MOD_SHIFT}},   /* Ü */
    {223, {8, 1, MOD_NO}},      /* ß */
    {224, {3, 4, MOD_AGRAVE}},  /* à */
    {225, {3, 4, MOD_ACUTE}},   /* á */
    {226, {3, 4, MOD_ACIRC}},   /* â */
    {228, {8, 5, MOD_NO}},      /* ä */
    {232, {0, 3, MOD_AGRAVE}},  /* è */
    {233, {0, 3, MOD_ACUTE}},   /* é */
    {234, {0, 3, MOD_ACIRC}},   /* ê */
    {234, {0, 3, MOD_ACIRC}},   /* ê */
    {236, {6, 2, MOD_AGRAVE}},  /* ì */
    {237, {6, 2, MOD_ACUTE}},   /* í */
    {238, {6, 2, MOD_ACIRC}},   /* î */
    {242, {7, 2, MOD_AGRAVE}},  /* ò */
    {243, {7, 2, MOD_ACUTE}},   /* ó */
    {244, {7, 2, MOD_ACIRC}},   /* ô */
    {246, {6, 5, MOD_NO}},      /* ö */
    {249, {6, 3, MOD_AGRAVE}},  /* ù */
    {250, {6, 3, MOD_ACUTE}},   /* ú */
    {251, {6, 3, MOD_ACIRC}},   /* û */
    {252, {8, 3, MOD_NO}},      /* ü */
    {0, {0, 0, MOD_NO}}         /* Sentinel */
};

/* Control combinations */
const Combi SHIFT = { 8, 7, MOD_NO };
const Combi CODE = { 7, 9, MOD_NO };
const Combi ACUTE = { 8, 0, MOD_NO };
const Combi AGRAVE = { 8, 0, MOD_SHIFT };
const Combi SPACE = { 3, 9, MOD_NO };
const Combi BACKSPACE = { 9, 0, MOD_NO };
const Combi KBD1 = {7, 1, MOD_CODE | MOD_DELAY};
const Combi KBD2 = {9, 0, MOD_CODE | MOD_DELAY};

const char shiftWritePin = get_pin_row(SHIFT.row);

void activate(char row, char col, bool shift_same_col);
void key(Combi combi);
void write_character(unsigned char c);
void setup();
void loop();
