/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        bitmap_header.c
*/

#include "bitmap.h"

void	make_bmp_header (bmp_header_t * header, size_t size)
{
	memset(header, 0, sizeof(*header));
	#if __BYTE_ORDER__ == ORDER_LITTLE_ENDIAN
	header->magic = 0x424D;
	#else
	header->magic = 0x4D42;
	#endif
	header->size = size * size * sizeof(int) + sizeof(bmp_header_t) +
	sizeof(bmp_info_header_t);
	header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
}

void	 make_bmp_info_header (bmp_info_header_t * header, size_t size)
{
	memset(header, 0, sizeof(*header));
	header->raw_data_size = size * size;
	header->height = size;
	header->planes = 1;
	header->width = size;
	header->bpp = 32;
	header->size = 40;
}
