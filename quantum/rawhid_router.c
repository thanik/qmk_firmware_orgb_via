#if defined VIA_OPENRGB_HYBRID && defined VIA_OPENRGB_HYBRID_APPEND_COMMAND

#ifndef RAW_ENABLE
#    error "RAW_ENABLE is not enabled"
#endif

#include "quantum.h"
#include "raw_hid.h"
#include "openrgb.h"
#include "via.h"

extern void orgb_raw_hid_receive(uint8_t *data, uint8_t length);
extern void via_raw_hid_receive(uint8_t *data, uint8_t length);

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (*data > id_dynamic_keymap_set_encoder)
    {
        orgb_raw_hid_receive(data, length);
    }
    else
    {
        via_raw_hid_receive(data, length);
    }
}

#endif // VIA_OPENRGB_HYBRID
