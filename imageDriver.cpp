#include <iostream>
#include "Image.h"
#include <string>
using namespace std;

int main(int argc, char ** argv){

  Image img(argv[1]);

  img.zeroBlue();

  img.print();

  return 0;
}
