static inline char get_pin_input(char input)
{
    return 33 - input;
}

static inline char get_pin_output(char output)
{
    return 23 - output;
}

/* Mapping definition */
const byte MOD_NO = 0;
const byte MOD_SHIFT = 1;
const byte MOD_CODE = 2;
const byte MOD_ACUTE = 4;
const byte MOD_AGRAVE = 8;
const byte MOD_ACIRC = 16;
const byte MOD_DELAY = 32;
const byte MOD_KBD2 = 64;
const byte MOD_CEDILLE = 128;

typedef struct {
    char input;
    char output;
    byte mod;
} Combi;

const Combi mapping[256] = {
    {-1, -1, MOD_NO},    // char 0 unmapped
    { 7, 8, MOD_NO },    // char 1 SHIFT
    { 9, 7, MOD_NO },    // char 2 CODE
    { 0, 8, MOD_NO },    // char 3 ACUTE
    { 0, 8, MOD_SHIFT },  // char 4 AGRAVE
    {-1, -1, MOD_NO},    // char 5 unmapped
    { 4, 6, MOD_CODE | MOD_DELAY },    // char 6
    { 7, 1, MOD_CODE | MOD_DELAY },    // char 7
    {-1, -1, MOD_NO},    // char 8 unmapped
    {-1, -1, MOD_NO},    // char 9 unmapped
    { 4, 8, MOD_NO | MOD_DELAY },    // char 10
    {-1, -1, MOD_NO},    // char 11 unmapped
    { 4, 8, MOD_CODE | MOD_DELAY },    // char 12
    { 4, 8, MOD_NO | MOD_DELAY },    // char 13
    {-1, -1, MOD_NO},    // char 14 unmapped
    {-1, -1, MOD_NO},    // char 15 unmapped
    {-1, -1, MOD_NO},    // char 16 unmapped
    {-1, -1, MOD_NO},    // char 17 unmapped
    { 4, 2, MOD_CODE | MOD_DELAY },    // char 18
    {-1, -1, MOD_NO},    // char 19 unmapped
    {-1, -1, MOD_NO},    // char 20 unmapped
    { 3, 6, MOD_CODE | MOD_DELAY },    // char 21
    {-1, -1, MOD_NO},    // char 22 unmapped
    { 1, 7, MOD_CODE | MOD_DELAY },    // char 23
    { 0, 9, MOD_CODE | MOD_DELAY },    // char 24
    {-1, -1, MOD_NO},    // char 25 unmapped
    {-1, -1, MOD_NO},    // char 26 unmapped
    {-1, -1, MOD_NO},    // char 27 unmapped
    {-1, -1, MOD_NO},    // char 28 unmapped
    {-1, -1, MOD_NO},    // char 29 unmapped
    {-1, -1, MOD_NO},    // char 30 unmapped
    {-1, -1, MOD_NO},    // char 31 unmapped
    { 9, 3, MOD_NO },    // char 32 :
    { 0, 0, MOD_SHIFT },    // char 33 : !
    { 1, 0, MOD_SHIFT },    // char 34 : "
    { 7, 0, MOD_NO },    // char 35 : #
    { 0, 2, MOD_SHIFT },    // char 36 : $
    { 0, 3, MOD_SHIFT },    // char 37 : %
    { 1, 3, MOD_SHIFT },    // char 38 : &
    { 7, 0, MOD_SHIFT },    // char 39 : '
    { 0, 6, MOD_SHIFT },    // char 40 : (
    { 0, 7, MOD_SHIFT },    // char 41 : )
    { 2, 8, MOD_SHIFT },    // char 42 : *
    { 2, 8, MOD_NO },    // char 43 : +
    { 7, 2, MOD_NO },    // char 44 : ,
    { 8, 6, MOD_NO },    // char 45 : -
    { 7, 6, MOD_NO },    // char 46 : .
    { 1, 6, MOD_SHIFT },    // char 47 : /
    { 1, 7, MOD_NO },    // char 48 : 0
    { 0, 0, MOD_NO },    // char 49 : 1
    { 1, 0, MOD_NO },    // char 50 : 2
    { 1, 2, MOD_NO },    // char 51 : 3
    { 0, 2, MOD_NO },    // char 52 : 4
    { 0, 3, MOD_NO },    // char 53 : 5
    { 1, 3, MOD_NO },    // char 54 : 6
    { 1, 6, MOD_NO },    // char 55 : 7
    { 0, 6, MOD_NO },    // char 56 : 8
    { 0, 7, MOD_NO },    // char 57 : 9
    { 7, 6, MOD_SHIFT },    // char 58 : :
    { 7, 2, MOD_SHIFT },    // char 59 : ;
    {-1, -1, MOD_NO},    // char 60 unmapped
    { 1, 7, MOD_SHIFT },    // char 61 : =
    {-1, -1, MOD_NO},    // char 62 unmapped
    { 1, 8, MOD_SHIFT },    // char 63 : ?
    {-1, -1, MOD_NO},    // char 64 unmapped
    { 4, 3, MOD_SHIFT },    // char 65 : A
    { 7, 1, MOD_SHIFT },    // char 66 : B
    { 8, 3, MOD_SHIFT },    // char 67 : C
    { 5, 1, MOD_SHIFT },    // char 68 : D
    { 3, 0, MOD_SHIFT },    // char 69 : E
    { 4, 1, MOD_SHIFT },    // char 70 : F
    { 4, 0, MOD_SHIFT },    // char 71 : G
    { 5, 0, MOD_SHIFT },    // char 72 : H
    { 2, 6, MOD_SHIFT },    // char 73 : I
    { 5, 2, MOD_SHIFT },    // char 74 : J
    { 4, 2, MOD_SHIFT },    // char 75 : K
    { 4, 6, MOD_SHIFT },    // char 76 : L
    { 8, 2, MOD_SHIFT },    // char 77 : M
    { 8, 1, MOD_SHIFT },    // char 78 : N
    { 2, 7, MOD_SHIFT },    // char 79 : O
    { 3, 7, MOD_SHIFT },    // char 80 : P
    { 2, 1, MOD_SHIFT },    // char 81 : Q
    { 2, 0, MOD_SHIFT },    // char 82 : R
    { 5, 3, MOD_SHIFT },    // char 83 : S
    { 2, 3, MOD_NO },    // char 84 : T
    { 3, 6, MOD_SHIFT },    // char 85 : U
    { 7, 3, MOD_SHIFT },    // char 86 : V
    { 3, 1, MOD_SHIFT },    // char 87 : W
    { 8, 7, MOD_SHIFT },    // char 88 : X
    { 7, 7, MOD_SHIFT },    // char 89 : Y
    { 3, 2, MOD_SHIFT },    // char 90 : Z
    {-1, -1, MOD_NO},    // char 91 unmapped
    {-1, -1, MOD_NO},    // char 92 unmapped
    {-1, -1, MOD_NO},    // char 93 unmapped
    {-1, -1, MOD_NO},    // char 94 unmapped
    { 8, 6, MOD_SHIFT },    // char 95 : _
    {-1, -1, MOD_NO},    // char 96 unmapped
    { 4, 3, MOD_NO },    // char 97 : a
    { 7, 1, MOD_NO },    // char 98 : b
    { 8, 3, MOD_NO },    // char 99 : c
    { 5, 1, MOD_NO },    // char 100 : d
    { 3, 0, MOD_NO },    // char 101 : e
    { 4, 1, MOD_NO },    // char 102 : f
    { 4, 0, MOD_NO },    // char 103 : g
    { 5, 0, MOD_NO },    // char 104 : h
    { 2, 6, MOD_NO },    // char 105 : i
    { 5, 2, MOD_NO },    // char 106 : j
    { 4, 2, MOD_NO },    // char 107 : k
    { 4, 6, MOD_NO },    // char 108 : l
    { 8, 2, MOD_NO },    // char 109 : m
    { 8, 1, MOD_NO },    // char 110 : n
    { 2, 7, MOD_NO },    // char 111 : o
    { 3, 7, MOD_NO },    // char 112 : p
    { 2, 1, MOD_NO },    // char 113 : q
    { 2, 0, MOD_NO },    // char 114 : r
    { 5, 3, MOD_NO },    // char 115 : s
    { 2, 2, MOD_NO },    // char 116 : t
    { 3, 6, MOD_NO },    // char 117 : u
    { 7, 3, MOD_NO },    // char 118 : v
    { 3, 1, MOD_NO },    // char 119 : w
    { 8, 7, MOD_NO },    // char 120 : x
    { 7, 7, MOD_NO },    // char 121 : y
    { 3, 2, MOD_NO },    // char 122 : z
    {-1, -1, MOD_NO},    // char 123 unmapped
    {-1, -1, MOD_NO},    // char 124 unmapped
    {-1, -1, MOD_NO},    // char 125 unmapped
    {-1, -1, MOD_NO},    // char 126 unmapped
    { 0, 9, MOD_NO },    // char 127 : backspace
    {-1, -1, MOD_NO},    // char 128 unmapped
    {-1, -1, MOD_NO},    // char 129 unmapped
    {-1, -1, MOD_NO},    // char 130 unmapped
    {-1, -1, MOD_NO},    // char 131 unmapped
    {-1, -1, MOD_NO},    // char 132 unmapped
    {-1, -1, MOD_NO},    // char 133 unmapped
    {-1, -1, MOD_NO},    // char 134 unmapped
    {-1, -1, MOD_NO},    // char 135 unmapped
    {-1, -1, MOD_NO},    // char 136 unmapped
    {-1, -1, MOD_NO},    // char 137 unmapped
    {-1, -1, MOD_NO},    // char 138 unmapped
    {-1, -1, MOD_NO},    // char 139 unmapped
    {-1, -1, MOD_NO},    // char 140 unmapped
    {-1, -1, MOD_NO},    // char 141 unmapped
    {-1, -1, MOD_NO},    // char 142 unmapped
    {-1, -1, MOD_NO},    // char 143 unmapped
    {-1, -1, MOD_NO},    // char 144 unmapped
    {-1, -1, MOD_NO},    // char 145 unmapped
    {-1, -1, MOD_NO},    // char 146 unmapped
    {-1, -1, MOD_NO},    // char 147 unmapped
    {-1, -1, MOD_NO},    // char 148 unmapped
    {-1, -1, MOD_NO},    // char 149 unmapped
    {-1, -1, MOD_NO},    // char 150 unmapped
    {-1, -1, MOD_NO},    // char 151 unmapped
    {-1, -1, MOD_NO},    // char 152 unmapped
    {-1, -1, MOD_NO},    // char 153 unmapped
    {-1, -1, MOD_NO},    // char 154 unmapped
    {-1, -1, MOD_NO},    // char 155 unmapped
    {-1, -1, MOD_NO},    // char 156 unmapped
    {-1, -1, MOD_NO},    // char 157 unmapped
    {-1, -1, MOD_NO},    // char 158 unmapped
    {-1, -1, MOD_NO},    // char 159 unmapped
    {-1, -1, MOD_NO},    // char 160 unmapped
    {-1, -1, MOD_NO},    // char 161 unmapped
    {-1, -1, MOD_NO},    // char 162 unmapped
    {-1, -1, MOD_NO},    // char 163 unmapped
    {-1, -1, MOD_NO},    // char 164 unmapped
    {-1, -1, MOD_NO},    // char 165 unmapped
    {-1, -1, MOD_NO},    // char 166 unmapped
    { 1, 2, MOD_SHIFT },    // char 167 : §
    {-1, -1, MOD_NO},    // char 168 unmapped
    {-1, -1, MOD_NO},    // char 169 unmapped
    {-1, -1, MOD_NO},    // char 170 unmapped
    {-1, -1, MOD_NO},    // char 171 unmapped
    {-1, -1, MOD_NO},    // char 172 unmapped
    {-1, -1, MOD_NO},    // char 173 unmapped
    {-1, -1, MOD_NO},    // char 174 unmapped
    {-1, -1, MOD_NO},    // char 175 unmapped
    {-1, -1, MOD_NO},    // char 176 unmapped
    {-1, -1, MOD_NO},    // char 177 unmapped
    {-1, -1, MOD_NO},    // char 178 unmapped
    {-1, -1, MOD_NO},    // char 179 unmapped
    {-1, -1, MOD_NO},    // char 180 unmapped
    { 1, 3, MOD_CODE },    // char 181 : µ
    {-1, -1, MOD_NO},    // char 182 unmapped
    {-1, -1, MOD_NO},    // char 183 unmapped
    {-1, -1, MOD_NO},    // char 184 unmapped
    {-1, -1, MOD_NO},    // char 185 unmapped
    {-1, -1, MOD_NO},    // char 186 unmapped
    {-1, -1, MOD_NO},    // char 187 unmapped
    {-1, -1, MOD_NO},    // char 188 unmapped
    {-1, -1, MOD_NO},    // char 189 unmapped
    {-1, -1, MOD_NO},    // char 190 unmapped
    {-1, -1, MOD_NO},    // char 191 unmapped
    { 4, 3, MOD_AGRAVE | MOD_SHIFT },    // char 192 : À
    { 4, 3, MOD_ACUTE | MOD_SHIFT },    // char 193 : Á
    { 4, 3, MOD_ACIRC | MOD_SHIFT },    // char 194 : Â
    {-1, -1, MOD_NO},    // char 195 unmapped
    { 5, 8, MOD_SHIFT },    // char 196 : Ä
    {-1, -1, MOD_NO},    // char 197 unmapped
    {-1, -1, MOD_NO},    // char 198 unmapped
    { 8, 3, MOD_SHIFT | MOD_CEDILLE },    // char 199 : Ç
    { 3, 0, MOD_AGRAVE | MOD_SHIFT },    // char 200 : È
    { 3, 0, MOD_ACUTE | MOD_SHIFT },    // char 201 : É
    { 3, 0, MOD_ACIRC | MOD_SHIFT },    // char 202 : Ê
    {-1, -1, MOD_NO},    // char 203 unmapped
    { 2, 6, MOD_AGRAVE | MOD_SHIFT },    // char 204 : Ì
    { 2, 6, MOD_ACUTE | MOD_SHIFT },    // char 205 : Í
    { 2, 6, MOD_ACIRC | MOD_SHIFT },    // char 206 : Î
    {-1, -1, MOD_NO},    // char 207 unmapped
    {-1, -1, MOD_NO},    // char 208 unmapped
    {-1, -1, MOD_NO},    // char 209 unmapped
    { 2, 7, MOD_AGRAVE | MOD_SHIFT },    // char 210 : Ò
    { 2, 7, MOD_ACUTE | MOD_SHIFT },    // char 211 : Ó
    { 2, 7, MOD_ACIRC | MOD_SHIFT },    // char 212 : Ô
    {-1, -1, MOD_NO},    // char 213 unmapped
    { 5, 6, MOD_SHIFT },    // char 214 : Ö
    {-1, -1, MOD_NO},    // char 215 unmapped
    {-1, -1, MOD_NO},    // char 216 unmapped
    { 3, 6, MOD_AGRAVE | MOD_SHIFT },    // char 217 : Ù
    { 3, 6, MOD_ACUTE | MOD_SHIFT },    // char 218 : Ú
    { 3, 6, MOD_ACIRC | MOD_SHIFT },    // char 219 : Û
    { 3, 8, MOD_SHIFT },    // char 220 : Ü
    {-1, -1, MOD_NO},    // char 221 unmapped
    {-1, -1, MOD_NO},    // char 222 unmapped
    { 1, 8, MOD_NO },    // char 223 : ß
    { 4, 3, MOD_AGRAVE },    // char 224 : à
    { 4, 3, MOD_ACUTE },    // char 225 : á
    { 4, 3, MOD_ACIRC },    // char 226 : â
    {-1, -1, MOD_NO},    // char 227 unmapped
    { 5, 8, MOD_NO },    // char 228 : ä
    {-1, -1, MOD_NO},    // char 229 unmapped
    {-1, -1, MOD_NO},    // char 230 unmapped
    { 8, 3, MOD_CEDILLE },    // char 231 : ç
    { 3, 0, MOD_AGRAVE },    // char 232 : è
    { 3, 0, MOD_ACUTE },    // char 233 : é
    { 3, 0, MOD_ACIRC },    // char 234 : ê
    {-1, -1, MOD_NO},    // char 235 unmapped
    { 2, 6, MOD_AGRAVE },    // char 236 : ì
    { 2, 6, MOD_ACUTE },    // char 237 : í
    { 2, 6, MOD_ACIRC },    // char 238 : î
    {-1, -1, MOD_NO},    // char 239 unmapped
    {-1, -1, MOD_NO},    // char 240 unmapped
    {-1, -1, MOD_NO},    // char 241 unmapped
    { 2, 7, MOD_AGRAVE },    // char 242 : ò
    { 2, 7, MOD_ACUTE },    // char 243 : ó
    { 2, 7, MOD_ACIRC },    // char 244 : ô
    {-1, -1, MOD_NO},    // char 245 unmapped
    { 5, 6, MOD_NO },    // char 246 : ö
    {-1, -1, MOD_NO},    // char 247 unmapped
    {-1, -1, MOD_NO},    // char 248 unmapped
    { 3, 6, MOD_AGRAVE },    // char 249 : ù
    { 3, 6, MOD_ACUTE },    // char 250 : ú
    { 3, 6, MOD_ACIRC },    // char 251 : û
    { 3, 8, MOD_NO },    // char 252 : ü
    {-1, -1, MOD_NO},    // char 253 unmapped
    {-1, -1, MOD_NO},    // char 254 unmapped
    {-1, -1, MOD_NO},    // char 255 unmapped
};

/* Control combinations */
const Combi SHIFT = mapping[1];
const Combi CODE = mapping[2];
const Combi ACUTE = mapping[3];
const Combi AGRAVE = mapping[4];
const Combi BACKSPACE = mapping[127];
const Combi CEDILLE = mapping[44];
const Combi SPACE = mapping[32];
const Combi KBD1 = mapping[23];
const Combi KBD2 = mapping[24];
const char shiftWritePin = get_pin_output(SHIFT.output);

void activate(char output, char input, bool shift_same_input);
void key(Combi combi);
void write_character(unsigned char c);
void setup();
void loop();
