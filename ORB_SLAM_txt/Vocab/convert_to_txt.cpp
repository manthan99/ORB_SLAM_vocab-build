/**
 * File: Demo.cpp
 * Date: November 2011
 * Author: Dorian Galvez-Lopez
 * Description: demo application of DBoW2
 * License: see the LICENSE.txt file
 */

#include <iostream>
#include <vector>

#include "ORBVocabulary.h"

using namespace ORB_SLAM2;
using namespace std;


int main()
{
  ORBVocabulary voc("castle_ruins.yml.gz");
  voc.saveToTextFile("castle_ruins.txt");
  return 0;
}



