
#include "char.h"

int8_t char_conts(uint8_t c) {
    static const uint8_t cmps[] = { 0x80, 0xe0, 0xf0, 0xf8 };
    static const uint8_t eqs[] = { 0, 0xc0, 0xe0, 0xf0 };
    for (uint8_t i = 0; i < 4; i++) if ((c & cmps[i]) == eqs[i]) return i;
    return -1;
}

var* char_from_bytes(uint8_t* bytes, size_t len) {
    if (len < 1 || len > 4) return VAR_ERROR(INVALID_BYTES_FOR_CHAR);
    int8_t conts = char_conts(bytes[0]);
    if (conts == -1) return VAR_ERROR(INVALID_BYTES_FOR_CHAR);
    var_char c;
    memcpy(c.data, bytes, conts + 1);
    return VAR_CHAR(c);
}
