# ORB_SLAM_vocab-build

This repository can be used to create custom bag of words vocabulary which can be directly used for ORB SLAM/ORB SLAM2.
It consists of 2 major sub-folders:  

1.DBoW2 (Forked from [dorian3d/DBoW2](https://github.com/dorian3d/DBoW2))  
2.ORB_SLAM_txt (modified and used from [ORB_SLAM2](https://github.com/raulmur/ORB_SLAM2))

Here is the step by step procedure to build your own bag of words vocabulary and save it as .txt file format (which is required for ORB_SLAM):

## 1. Prerequisites
We have tested the library in **Ubuntu 12.04**, **14.04**, **16.04** & **18.04**, but it should be easy to compile in other platforms.
### C++11 or C++0x Compiler
We use the new thread and chrono functionalities of C++11.
### OpenCV
We use [OpenCV](http://opencv.org) to manipulate images and features. Dowload and install instructions can be found at: http://opencv.org. **Required at leat 2.4.3. Tested with OpenCV 2.4.11 and OpenCV 3.2**.


## 2. Installation
