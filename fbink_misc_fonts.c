/*
	FBInk: FrameBuffer eInker, a tool to print text & images on eInk devices (Kobo/Kindle)
	Copyright (C) 2018 NiLuJe <ninuje@gmail.com>

	----

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as
	published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "fbink_misc_fonts.h"

static const unsigned char*
    kates_get_bitmap(uint32_t codepoint)
{
	if (codepoint <= 0x02) {
		return kates_block1[codepoint];
	} else if (codepoint >= 0x09 && codepoint <= 0x19) {
		return kates_block2[codepoint - 0x09];
	} else if (codepoint >= 0x1b && codepoint <= 0x1b) {
		return kates_block3[codepoint - 0x1b];
	} else if (codepoint >= 0x20 && codepoint <= 0x7e) {
		return kates_block4[codepoint - 0x20];
	} else if (codepoint >= 0xa1 && codepoint <= 0xac) {
		return kates_block5[codepoint - 0xa1];
	} else if (codepoint >= 0xae && codepoint <= 0xff) {
		return kates_block6[codepoint - 0xae];
	} else {
		fprintf(stderr, "[FBInk] Codepoint U+%04X is not covered by this font!\n", codepoint);
		return kates_block1[0];
	}
}

static const unsigned char*
    fkp_get_bitmap(uint32_t codepoint)
{
	if (codepoint <= 0xff) {
		return fkp_block1[codepoint];
	} else {
		fprintf(stderr, "[FBInk] Codepoint U+%04X is not covered by this font!\n", codepoint);
		return fkp_block1[0];
	}
}

static const unsigned char*
    ctrld_get_bitmap(uint32_t codepoint)
{
	if (codepoint >= 0x0a && codepoint <= 0xff) {
		return ctrld_block1[codepoint - 0x0a];
	} else if (codepoint >= 0x3bb && codepoint <= 0x3bb) {
		return ctrld_block2[codepoint - 0x3bb];
	} else if (codepoint >= 0x3c0 && codepoint <= 0x3c0) {
		return ctrld_block3[codepoint - 0x3c0];
	} else if (codepoint >= 0x21b5 && codepoint <= 0x21b5) {
		return ctrld_block4[codepoint - 0x21b5];
	} else if (codepoint >= 0x25aa && codepoint <= 0x25aa) {
		return ctrld_block5[codepoint - 0x25aa];
	} else if (codepoint >= 0x25b4 && codepoint <= 0x25b4) {
		return ctrld_block6[codepoint - 0x25b4];
	} else if (codepoint >= 0x25b8 && codepoint <= 0x25b8) {
		return ctrld_block7[codepoint - 0x25b8];
	} else if (codepoint >= 0x25be && codepoint <= 0x25be) {
		return ctrld_block8[codepoint - 0x25be];
	} else if (codepoint >= 0x25c2 && codepoint <= 0x25c2) {
		return ctrld_block9[codepoint - 0x25c2];
	} else if (codepoint >= 0x25c6 && codepoint <= 0x25c6) {
		return ctrld_block10[codepoint - 0x25c6];
	} else if (codepoint >= 0x2713 && codepoint <= 0x2713) {
		return ctrld_block11[codepoint - 0x2713];
	} else if (codepoint >= 0x2717 && codepoint <= 0x2717) {
		return ctrld_block12[codepoint - 0x2717];
	} else if (codepoint >= 0xe0a0 && codepoint <= 0xe0a2) {
		return ctrld_block13[codepoint - 0xe0a0];
	} else if (codepoint >= 0xe0b0 && codepoint <= 0xe0b3) {
		return ctrld_block14[codepoint - 0xe0b0];
	} else if (codepoint >= 0xee00 && codepoint <= 0xee03) {
		return ctrld_block15[codepoint - 0xee00];
	} else if (codepoint >= 0xee10 && codepoint <= 0xee13) {
		return ctrld_block16[codepoint - 0xee10];
	} else if (codepoint >= 0xee20 && codepoint <= 0xee23) {
		return ctrld_block17[codepoint - 0xee20];
	} else if (codepoint >= 0xee30 && codepoint <= 0xee37) {
		return ctrld_block18[codepoint - 0xee30];
	} else if (codepoint >= 0xee40 && codepoint <= 0xee43) {
		return ctrld_block19[codepoint - 0xee40];
	} else if (codepoint >= 0xeef0 && codepoint <= 0xeef9) {
		return ctrld_block20[codepoint - 0xeef0];
	} else {
		fprintf(stderr, "[FBInk] Codepoint U+%04X is not covered by this font!\n", codepoint);
		return ctrld_block1[0];
	}
}
