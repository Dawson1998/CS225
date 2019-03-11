#include "Image.h"
#include "StickerSheet.h"
#include <iostream>
int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image alma; alma.readFromFile("alma.png");
  Image i;    i.readFromFile("i.png");
  //std::cout<<"done!";
  StickerSheet sheet(alma, 5);
  sheet.addSticker(i, alma.width()-50, 50);
  sheet.addSticker(i, 50, 50);
  sheet.addSticker(i, alma.width()/2, 100);
  Image expected = sheet.render();
  expected.writeToFile("myImage.png");
  //sheet.changeMaxStickers(6);
  //sheet.changeMaxStickers(1,2,3);
  //sheet.removeSticker(6);
  //sheet.getSticker(1);
  //sheet.changeMaxStickers(100);
  //sheet.destroy();
  //std::cout<<"all indis passed";
  ///expected.readFromFile("tests/expected.png");
  return 0;
}
