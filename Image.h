#ifndef _IMAGE_
#define _IMAGE_
#include <iostream>
#include <fstream>
using namespace std;

struct Pixel{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

class Image{
private:
  int width;
  int height;
  Pixel **data;
  
public:
  Image(int w, int h){
    width = w;
    height = h;
    data = new Pixel*[height];
    for(int i = 0; i < height; i++){
      data[i] = new Pixel[width];
    }
  }

  Image(char* filename){
    string s;
    int range;
    ifstream f(filename);

    f >> s;
    f >> width;
    f >> height;
    f >> range;
    f.get(); //SKIP THE SPACE, UGH
    data = new Pixel*[height]; //allocate memory
    for(int i = 0; i < height; i++){
      data[i] = new Pixel[width];
    }
    for(int i = 0; i < height; ++i){
      f.read( (char *) data[i], width*sizeof(Pixel) );//read in the data
    }
    
  }

  ~Image(){
    for(int i = 0; i < height; i++){
      delete [] data[i];
    }
    delete [] data;
  }

  int getWidth();
  int getHeight();
  void print();
  void zeroRed();
  void greyScale();
  void horizSqueeze();
  void addBorder();
  void zeroBlue();


};


#endif  // _IMAGE_
