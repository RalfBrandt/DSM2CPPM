;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: RX8_1.inc
;;   Version: 3.50, Updated on 2014/7/14 at 8:15:1
;;  Generated by PSoC Designer 5.4.2946
;;
;;  DESCRIPTION: Assembler declarations for the RX8 user module interface.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2014. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"

;--------------------------------------------------
; Constants for RX8_1 API's
;--------------------------------------------------

;mask value for global int reg bit for RX instance
RX8_1_bINT_MASK:        equ 04h
;RX8 interrupt address
RX8_1_INT_REG:          equ 0e1h

RX8_1_RXBUF_ENABLE:                         equ   0

RX8_1_RX_IGNORE_BELOW:                       equ  0h
RX8_1_RX_BUFFER_SIZE:                        equ  8h
RX8_1_CMD_TERM:                              equ  0h
RX8_1_DELIMITER:                             equ  0h

; This equate will be removed in future revisions.
; Do not use.
bRX8_1_INT_MASK:        equ 04h
;------------------------------------
;  RX8 Parity masks
;------------------------------------
RX8_1_PARITY_NONE:           equ   0h
RX8_1_PARITY_EVEN:           equ   2h
RX8_1_PARITY_ODD:            equ   6h

;------------------------------------
;  RX8 Status Register masks
;------------------------------------

RX8_1_RX_ACTIVE:             equ   10h
RX8_1_RX_COMPLETE:           equ   08h
RX8_1_RX_REG_FULL:           equ   08h
RX8_1_RX_PARITY_ERROR:       equ   80h
RX8_1_RX_OVERRUN_ERROR:      equ   40h
RX8_1_RX_FRAMING_ERROR:      equ   20h
RX8_1_RX_ERROR:              equ   E0h
RX8_1_RX_NO_ERROR:           equ   E0h   ; This symbol is deprecated and will removed in the future
RX8_1_RX_ENABLE:             equ   01h

RX8_1_RX_BUF_ERROR:                     equ   F0h  ; Mask for any Rx that may occur.
RX8_1_RX_BUF_OVERRUN:                   equ   10h  ; This indicates the software buffer has
                                                        ; been over run.
RX8_1_RX_BUF_CMDTERM:                   equ   01h  ; Command terminator has been received.

RX8_1_RX_NO_DATA:                       equ   01h
RX8_1_RX_NO_ERROR:                      equ   E0h

; Old equates, will be removed in future release
; Do not use
RX8_PARITY_NONE:           equ   0h
RX8_PARITY_EVEN:           equ   2h
RX8_PARITY_ODD:            equ   6h
RX8_RX_ACTIVE:             equ   10h
RX8_RX_COMPLETE:           equ   08h
RX8_RX_PARITY_ERROR:       equ   80h
RX8_RX_OVERRUN_ERROR:      equ   40h
RX8_RX_FRAMING_ERROR:      equ   20h
RX8_RX_NO_ERROR:           equ   E0h


;--------------------------------------------------
; Register Address Constants for RX8_1
;--------------------------------------------------
RX8_1_CONTROL_REG:  equ 2bh                      ;Control register
RX8_1_RX_SHIFT_REG: equ 28h                      ;RX Shift Register register
RX8_1_RX_BUFFER_REG:    equ 2ah                  ;RX Buffer Register
RX8_1_FUNC_REG: equ 28h                          ;Function register
RX8_1_INPUT_REG:    equ 29h                      ;Input register
RX8_1_OUTPUT_REG:   equ 2ah                      ;Output register

; end of file RX8_1.inc