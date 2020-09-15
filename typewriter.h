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
    char output;
    char input;
    byte mod;
} Combi;

const Combi mapping[256] = {
    {-1, -1, MOD_NO},    // char 0 unmapped
    {-1, -1, MOD_NO},    // char 1 unmapped
    {-1, -1, MOD_NO},    // char 2 unmapped
    {-1, -1, MOD_NO},    // char 3 unmapped
    {-1, -1, MOD_NO},    // char 4 unmapped
    {-1, -1, MOD_NO},    // char 5 unmapped
    { 6, 4, MOD_CODE | MOD_DELAY },    // char 6
    { 1, 7, MOD_CODE | MOD_DELAY },    // char 7
    {-1, -1, MOD_NO},    // char 8 unmapped
    {-1, -1, MOD_NO},    // char 9 unmapped
    { 8, 4, MOD_NO | MOD_DELAY },    // char 10
    {-1, -1, MOD_NO},    // char 11 unmapped
    { 8, 4, MOD_CODE | MOD_DELAY },    // char 12
    { 8, 4, MOD_NO | MOD_DELAY },    // char 13
    {-1, -1, MOD_NO},    // char 14 unmapped
    {-1, -1, MOD_NO},    // char 15 unmapped
    {-1, -1, MOD_NO},    // char 16 unmapped
    {-1, -1, MOD_NO},    // char 17 unmapped
    { 2, 4, MOD_CODE | MOD_DELAY },    // char 18
    {-1, -1, MOD_NO},    // char 19 unmapped
    {-1, -1, MOD_NO},    // char 20 unmapped
    { 6, 3, MOD_CODE | MOD_DELAY },    // char 21
    {-1, -1, MOD_NO},    // char 22 unmapped
    { 7, 1, MOD_CODE | MOD_DELAY },    // char 23
    { 9, 0, MOD_CODE | MOD_DELAY },    // char 24
    {-1, -1, MOD_NO},    // char 25 unmapped
    {-1, -1, MOD_NO},    // char 26 unmapped
    {-1, -1, MOD_NO},    // char 27 unmapped
    {-1, -1, MOD_NO},    // char 28 unmapped
    {-1, -1, MOD_NO},    // char 29 unmapped
    {-1, -1, MOD_NO},    // char 30 unmapped
    {-1, -1, MOD_NO},    // char 31 unmapped
    { 3, 9, MOD_NO },    // char 32 :
    { 0, 0, MOD_SHIFT },    // char 33 : !
    { 0, 1, MOD_SHIFT },    // char 34 : "
    { 0, 7, MOD_NO },    // char 35 : #
    { 2, 0, MOD_SHIFT },    // char 36 : $
    { 3, 0, MOD_SHIFT },    // char 37 : %
    { 3, 1, MOD_SHIFT },    // char 38 : &
    { 0, 7, MOD_SHIFT },    // char 39 : '
    { 6, 0, MOD_SHIFT },    // char 40 : (
    { 7, 0, MOD_SHIFT },    // char 41 : )
    { 8, 2, MOD_SHIFT },    // char 42 : *
    { 8, 2, MOD_NO },    // char 43 : +
    { 2, 7, MOD_NO },    // char 44 : ,
    { 6, 8, MOD_NO },    // char 45 : -
    { 6, 7, MOD_NO },    // char 46 : .
    { 6, 1, MOD_SHIFT },    // char 47 : /
    { 7, 1, MOD_NO },    // char 48 : 0
    { 0, 0, MOD_NO },    // char 49 : 1
    { 0, 1, MOD_NO },    // char 50 : 2
    { 2, 1, MOD_NO },    // char 51 : 3
    { 2, 0, MOD_NO },    // char 52 : 4
    { 3, 0, MOD_NO },    // char 53 : 5
    { 3, 1, MOD_NO },    // char 54 : 6
    { 6, 1, MOD_NO },    // char 55 : 7
    { 6, 0, MOD_NO },    // char 56 : 8
    { 7, 0, MOD_NO },    // char 57 : 9
    { 6, 7, MOD_SHIFT },    // char 58 : :
    { 2, 7, MOD_SHIFT },    // char 59 : ;
    {-1, -1, MOD_NO},    // char 60 unmapped
    { 7, 1, MOD_SHIFT },    // char 61 : =
    {-1, -1, MOD_NO},    // char 62 unmapped
    { 8, 1, MOD_SHIFT },    // char 63 : ?
    {-1, -1, MOD_NO},    // char 64 unmapped
    { 3, 4, MOD_SHIFT },    // char 65 : A
    { 1, 7, MOD_SHIFT },    // char 66 : B
    { 3, 8, MOD_SHIFT },    // char 67 : C
    { 1, 5, MOD_SHIFT },    // char 68 : D
    { 0, 3, MOD_SHIFT },    // char 69 : E
    { 1, 4, MOD_SHIFT },    // char 70 : F
    { 0, 4, MOD_SHIFT },    // char 71 : G
    { 0, 5, MOD_SHIFT },    // char 72 : H
    { 6, 2, MOD_SHIFT },    // char 73 : I
    { 2, 5, MOD_SHIFT },    // char 74 : J
    { 2, 4, MOD_SHIFT },    // char 75 : K
    { 6, 4, MOD_SHIFT },    // char 76 : L
    { 2, 8, MOD_SHIFT },    // char 77 : M
    { 1, 8, MOD_SHIFT },    // char 78 : N
    { 7, 2, MOD_SHIFT },    // char 79 : O
    { 7, 3, MOD_SHIFT },    // char 80 : P
    { 1, 2, MOD_SHIFT },    // char 81 : Q
    { 0, 2, MOD_SHIFT },    // char 82 : R
    { 3, 5, MOD_SHIFT },    // char 83 : S
    { 3, 2, MOD_NO },    // char 84 : T
    { 6, 3, MOD_SHIFT },    // char 85 : U
    { 3, 7, MOD_SHIFT },    // char 86 : V
    { 1, 3, MOD_SHIFT },    // char 87 : W
    { 7, 8, MOD_SHIFT },    // char 88 : X
    { 7, 7, MOD_SHIFT },    // char 89 : Y
    { 2, 3, MOD_SHIFT },    // char 90 : Z
    {-1, -1, MOD_NO},    // char 91 unmapped
    {-1, -1, MOD_NO},    // char 92 unmapped
    {-1, -1, MOD_NO},    // char 93 unmapped
    {-1, -1, MOD_NO},    // char 94 unmapped
    { 6, 8, MOD_SHIFT },    // char 95 : _
    {-1, -1, MOD_NO},    // char 96 unmapped
    { 3, 4, MOD_NO },    // char 97 : a
    { 1, 7, MOD_NO },    // char 98 : b
    { 3, 8, MOD_NO },    // char 99 : c
    { 1, 5, MOD_NO },    // char 100 : d
    { 0, 3, MOD_NO },    // char 101 : e
    { 1, 4, MOD_NO },    // char 102 : f
    { 0, 4, MOD_NO },    // char 103 : g
    { 0, 5, MOD_NO },    // char 104 : h
    { 6, 2, MOD_NO },    // char 105 : i
    { 2, 5, MOD_NO },    // char 106 : j
    { 2, 4, MOD_NO },    // char 107 : k
    { 6, 4, MOD_NO },    // char 108 : l
    { 2, 8, MOD_NO },    // char 109 : m
    { 1, 8, MOD_NO },    // char 110 : n
    { 7, 2, MOD_NO },    // char 111 : o
    { 7, 3, MOD_NO },    // char 112 : p
    { 1, 2, MOD_NO },    // char 113 : q
    { 0, 2, MOD_NO },    // char 114 : r
    { 3, 5, MOD_NO },    // char 115 : s
    { 2, 2, MOD_NO },    // char 116 : t
    { 6, 3, MOD_NO },    // char 117 : u
    { 3, 7, MOD_NO },    // char 118 : v
    { 1, 3, MOD_NO },    // char 119 : w
    { 7, 8, MOD_NO },    // char 120 : x
    { 7, 7, MOD_NO },    // char 121 : y
    { 2, 3, MOD_NO },    // char 122 : z
    {-1, -1, MOD_NO},    // char 123 unmapped
    {-1, -1, MOD_NO},    // char 124 unmapped
    {-1, -1, MOD_NO},    // char 125 unmapped
    {-1, -1, MOD_NO},    // char 126 unmapped
    { 9, 0, MOD_NO },    // char 127 : 
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
    { 2, 1, MOD_SHIFT },    // char 167 : §
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
    { 3, 1, MOD_CODE },    // char 181 : µ
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
    { 3, 4, MOD_AGRAVE | MOD_SHIFT },    // char 192 : À
    { 3, 4, MOD_ACUTE | MOD_SHIFT },    // char 193 : Á
    { 3, 4, MOD_ACIRC | MOD_SHIFT },    // char 194 : Â
    {-1, -1, MOD_NO},    // char 195 unmapped
    { 8, 5, MOD_SHIFT },    // char 196 : Ä
    {-1, -1, MOD_NO},    // char 197 unmapped
    {-1, -1, MOD_NO},    // char 198 unmapped
    { 3, 8, MOD_SHIFT | MOD_CEDILLE },    // char 199 : Ç
    { 0, 3, MOD_AGRAVE | MOD_SHIFT },    // char 200 : È
    { 0, 3, MOD_ACUTE | MOD_SHIFT },    // char 201 : É
    { 0, 3, MOD_ACIRC | MOD_SHIFT },    // char 202 : Ê
    {-1, -1, MOD_NO},    // char 203 unmapped
    { 6, 2, MOD_AGRAVE | MOD_SHIFT },    // char 204 : Ì
    { 6, 2, MOD_ACUTE | MOD_SHIFT },    // char 205 : Í
    { 6, 2, MOD_ACIRC | MOD_SHIFT },    // char 206 : Î
    {-1, -1, MOD_NO},    // char 207 unmapped
    {-1, -1, MOD_NO},    // char 208 unmapped
    {-1, -1, MOD_NO},    // char 209 unmapped
    { 7, 2, MOD_AGRAVE | MOD_SHIFT },    // char 210 : Ò
    { 7, 2, MOD_ACUTE | MOD_SHIFT },    // char 211 : Ó
    { 7, 2, MOD_ACIRC | MOD_SHIFT },    // char 212 : Ô
    {-1, -1, MOD_NO},    // char 213 unmapped
    { 6, 5, MOD_SHIFT },    // char 214 : Ö
    {-1, -1, MOD_NO},    // char 215 unmapped
    {-1, -1, MOD_NO},    // char 216 unmapped
    { 6, 3, MOD_AGRAVE | MOD_SHIFT },    // char 217 : Ù
    { 6, 3, MOD_ACUTE | MOD_SHIFT },    // char 218 : Ú
    { 6, 3, MOD_ACIRC | MOD_SHIFT },    // char 219 : Û
    { 8, 3, MOD_SHIFT },    // char 220 : Ü
    {-1, -1, MOD_NO},    // char 221 unmapped
    {-1, -1, MOD_NO},    // char 222 unmapped
    { 8, 1, MOD_NO },    // char 223 : ß
    { 3, 4, MOD_AGRAVE },    // char 224 : à
    { 3, 4, MOD_ACUTE },    // char 225 : á
    { 3, 4, MOD_ACIRC },    // char 226 : â
    {-1, -1, MOD_NO},    // char 227 unmapped
    { 8, 5, MOD_NO },    // char 228 : ä
    {-1, -1, MOD_NO},    // char 229 unmapped
    {-1, -1, MOD_NO},    // char 230 unmapped
    { 3, 8, MOD_CEDILLE },    // char 231 : ç
    { 0, 3, MOD_AGRAVE },    // char 232 : è
    { 0, 3, MOD_ACUTE },    // char 233 : é
    { 0, 3, MOD_ACIRC },    // char 234 : ê
    {-1, -1, MOD_NO},    // char 235 unmapped
    { 6, 2, MOD_AGRAVE },    // char 236 : ì
    { 6, 2, MOD_ACUTE },    // char 237 : í
    { 6, 2, MOD_ACIRC },    // char 238 : î
    {-1, -1, MOD_NO},    // char 239 unmapped
    {-1, -1, MOD_NO},    // char 240 unmapped
    {-1, -1, MOD_NO},    // char 241 unmapped
    { 7, 2, MOD_AGRAVE },    // char 242 : ò
    { 7, 2, MOD_ACUTE },    // char 243 : ó
    { 7, 2, MOD_ACIRC },    // char 244 : ô
    {-1, -1, MOD_NO},    // char 245 unmapped
    { 6, 5, MOD_NO },    // char 246 : ö
    {-1, -1, MOD_NO},    // char 247 unmapped
    {-1, -1, MOD_NO},    // char 248 unmapped
    { 6, 3, MOD_AGRAVE },    // char 249 : ù
    { 6, 3, MOD_ACUTE },    // char 250 : ú
    { 6, 3, MOD_ACIRC },    // char 251 : û
    { 8, 3, MOD_NO },    // char 252 : ü
    {-1, -1, MOD_NO},    // char 253 unmapped
    {-1, -1, MOD_NO},    // char 254 unmapped
    {-1, -1, MOD_NO},    // char 255 unmapped
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
const Combi CEDILLE = {2, 7, MOD_NO};
const char shiftWritePin = get_pin_output(SHIFT.output);

void activate(char output, char input, bool shift_same_input);
void key(Combi combi);
void write_character(unsigned char c);
void setup();
void loop();
