/*
 * Copyright (c) 2018 naehrwert
 * Copyright (c) 2018 st4rk
 * Copyright (c) 2018-2019 CTCaer
 * Copyright (c) 2018 balika011
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>

#include "pkg1.h"
#include "../sec/se.h"

static const pkg1_id_t _pkg1_ids[] = {
	{ "20161121183008", 0, 0x1900, 0x3FE0, 0x4002B020 }, //1.0.0
	{ "20170210155124", 0, 0x1900, 0x3FE0, 0x4002D000 }, //2.0.0 - 2.3.0
	{ "20170519101410", 1, 0x1A00, 0x3FE0, 0x4002D000 }, //3.0.0
	{ "20170710161758", 2, 0x1A00, 0x3FE0, 0x4002D000 }, //3.0.1 - 3.0.2
	{ "20170921172629", 3, 0x1800, 0x3FE0, 0x4002B000 }, //4.0.0 - 4.1.0
	{ "20180220163747", 4, 0x1900, 0x3FE0, 0x4002B000 }, //5.0.0 - 5.1.0
	{ "20180802162753", 5, 0x1900, 0x3FE0, 0x4002B000 }, //6.0.0 - 6.1.0
	{ "20181107105733", 6, 0x0E00, 0x6FE0, 0x4002B000 }, //6.2.0
	{ "20181218175730", 7, 0x0F00, 0x6FE0, 0x40030000 }, //7.0.0
	{ "20190208150037", 7, 0x0F00, 0x6FE0, 0x40030000 }, //7.0.1
	{ "20190314172056", 7, 0x0E00, 0x6FE0, 0x40030000 }, //8.0.0
	{ NULL } //End.
};

const pkg1_id_t *pkg1_identify(u8 *pkg1)
{
	for (u32 i = 0; _pkg1_ids[i].id; i++)
		if (!memcmp(pkg1 + 0x10, _pkg1_ids[i].id, 12))
			return &_pkg1_ids[i];
	return NULL;
}
