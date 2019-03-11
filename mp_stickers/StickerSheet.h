/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include <iostream>
#include "Image.h"
class StickerSheet
{
public:
  StickerSheet(const Image &picture,unsigned max);
  ~StickerSheet();
  StickerSheet(const StickerSheet &other);
  void copy(const StickerSheet & other);
  const StickerSheet& 	operator= (const StickerSheet &other);
  void 	changeMaxStickers (unsigned max);
  int 	addSticker (Image &sticker, unsigned x, unsigned y);
  bool 	translate (unsigned index, unsigned x, unsigned y);
  void 	removeSticker (unsigned index);
  Image * 	getSticker (unsigned index);
  Image 	render () const;
  Image ** stickers;
  void destroy();
  unsigned sticker_max;
  unsigned sticker_ct;
  unsigned * x;
  unsigned * y;
  Image * base;
  unsigned * layer;
};
