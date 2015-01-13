#include<iostream>
#include<fstream>
using namespace std;
#include "Image.h"


int Image::getWidth(){
  return width;
}
int Image::getHeight(){
  return height;
}

void Image::print(){
  cout << "P6"<<endl;
  cout <<width<<" "<<height<<endl;
  cout <<255<<endl;

  for(int y = 0; y <height;  y++){
    for(int x = 0; x < width; x++){
      cout <<data[y][x].red << data[y][x].green 
	   <<data[y][x].blue;
    }
  }
}

void Image::zeroRed(){
  for(int y = 0; y <height;  y++){ //remove the red
    for(int x = 0; x < width; x++){
      data[y][x].red = (unsigned char)0;
    }
  }
}

void Image::zeroBlue(){
  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      data[y][x].blue = (unsigned char)0;
    }
  }
}

void Image::greyScale(){
  for(int y = 0; y <height;  y++){ //double the green
    for(int x = 0; x < width; x++){
      int a = ((int)data[y][x].red+(int)data[y][x].green+(int)data[y][x].blue)/3; //average
      data[y][x].red = (unsigned char)(a);
      data[y][x].green = (unsigned char)(a);
      data[y][x].blue = (unsigned char)(a);
    }
  }
}

void Image::horizSqueeze(){
  Pixel **data2;
  data2 = new Pixel*[height]; //allocate memory
  for(int i = 0; i < height; i++){
    data2[i] = new Pixel[width/2];
  }
  
  for(int y = 0; y <height;  y++){ //transfer data (every other horiz pixel)
    for(int x = 0; x < width; x++){
      if(x%2 ==0){
	data2[y][x/2].red = data[y][x].red;
	data2[y][x/2].green = data[y][x].green;
	data2[y][x/2].blue = data[y][x].blue;
      }
    }
  }

  width = width/2;

  delete [] data;//deallocate old memory
  data = data2; //reassign the primary data to the new data

}


void Image::addBorder(){
  Pixel **data2;
  int datax;
  int border = 50;
  int newWidth = width+100;
  int newHeight = height+100;
  unsigned char zip = (unsigned char)0;
  
  data2 = new Pixel*[height+100]; //allocate memory
  for(int i = 0; i < height; i++){
    data2[i] = new Pixel[width+100]; //accounting for odd/off by 1 error?
  }

  for(int y = 0; y < border; y++){ //top border
    for(int x = 0; x < newWidth; x++){
      data2[y][x].red = zip;
      data2[y][x].green = zip;
      data2[y][x].blue = zip;
    }
  }

  for(int y = border; y < border+height; y++){
    datax = 0;
    for(int x = 0; x < newWidth; x++){
      if(x >= border && x < width+border){
	data2[y][x].red = data[y-border][datax].red; //y-border for correct y?
	data2[y][x].green = data[y-border][datax].green;
	data2[y][x].blue = data[y-border][datax].blue;
	datax++;
      }else{
	data2[y][x].red = zip;
	data2[y][x].green = zip;
	data2[y][x].blue = zip;
      }
    }
  }

  for(int y = border+height; y < newHeight; y++){
    for(int x = 0; x< newWidth; x++){
      data2[y][x].red = zip;
      data2[y][x].green = zip;
      data2[y][x].blue = zip;
    }
  }

  width = newWidth;
  height = newHeight;
  delete [] data;//deallocate old memory
  data = data2; //reassign the primary data to the new data

}

