    .area       _CODE

    .globl      _vdp_init
    .globl      _vdp_vsync

mos_sysvars = 0x08

_vdp_init:
    ld          a,#mos_sysvars
    rst         0x08         

    .db 0x5b    ; LIL prefix
    .db 0xed,0x22,0x05      ; lea   hl+5
    .db 0x5b    ; LIL prefix
    ld          (keycode_ptr),hl
    .db 0x04    ; Hack to fix the previous ADL address


    .db 0x5b    ; LIL prefix
    .db 0xed,0x22,0x17      ; lea   hl+17
    .db 0x5b ;; LIL prefix
    ld          (vk_code),hl
    .db 0x04    ; Hack to fix the previous ADL address

    .db 0x5b    ; LIL prefix
    .db 0xed,0x22,0x18      ; lea   hl+18
    .db 0x5b ;; LIL prefix
    ld          (key_up),hl
    .db 0x04    ; Hack to fix the previous ADL address

    .db 0x5b    ; LIL prefix
    .db 0x5b ;; LIL prefix
    ld          (frame_ptr),ix
    .db 0x04    ; Hack to fix the previous ADL address

    ret

_vdp_vsync:
    .db 0x5b    ; LIL prefix
    ld          hl,(frame_ptr)
    .db 0x04    ; Hack to fix the previous ADL address

    .db 0x5b    ; LIL prefix
    ld          a,(hl)
vdp_vsync_lp:
    .db 0x5b    ; LIL prefix
    cp          (hl)
    jr          z,vdp_vsync_lp

    ret

    .area       _BSS

_frame_ptr:
frame_ptr:      .db 0,0,0
_keycode_ptr:
keycode_ptr:    .db 0,0,0
_vk_code:
vk_code:        .db 0,0,0
_key_up:
key_up:         .db 0,0,0
